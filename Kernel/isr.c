#include "../Include/isr.h"
#include "../Include/screen.h"
#include "../Include/io.h"
#include <stdint.h>

isr_t interruptHandlers[256];

void isrHandler(registers_t *regs){
	if (interruptHandlers[regs->intNo]!=0){
		isr_t handler=interruptHandlers[regs->intNo];
		handler(regs);
	}

}
void irqHandler(registers_t *regs){
	if (interruptHandlers[regs->intNo]!=0)
	{
		isr_t handler=interruptHandlers[regs->intNo];
		handler(regs);
	}
	// pic won't send any other interrupt request if we don't reset.
	if (regs->intNo>=40)
	{
		portByteOut(0xA0,0x20); // send end of interrupt signal to slave.
	} 
	portByteOut(0x20,0x20); // Send end of interrupt signal to master.

}
void registerInterruptHandler(uint8_t n,isr_t handler){
	interruptHandlers[n]=handler;
}
