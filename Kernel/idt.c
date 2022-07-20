#include <stdint.h>
#include "../Include/idt.h"
#include "../Include/util.h"
#include "../Include/io.h"


extern void idtFlush(uint32_t);
void initIDT();
static void IDTSetGate(uint8_t,uint32_t,uint16_t,uint8_t);

IDT_Entry IDT_Entries[256];
IDT_Ptr IDT_P;
void initIDT(){
	IDT_P.limit=sizeof(IDT_Entry)*256-1;
	IDT_P.base=(uint32_t)&IDT_Entries;
	memset(&IDT_Entries, 0, sizeof(IDT_Entry));
	IDTSetGate(0,(uint32_t)isr0,0x08,0x8E);
	IDTSetGate(1,(uint32_t)isr1,0x08,0x8E);
	IDTSetGate(2,(uint32_t)isr2,0x08,0x8E);
	IDTSetGate(3,(uint32_t)isr3,0x08,0x8E);
	IDTSetGate(4,(uint32_t)isr4,0x08,0x8E);
	IDTSetGate(5,(uint32_t)isr5,0x08,0x8E);
	IDTSetGate(6,(uint32_t)isr6,0x08,0x8E);
	IDTSetGate(7,(uint32_t)isr7,0x08,0x8E);
	IDTSetGate(8,(uint32_t)isr8,0x08,0x8E);
	IDTSetGate(9,(uint32_t)isr9,0x08,0x8E);
	IDTSetGate(10,(uint32_t)isr10,0x08,0x8E);
	IDTSetGate(11,(uint32_t)isr11,0x08,0x8E);
	IDTSetGate(12,(uint32_t)isr12,0x08,0x8E);
	IDTSetGate(13,(uint32_t)isr13,0x08,0x8E);
	IDTSetGate(14,(uint32_t)isr14,0x08,0x8E);
	IDTSetGate(15,(uint32_t)isr15,0x08,0x8E);
	IDTSetGate(16,(uint32_t)isr16,0x08,0x8E);
	IDTSetGate(17,(uint32_t)isr17,0x08,0x8E);
	IDTSetGate(18,(uint32_t)isr18,0x08,0x8E);
	IDTSetGate(19,(uint32_t)isr19,0x08,0x8E);
	IDTSetGate(20,(uint32_t)isr20,0x08,0x8E);
	IDTSetGate(21,(uint32_t)isr21,0x08,0x8E);
	IDTSetGate(22,(uint32_t)isr22,0x08,0x8E);
	IDTSetGate(23,(uint32_t)isr23,0x08,0x8E);
	IDTSetGate(24,(uint32_t)isr24,0x08,0x8E);
	IDTSetGate(25,(uint32_t)isr25,0x08,0x8E);
	IDTSetGate(26,(uint32_t)isr26,0x08,0x8E);
	IDTSetGate(27,(uint32_t)isr27,0x08,0x8E);
	IDTSetGate(28,(uint32_t)isr28,0x08,0x8E);
	IDTSetGate(29,(uint32_t)isr29,0x08,0x8E);
	IDTSetGate(30,(uint32_t)isr30,0x08,0x8E);
	IDTSetGate(31,(uint32_t)isr31,0x08,0x8E);
	  // Remap interrupt request controller.
	 // ICW1
	 portByteOut(0x20, 0x11);
	 portByteOut(0xA0, 0x11);
	 // ICW2
	 portByteOut(0x21, 0x20);
	 portByteOut(0xA1, 0x28);
	 // ICW3
	 portByteOut(0x21, 0x04);
	 portByteOut(0xA1, 0x02);
	 // ICW4
	 portByteOut(0x21, 0x01);
	 portByteOut(0xA1, 0x01);
	 
	 // OCW1
	 portByteOut(0x21, 0x0);
	 portByteOut(0xA1, 0x0);
	
	IDTSetGate(32,(uint32_t)irq0,0x08,0x8E);
	IDTSetGate(33,(uint32_t)irq1,0x08,0x8E);
	IDTSetGate(34,(uint32_t)irq2,0x08,0x8E);
	IDTSetGate(35,(uint32_t)irq3,0x08,0x8E);
	IDTSetGate(36,(uint32_t)irq4,0x08,0x8E);
	IDTSetGate(37,(uint32_t)irq5,0x08,0x8E);
	IDTSetGate(38,(uint32_t)irq6,0x08,0x8E);
	IDTSetGate(39,(uint32_t)irq7,0x08,0x8E);
	IDTSetGate(40,(uint32_t)irq8,0x08,0x8E);
	IDTSetGate(41,(uint32_t)irq9,0x08,0x8E);
	IDTSetGate(42,(uint32_t)irq10,0x08,0x8E);
	IDTSetGate(43,(uint32_t)irq11,0x08,0x8E);
	IDTSetGate(44,(uint32_t)irq12,0x08,0x8E);
	IDTSetGate(45,(uint32_t)irq13,0x08,0x8E);
	IDTSetGate(46,(uint32_t)irq14,0x08,0x8E);
	IDTSetGate(47,(uint32_t)irq15,0x08,0x8E);
	
	idtFlush((uint32_t)&IDT_P);

}
static void IDTSetGate(uint8_t num,uint32_t base,uint16_t sel,uint8_t flags){

	IDT_Entries[num].baseLo=base&0xFFFF;
	IDT_Entries[num].baseHi=(base>>16)&0xFFFF;
	IDT_Entries[num].always0=0;
	IDT_Entries[num].sel=sel;
	IDT_Entries[num].flags=flags;
}