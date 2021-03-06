# Automatically generate lists of sources using wildcards
C_SOURCES = $(wildcard Kernel/*.c Drivers/*.c)
HEADERS = $(wildcard Include/*.h)
KERNEL_ENTRY=kernel_entry.o
BUILD_DIR=Build
# Convert the *.c filenames to *.o to give a list of object files to build
OBJ = $(C_SOURCES:.c=.o)
ISR=isr.o

all: os-image
run: os-image
	qemu-system-x86_64 -serial file:serial.log -fda $(BUILD_DIR)/os.bin
os-image: boot_sect.bin kernel.bin
	cat $^ > os.bin
	mkdir -p $(BUILD_DIR)
	mv *.o *.bin $(BUILD_DIR) 
boot_sect.bin:
	nasm -i Boot/ -f bin Boot/boot_sect.asm -o $@
kernel.bin: $(KERNEL_ENTRY) $(ISR) $(OBJ)
	i686-elf-ld -o kernel.bin -Ttext 0x1000 $^ --oformat binary
%.o: %.c ${HEADERS}
	i686-elf-gcc -g -ffreestanding -Wall -nostdlib -c $< -o $@
$(KERNEL_ENTRY): Boot/kernel_entry.asm
	nasm -f elf $< -o $@
$(ISR): Boot/isr.asm
	nasm -f elf $< -o $@


clean:	
	rm -rf *.bin *.o
	rm -rf Kernel/*.o
	rm -rf Drivers/*.o
	
