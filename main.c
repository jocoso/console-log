#include <stdio.h>
#include "modules/tools/arraylist.h"

int main(int argc, char** argv) {
	Array_List *list = new_list();
	
	list_append(list, 3);
	list_append(list, 5);

	//int a = void_to_int(TO_VOID(5));
	//printf("%p\n", a);

	// void* a = 5;
	// int b = *((int*) &a);
	// printf("%d\n", b);

	(list_search(list, 57, INT))? printf("TRUE\n") : printf("FALSE\n");
	list_free(list);
}