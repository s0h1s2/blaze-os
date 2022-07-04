#define VIDEO_ADDRESS 0xb8000
#define MAX_COLS 25
#define MAX_ROWS 80

#define WHITE_ON_BLACK 0x0f

#define REG_SCREEN_CTRL 0x3D4 // cursor position.
#define REG_SCREEN_DATA 0x3D5 // data register.


void print(char *message);
void printf(char *format,...); // TODO: port printf like standard library of unix.
void clearScreen();
