#define LIST_INITIAL_CAPACITY 100


typedef struct Array_List {
	int size;		// How many spaces used
	int capacity;	// How many available
	void **data;		// Array
} Array_List;

Array_List *new_list();
void list_append(Array_List * array_list, void *value);
int list_get_int(Array_List *array_list, int index);
double list_get_double(Array_List *array_list, int index);
char *list_get_string(Array_List *array_list, int index);
char   list_get_char(Array_List *array_list, int index);
void  *list_get_raw(Array_List *array_list, int index);
void list_set(Array_List *array_list, int index, void *value);
void list_double_capacity_if_full(Array_List *array_list);
void list_free(Array_List *array_list);