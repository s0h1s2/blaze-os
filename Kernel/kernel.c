#include "../Include/screen.h"
#include "../Include/io.h"
#include "../Include/idt.h"

void main(){
    initIDT();        
    clearScreen();
    vgaInit(); // set offset to 0,0 position;
    printf("%i",1/0);

}

