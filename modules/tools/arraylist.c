// arraylist.c

#include <stdio.h>
#include <stdlib.h>
#include "arraylist.h"

Array_List *new_list() {
	// Initialize size and capacity
	struct Array_List *list;

	list = malloc(sizeof(Array_List*));
	list->size = 0;
	list->capacity = LIST_INITIAL_CAPACITY;
	
	// allocate memory
	list->data = malloc(sizeof(void*) * list->capacity);

	return list;
}

void list_append(Array_List *array_list, void* value) {
	// Making sure there's room to expand
	list_double_capacity_if_full(array_list);
	
	// append the value and increment the size
	array_list->data[array_list->size++] = value;
}

// -------Getters-START------- //

int list_get_int(Array_List *array_list, int index) {
	if(index >= array_list->size || index < 0) {
		printf("Index %d out of bounds for list of size %d\n", index, array_list->size);
		exit(1);
	}
	
	return *((int *) (array_list->data[index]));
}

double list_get_double(Array_List *array_list, int index) {
	if(index >= array_list->size || index < 0) {
		printf("Index %d out of bounds for list of size %d\n", index, array_list->size);
		exit(1);
	}
	
	return *((double *)(array_list->data[index]));
}
char* list_get_string(Array_List *array_list, int index) {
	if(index >= array_list->size || index < 0) {
		printf("Index %d out of bounds for list of size %d\n", index, array_list->size);
		exit(1);
	}
	
	return (char *) array_list->data[index];
}
char list_get_char(Array_List *array_list, int index) {
	if(index >= array_list->size || index < 0) {
		printf("Index %d out of bounds for list of size %d\n", index, array_list->size);
		exit(1);
	}
	
	return *((char *)(array_list->data[index]));
}

void *list_get_raw(Array_List *array_list, int index) {
	if(index >= array_list->size || index < 0) {
		printf("Index %d out of bounds for list of size %d\n", index, array_list->size);
		exit(1);
	}
	
	return array_list->data[index];
}

// -------Getters-END------- //





void list_set(Array_List *array_list, int index, void *value) {
	// zero fill the list up to the desired index
	while (index >= array_list->size) {
		list_append(array_list, 0);
	}
	
	// set value at desired index
	array_list->data[index] = value;
}

void list_double_capacity_if_full(Array_List *array_list) {
	if(array_list->size >= array_list->capacity) {
		// double capacity and resize the allocated memory accordingly
		array_list->capacity *= 2;
		array_list->data = realloc(array_list->data, sizeof(void*) * array_list->capacity);
	}
}

void list_free(Array_List *array_list) {
	free(array_list->data);
	free(array_list);
}












