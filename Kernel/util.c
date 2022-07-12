#include <stdint.h>
void memset(uint8_t *dest,const uint8_t val,uint32_t len){
	uint8_t *temp=(uint8_t *)dest;
	while (len!=0) {
		*temp++=val;
		len--;
	}
}

// char *parseInt(int val){
// 	return ()

// }

