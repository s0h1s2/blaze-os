#include "../Include/io.h"
#include <stdint.h>

unsigned char portByteIn(unsigned char port) {
    unsigned char result;
    __asm__("in %%dx, %%al" : "=a" (result) : "d" (port));
    return result;
}

void portByteOut(unsigned char port, unsigned char data) {
    __asm__("out %%al, %%dx" : : "a" (data), "d" (port));
}
unsigned short portWordIn(uint16_t port) {
    unsigned short result;
    __asm__("in %%dx, %%al" : "=a" (result) : "d" (port));
    return result;
}

void portWordOut(uint16_t port, uint16_t data) {
    __asm__("out %%al, %%dx" : : "a" (data), "d" (port));
}
