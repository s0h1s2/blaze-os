#include "../Include/screen.h"
#include "../Include/io.h"
#include <stdint.h>

short *address=(short*)VIDEO_ADDRESS;

typedef unsigned char byte;

uint16_t getCursor();	
void setCursor(uint16_t offset);
uint16_t getRowFromOffset(uint16_t offset);
uint16_t getOffset(unsigned char x,unsigned char y);
uint16_t moveOffsetToNewline(uint16_t offset);
void setCharAtAddress(char character,int offset);

void vgaInit(){
	setCursor(getOffset(0, 0));
}

void print(char *message){
	short *addr=(short *)VIDEO_ADDRESS;
	uint16_t cursorPos=getCursor();

	while (*message) {

		if ('\n'==(char)*message)
		{
			setCursor(moveOffsetToNewline(cursorPos));
			cursorPos=getCursor();

		}
		if (*message>=0x20)
		{
			*(addr+cursorPos)=0x0f<<8|*message;
		}

		message++;//move pointer to next charatcer;
		cursorPos++;
	}
	
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


// // TODO: danger code what if the buffer is full.
// short printInt(short message){
// 	byte allocSize=32;

// 	byte buffer[allocSize];
// 	byte index=0;
// 	while(message>0){
// 		char c=(message%10)+'0';
// 		message=message/10;
// 		buffer[index]=c;
// 		index++;

// 	}
// 	// Reverse the values to get correct ones.
// 	byte result[index];

// 	for (byte i = 1; i<=index; i++)
// 	{
// 		*(result+(i-1))=*((byte *)(&buffer)+(index-i));

// 	}	

// }
