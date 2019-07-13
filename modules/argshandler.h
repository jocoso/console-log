#include "tools/arraylist.h"

typedef struct {
	ArrayList argument_list;
} ArgumentHandler;

typedef struct Arg{
	char *arg_name;
	char *arg_help;
} Arg;

void arghandler_add(ArgumentHandler *argument_handler, char* argument, char* helper);
void arghandler_init(ArgumentHandler *argument_handler);
void arghandler_free(ArgumentHandler *argument_handler);
void arg_init(Arg *arg);
Arg to_arg(void *arg);