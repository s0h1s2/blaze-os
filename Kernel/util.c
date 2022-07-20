#include <stdint.h>
#include <stddef.h>

#include "../Include/util.h"

void memset(void *dest,const uint8_t val,uint32_t len){
	uint8_t *temp=(uint8_t *)dest;
	while (len!=0) {
		*temp++=val;
		len--;
	}
}

void* memcopy(void *dest,const void *source, size_t nbytes){
	char *sChar=source;
	char *dChar=dest;
	for (size_t i=0;i<nbytes; i++) {
		dChar[i]=sChar[i];
	}
	return dChar;
	
}