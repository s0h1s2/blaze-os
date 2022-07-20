#include "../Include/keyboard.h"
#include "../Include/isr.h"


#define IRQ1 33
void scanCode();
void initKeyboard(){
	registerInterruptHandler(IRQ1, scanCode);

}

void scanCode(registers_t *regs){
	uint8_t scancode=portByteIn(0x60);
	switch (scancode) {
		case 0x82:
			print("1");
			break;
		case 0x83:
			print("2");
			break;
		case 0x84:
			print("3");
			break;
		case 0x2C:
			print("Z");
			break;

		default:
			// printf("Unknown key.%i\n",scancode);
			if (scancode==156) {
				print("\n");
			}
			break;

	}
}