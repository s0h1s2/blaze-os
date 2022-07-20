#include "../Include/screen.h"
#include "../Include/io.h"
#include "../Include/idt.h"
#include "../Include/isr.h"
#include "../Include/keyboard.h"

void main(){

    vgaInit(); // set offset to 0,0 position;
    clearScreen();
    initIDT();
    asm volatile("sti");
    initKeyboard();
    
    // printf("Install keyboard.");

}

