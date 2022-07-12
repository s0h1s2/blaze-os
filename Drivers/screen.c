#include "../Include/screen.h"
#include "../Include/io.h"
#include <stdint.h>
#include <stdarg.h>
#include <stdbool.h>

uint16_t getCursor();	
void setCursor(uint16_t offset);
uint16_t getRowFromOffset(uint16_t offset);
uint16_t getOffset(unsigned char x,unsigned char y);
uint16_t moveOffsetToNewline(uint16_t offset);
void setCharAtAddress(char character,int offset);

void vgaInit(){
	setCursor(getOffset(0, 0));
}
void printf(char *format, ...){
	char buffer[512]; // TODO: Dynamic allocation when memory part finished.

	signed short index=0;
	va_list argList;
	va_start(argList,format);

	while (*format) {
		// char *next=*(&format+1);
		if (*format=='%' && *(format+1)=='i')
		{
			char tempBuffer[32];
			unsigned char i=0;
			bool isSigned=false;
			int val=va_arg(argList,int);			
				
			if (val<0)
			{
				val=val*-1;
				isSigned=true;


			}

			while (val!=0) {
				*(tempBuffer+i)=val%10+'0';
				val=val/10;
				i++;
			}
			if (isSigned)
			{
				*(buffer+index)='-';
				index++;

			}
			for (signed short j = i-1; j >=0; j--)
			{

				*(buffer+index)=*(tempBuffer+(j));
				index++;

			}
			format+=2;
			continue;

		}
		*(buffer+index)=*format;
		
		index++;

		format++;

	}
	va_end(argList);
	print(buffer);
	memset(&buffer, 0, 512); 

		

}
void print(char *message){
	short *addr=(short *)VIDEO_ADDRESS;
	uint16_t cursorPos=getCursor();

	while (*message) {

		if ('\n'==(char)*message)
		{
			setCursor(moveOffsetToNewline(cursorPos));
			cursorPos=getCursor();

		}else{
			if (*message>=0x20)
			{
				*(addr+cursorPos)=0x0f<<8|*message;
			}
			cursorPos++;

		}
		message++;//move pointer to next charatcer;


	}
	*(addr+cursorPos)=0x0f00;
	setCursor(cursorPos);

}

void clearScreen(){
	short *addr=(short*)VIDEO_ADDRESS;
	for (short i = 0; i < MAX_COLS*MAX_ROWS; ++i)
	{
		addr[i]=0x0000;
	}	
}


uint16_t getCursor(void){
	uint16_t pos=0;
    portByteOut(VGA_REG_SCREEN_CTRL, VGA_OFFSET_LOW);
    pos|=portByteIn(VGA_REG_SCREEN_DATA);
    portByteOut(VGA_REG_SCREEN_CTRL, VGA_OFFSET_HIGH);
    pos|=(uint16_t)portByteIn(VGA_REG_SCREEN_DATA) <<8 ;
    return pos;


}
void setCursor(uint16_t offset){
	portByteOut(VGA_REG_SCREEN_CTRL, VGA_OFFSET_LOW);
	portByteOut(VGA_REG_SCREEN_DATA, (offset &0xFF));
	portByteOut(VGA_REG_SCREEN_CTRL, VGA_OFFSET_HIGH);
	portByteOut(VGA_REG_SCREEN_DATA, (offset>>8) & 0xFF);
}

uint16_t getRowFromOffset(uint16_t offset){
	return offset/(MAX_COLS);

}
uint16_t getOffset(unsigned char x,unsigned char y){
	uint16_t offset=y*MAX_COLS+x;
	return offset;

}
uint16_t moveOffsetToNewline(uint16_t offset){
	return getOffset(0, getRowFromOffset(offset)+1);
}
void setCharAtAddress(char character,int offset){
	int *addr=(int*)VIDEO_ADDRESS;
	addr[offset]=character;
	addr[offset+1]=0x0f;
}