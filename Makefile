# Automatically generate lists of sources using wildcards
C_SOURCES = $(wildcard Kernel/*.c)
KENREL_DIR:=KERNEL/
HEADERS = $(wildcard Include/*.h)
KERNEL_ENTRY=kernel_entry.o
# Convert the *.c filenames to *.o to give a list of object files to build
OBJ = $(C_SOURCES:.c=.o)
all: os-image boot_sect.bin kernel.bin
os-image: boot_sect.bin kernel.bin
	cat $^ > os.bin
boot_sect.bin:
	nasm -i Boot/ -f bin Boot/boot_sect.asm -o $@
kernel.bin: $(KERNEL_ENTRY) kernel.o
	i686-elf-ld -o kernel.bin -Ttext 0x1000 $^ --oformat binary
kernel.o: Kernel/kernel.c
	i686-elf-gcc -ffreestanding -c $< -o $@
$(KERNEL_ENTRY): Boot/kernel_entry.asm
	nasm -f elf $< -o $@


clean:	
	rm -rf *.bin *.o
	rm -rf Kernel/*.o
