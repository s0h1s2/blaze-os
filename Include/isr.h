#include <stdint.h>
typedef struct {
	uint32_t ds;
	uint32_t edi, esi, ebp, esp, ebx, edx, ecx, eax;
	uint32_t intNo,errorCode;
	uint32_t eip,eflags,useresp,ss;
	
} registers_t;

typedef void (*isr_t)(registers_t *reg);

void registerInterruptHandler(uint8_t n,isr_t handler);
