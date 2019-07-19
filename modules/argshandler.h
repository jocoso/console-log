#include "tools/hashmap.h"

typedef struct Argument_Handler{
	Hash_Table *arg_list;
} Argument_Handler;

typedef struct Arg{
	char *arg_name;
	char *arg_help;
} Arg;

Argument_Handler *new_arg_handler();
void arghandler_add(Argument_Handler *argument_handler, char* argument, char* helper);
int arghandler_verify(Argument_Handler *argument_handler, char* arg);
Arg *to_arg(void *arg);
void arghandler_free(Argument_Handler *argument_handler);