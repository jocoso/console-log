#define LEN(array) (sizeof(array)/sizeof(array[0]))
#define EQUALS(a, b) (a == b)
#define PRINT(value, ...) printf((value), ##__VA_ARGS__)
#define TRUE 1
#define FALSE 0

long pow(long base, long exponent);