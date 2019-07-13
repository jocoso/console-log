// arraylist.c

#include <stdio.h>
#include <stdlib.h>
#include "arraylist.h"

void list_init(ArrayList *array_list) {
	// Initialize size and capacity
	array_list->size = 0;
	array_list->capacity = LIST_INITIAL_CAPACITY;
	
	// allocate memory
	array_list->data = malloc(sizeof(void*) * array_list->capacity);
}

void list_append(ArrayList * array_list, void* value) {
	// Making sure there's room to expand
	list_double_capacity_if_full(array_list);
	
	// append the value and increment the size
	array_list->data[array_list->size++] = value;
}

int list_get_int(ArrayList *array_list, int index) {
	if(index >= array_list->size || index < 0) {
		printf("Index %d out of bounds for list of size %d\n", index, array_list->size);
		exit(1);
	}
	
	return *((int *) (array_list->data[index]));
}

double list_get_double(ArrayList *array_list, int index) {
	if(index >= array_list->size || index < 0) {
		printf("Index %d out of bounds for list of size %d\n", index, array_list->size);
		exit(1);
	}
	
	return *((double *)(array_list->data[index]));
}
char* list_get_string(ArrayList *array_list, int index) {
	if(index >= array_list->size || index < 0) {
		printf("Index %d out of bounds for list of size %d\n", index, array_list->size);
		exit(1);
	}
	
	return *((char **)(array_list->data[index]));
}
char list_get_char(ArrayList *array_list, int index) {
	if(index >= array_list->size || index < 0) {
		printf("Index %d out of bounds for list of size %d\n", index, array_list->size);
		exit(1);
	}
	
	return *((char *)(array_list->data[index]));
}

void *list_get_raw(ArrayList *array_list, int index) {
	if(index >= array_list->size || index < 0) {
		printf("Index %d out of bounds for list of size %d\n", index, array_list->size);
		exit(1);
	}
	
	return array_list->data[index];
}

void list_set(ArrayList *array_list, int index, void *value) {
	// zero fill the list up to the desired index
	while (index >= array_list->size) {
		list_append(array_list, 0);
	}
	
	// set value at desired index
	array_list->data[index] = value;
}

void list_double_capacity_if_full(ArrayList *array_list) {
	if(array_list->size >= array_list->capacity) {
		// double capacity and resize the allocated memory accordingly
		array_list->capacity *= 2;
		array_list->data = realloc(array_list->data, sizeof(void*) * array_list->capacity);
	}
}

void list_free(ArrayList *array_list) {
	free(array_list->data);
}












