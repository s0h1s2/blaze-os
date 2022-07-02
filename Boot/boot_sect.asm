[org 0x7c00]
KERNEL_OFFSET equ 0x1000

mov [BOOT_DRIVE], dl	; BIOS stores our boot drive in DL , so it 's
			; best to remember this for later.

mov bp, 0x9000
mov sp, bp

mov bx, MSG_REAL_MODE
call print_string

call load_kernel

call switch_to_pm
jmp $

%include "print_string.asm"
%include "disk_load.asm"
%include "print_string_pm.asm"
%include "gdt.asm"
%include "switch_to_pm.asm"

[bits 16]
load_kernel: ; load kernel from boot sectors 
	mov bx, MSG_LOAD_KERNEL
	call print_string
	mov bx, KERNEL_OFFSET
	mov dh, 30 ; boot sectors to read. 
	mov dl, [BOOT_DRIVE] ; boot drive to read
	
	call disk_load
	
	ret

[bits 32]
BEGIN_PM:
	;mov ebx, MSG_PROT_MODE
	;call print_string_pm
	call KERNEL_OFFSET
	jmp $

BOOT_DRIVE:
	db 0

MSG_REAL_MODE:
	db "Started in 16- bit Real Mode ",10,13,0

MSG_PROT_MODE:
	db "Successfully landed in 32- bit Protected Mode", 0

MSG_LOAD_KERNEL:
	db "Loading kernel into memory...",13,10,0

times 510-($-$$) db 0
dw 0xAA55
