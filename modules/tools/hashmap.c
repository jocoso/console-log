#include <string.h>
#include "hashmap.h"


const unsigned int hash_code(size, str) 
	// Arguments
	const unsigned int size;  // Size of hash
	const char* str;          // key

{
	unsigned int code = 0x11111111;
	
	for(int i = 0; i < strlen(str); i++) {
	 code ^= str[i];
	 code = (code >> 5) |  (code << 27);
	}

	return code%size;
}

