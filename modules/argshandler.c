/* argshandler.c */
#define NULL 0
/* Implements this interface: */
#include "argshandler.h"
#include "tools\utilities.h"

Argument_Handler *new_arg_handler() {
	Argument_Handler *arg_handler;
	arg_handler = malloc(sizeof(Argument_Handler *));
	arg_handler->arg_list = new_hash();
	return arg_handler;
}

void arghandler_add(Argument_Handler *argument_handler, char* argument, char* helper) {
	Arg *arg = {&argument, &helper};
	hash_insert(argument_handler->arg_list, argument, arg);
}

int arghandler_verify(Argument_Handler *argument_handler, char* arg) {

	Hash_Table *list = argument_handler->arg_list;
	void* a = hash_search(argument_handler->arg_list, arg);
	struct Arg rose = *((struct Arg*) a);

	printf("%s\n", rose.arg_name);

	if(hash_search(list, arg) == NULL)
		return 0;
	return 1;
}


Arg *to_arg(void *arg) {
	return (Arg*) arg;
}

void arghandler_free(Argument_Handler *argument_handler) {
	hash_free(argument_handler->arg_list);
	free(argument_handler);
}


