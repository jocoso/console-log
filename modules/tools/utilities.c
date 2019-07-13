#include "utilities.h"

long pow(long base, long exponent) {	
	int result = 1;
	for(;;) {
		if(exponent & 1) {
			result *= base;
		}
		
		exponent >>= 1;
		
		if (!exponent) {
			break;
		}
		
		base *= base;
	}
	return result;
}