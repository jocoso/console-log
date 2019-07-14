/* argshandler.c */
#define NULL 0
/* Implements this interface: */
#include "argshandler.h"
#include "tools\utilities.h"

struct Argument_Handler *new_arg_handler() {
	struct Argument_Handler *arg_handler;
	//arg_handler->arg_list = *new_list();

	return arg_handler;
}


void arghandler_add(Argument_Handler *argument_handler, char* argument, char* helper) {
	Arg arg;
	arg_init(&arg);
	arg.arg_name = argument;
	arg.arg_help = helper;
	list_append(&(argument_handler->arg_list), &arg);
}

void arghandler_free(Argument_Handler *argument_handler) {
	list_free(&(argument_handler->arg_list));
}

void arg_init(Arg *arg) {
	arg->arg_name = NULL;
	arg->arg_help = NULL;
}


Arg to_arg(void *arg) {
	return *((Arg*) arg);
}

