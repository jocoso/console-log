#define LIST_INITIAL_CAPACITY 100

typedef struct {
	int size;		// How many spaces used
	int capacity;	// How many available
	void **data;		// Array
} ArrayList;

void list_init(ArrayList *array_list);

void list_append(ArrayList * array_list, void *value);

int    list_get_int(ArrayList *array_list, int index);
double list_get_double(ArrayList *array_list, int index);
char*  list_get_string(ArrayList *array_list, int index);
char   list_get_char(ArrayList *array_list, int index);
void  *list_get_raw(ArrayList *array_list, int index);

void list_set(ArrayList *array_list, int index, void *value);

void list_double_capacity_if_full(ArrayList *array_list);

void list_free(ArrayList *array_list);