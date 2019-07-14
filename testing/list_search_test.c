#include <stdio.h>
#include "modules/tools/arraylist.h"

#define DEBUG_PRI(label, arg1, arg2) ((arg1 == arg2)? printf("%s DEBUG: TRUE\n", label) : printf("%s DEBUG: FALSE\n", label))

void debug_int(Array_List * arg) {
	printf("Starting list_int debugging\n");
	list_append(arg, 2);
	list_append(arg, 3);
	list_append(arg, 7);
	list_append(arg, 14);

	Boolean a = list_search(arg, 2, INT);
	Boolean b = list_search(arg, 3, INT);
	Boolean c = list_search(arg, 7, INT);
	Boolean d = list_search(arg, 14, INT);
	Boolean e = list_search(arg, 25, INT);
	Boolean f = list_search(arg, 200, INT);

	Boolean g = list_search_index(arg, 2, INT);
	Boolean h = list_search_index(arg, 3, INT);
	Boolean i = list_search_index(arg, 7, INT);
	Boolean j = list_search_index(arg, 14, INT);
	Boolean k = list_search_index(arg, 25, INT);
	Boolean l = list_search_index(arg, 200, INT);

	DEBUG_PRI("a", a, 1);
	DEBUG_PRI("b", b, 1);
	DEBUG_PRI("c", c, 1);
	DEBUG_PRI("d", d, 1);
	DEBUG_PRI("e", e, 0);
	DEBUG_PRI("f", f, 0);

	DEBUG_PRI("g", g, 0);
	DEBUG_PRI("h", h, 1);
	DEBUG_PRI("i", i, 2);
	DEBUG_PRI("j", j, 3);
	DEBUG_PRI("k", k, NULL);
	DEBUG_PRI("l", l, NULL);
	printf("list_int debugging finished\n");
}

void debug_string(Array_List * arg) {
	printf("Starting list_string debugging\n");
	list_append(arg, "joshua");
	list_append(arg, "joey");
	list_append(arg, "yanira");
	list_append(arg, "eileen");

	Boolean a = list_search(arg, "joshua", STRING);
	Boolean b = list_search(arg, "joey", STRING);
	Boolean c = list_search(arg, "yanira", STRING);
	Boolean d = list_search(arg, "eileen", STRING);
	Boolean e = list_search(arg, "tamana", STRING);
	Boolean f = list_search(arg, "jamie", STRING);

	Boolean g = list_search_index(arg, "joshua", STRING);
	Boolean h = list_search_index(arg, "joey", STRING);
	Boolean i = list_search_index(arg, "yanira", STRING);
	Boolean j = list_search_index(arg, "eileen", STRING);
	Boolean k = list_search_index(arg, "tamana", STRING);
	Boolean l = list_search_index(arg, "jamie", STRING);


	 DEBUG_PRI("a", a, 1);
	 DEBUG_PRI("b", b, 1);
	 DEBUG_PRI("c", c, 1);
	 DEBUG_PRI("d", d, 1);
	 DEBUG_PRI("e", e, 0);
	 DEBUG_PRI("f", f, 0);

	DEBUG_PRI("g", g, 0);
	DEBUG_PRI("h", h, 1);
	DEBUG_PRI("i", i, 2);
	DEBUG_PRI("j", j, 3);
	DEBUG_PRI("k", k, NULL);
	DEBUG_PRI("l", l, NULL);
	printf("list_string debugging finished\n");
}

void debug_char(Array_List * arg) {
	printf("Starting list_char debugging\n");
	list_append(arg, 'a');
	list_append(arg, 'b');
	list_append(arg, 'c');
	list_append(arg, 'd');

	Boolean a = list_search(arg, 'a', CHAR);
	Boolean b = list_search(arg, 'b', CHAR);
	Boolean c = list_search(arg, 'c', CHAR);
	Boolean d = list_search(arg, 'd', CHAR);
	Boolean e = list_search(arg, 'e', CHAR);
	Boolean f = list_search(arg, 'f', CHAR);

	Boolean g = list_search_index(arg, 'a', CHAR);
	Boolean h = list_search_index(arg, 'b', CHAR);
	Boolean i = list_search_index(arg, 'c', CHAR);
	Boolean j = list_search_index(arg, 'd', CHAR);
	Boolean k = list_search_index(arg, 'e', CHAR);
	Boolean l = list_search_index(arg, 'f', CHAR);

	DEBUG_PRI("a", a, 1);
	DEBUG_PRI("b", b, 1);
	DEBUG_PRI("c", c, 1);
	DEBUG_PRI("d", d, 1);
	DEBUG_PRI("e", e, 0);
	DEBUG_PRI("f", f, 0);

	DEBUG_PRI("g", g, 0);
	DEBUG_PRI("h", h, 1);
	DEBUG_PRI("i", i, 2);
	DEBUG_PRI("j", j, 3);
	DEBUG_PRI("k", k, NULL);
	DEBUG_PRI("l", l, NULL);
	printf("list_char debugging finished\n");
}

void debug_boolean(Array_List * arg) {
	printf("Starting list_bool debugging\n");
	list_append(arg, TRUE);
	list_append(arg, FALSE);

	Boolean a = list_search(arg, TRUE, BOOLEAN);
	Boolean b = list_search(arg, FALSE, BOOLEAN);

	Boolean c = list_search_index(arg, TRUE, BOOLEAN);
	Boolean d = list_search_index(arg, FALSE, BOOLEAN);

	DEBUG_PRI("a", a, 1);
	DEBUG_PRI("b", b, 1);

	DEBUG_PRI("c", c, 0);
	DEBUG_PRI("d", d, 1);
	
	printf("list_bool debugging finished\n");
}


int main(int argc, char** argv) {
	Array_List *list_int = new_list();
	Array_List *list_string = new_list();
	Array_List *list_char = new_list();
	Array_List *list_boolean = new_list();

	// debug_int(list_int);
	// debug_string(list_string);
	// debug_char(list_char);
	 debug_boolean(list_boolean);

	list_free(list_int);
	list_free(list_string);
	list_free(list_char);
	list_free(list_boolean);
}