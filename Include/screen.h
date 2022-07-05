#include <stdint.h>
#ifndef SCREEN_H_INCLUDED
#define SCREEN_H_INCLUDED

#ifndef SCREEN_H
#define SCREEN_H
#define VIDEO_ADDRESS 0xb8000
#define MAX_COLS 25
#define MAX_ROWS 80

#define WHITE_ON_BLACK 0x0f

#define VGA_REG_SCREEN_CTRL 0x3D4 // cursor position.
#define VGA_REG_SCREEN_DATA 0x3D5 // data register.

#define VGA_OFFSET_LOW 0x0f // cursor position.
#define VGA_OFFSET_HIGH  0x0e// data register.

#endif

void print(char *message);
void printInt(int message);

//void printf(char *format,...); // TODO: port printf like standard library of unix.
void clearScreen();
int getCursor();

#endif // SCREEN_H_INCLUDED
