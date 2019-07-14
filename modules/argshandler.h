#include "tools/arraylist.h"

typedef struct {
	Array_List arg_list;
} Argument_Handler;

typedef struct Arg{
	char *arg_name;
	char *arg_help;
} Arg;

void arghandler_add(Argument_Handler *argument_handler, char* argument, char* helper);
void arghandler_init(Argument_Handler *argument_handler);
void arghandler_free(Argument_Handler *argument_handler);
void arg_init(Arg *arg);
Arg to_arg(void *arg);