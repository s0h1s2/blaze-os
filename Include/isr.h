#include <stdint.h>
typedef struct {
	uint32_t ds;
	uint32_t edi, esi, ebp, esp, ebx, edx, ecx, eax;
	uint32_t intNo,errorCode;
	uint32_t eip,eflags,useresp,ss;
	
} registers_t;