/* argshandler.c */
#define NULL 0
/* Implements this interface: */
#include "argshandler.h"
#include "tools\utilities.h"

void arghandler_init(ArgumentHandler *argument_handler) {
	list_init(&(argument_handler->argument_list));
}


void arghandler_add(ArgumentHandler *argument_handler, char* argument, char* helper) {
	Arg arg;
	arg_init(&arg);
	arg.arg_name = argument;
	arg.arg_help = helper;
	list_append(&(argument_handler->argument_list), &arg);
}

void arghandler_free(ArgumentHandler *argument_handler) {
	list_free(&(argument_handler->argument_list));
}

void arg_init(Arg *arg) {
	arg->arg_name = NULL;
	arg->arg_help = NULL;
}


Arg to_arg(void *arg) {
	return *((Arg*) arg);
}

