#include "screen.h"

void print(char *message){
	short* address=(short*)VIDEO_ADDRESS;
	while(*message){
			*address=*message|0x0f00;
			address++; // move address by 2 byte.
			message++;
	}
	
}

void clearScreen()
{
		for(int i=0;i<MAX_ROWS*MAX_COLS;i++){
			short* address=(short*)VIDEO_ADDRESS;
			address[i]=0x0000;
			
		}
}