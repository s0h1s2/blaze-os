#include "../Include/isr.h"
#include "../Include/screen.h"

void isrHandler(registers_t regs){
	printf("Received intrrupet.\n");
	printf("%i\n",regs.intNo);

}