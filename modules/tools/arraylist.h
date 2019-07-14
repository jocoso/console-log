#define LIST_INITIAL_CAPACITY 100


/* These macros were created to help easy up some
processes of the program and not as features */
#define TRANSFORM_PTR(value, datatype) ((datatype) value)
#define TRANSFORM(value, datatype) *((datatype*) &value)

// FLAGS
#define INT 0x0
#define STRING 0x1
#define CHAR 0x2
#define DOUBLE 0x3
#define FLOAT 0x4

//TODO: Place this on another library
#define TRUE 1
#define FALSE 0

#ifndef NULL
	#define NULL 0
#endif


typedef struct Array_List {
	int size;		// How many spaces used
	int capacity;	// How many available
	void **data;
} Array_List;

typedef int Boolean;




/* 	Returns an initialized Array_List that can be
	inmediately used.
	
	Returns:
			Array_List             : initialized Array_List
	Example:
			Array_List *a = new_list(); 
*/
Array_List *new_list();




/* 	Search on the given array list a given value
	return 1 (TRUE) if it exists or 0 (FALSE) if 
	it doesn't
	
	the arraylist should be filled with items of 
	the same datatype to avoid type side effects.

	Arguments:
			Array_List* list 	   : list affected
			void* 		value      : the value in the function 
			int 		flag	   : flag of datatype 
	Returns:
			int                    : TRUE (1), FALSE(0)
	Example:
			list_name->[20, 30, 50, 200]
			Boolean a = list_search(list_name, 20, INT);  // TRUE 
			Boolean b = list_search(list_name, 500, INT);  //  FALSE
*/
Boolean list_search(Array_List *array_list, void* value, int flag);



/* 	Adds an item in the array. Doubles the capacity
	of said array if it's full.

	Arguments:
			Array_List* list 	   : list affected
			void* 		value      : the value to put in the list
	Example:
			list_name->[20, 30, 50, 200]
			list_append(list_name, 50);
			list_name->[20, 30, 50, 200, 50]
*/
void list_append(Array_List * array_list, void* value);


// TODO: Eliminate the need for these merge them into one convinient function
int list_get_int(Array_List *array_list, int index);
double list_get_double(Array_List *array_list, int index);
char *list_get_string(Array_List *array_list, int index);
char   list_get_char(Array_List *array_list, int index);
void  *list_get_raw(Array_List *array_list, int index);



/* 	Replace a value at a particular index in the
	array. If the index is beyond the total size
	the function will put 0's on the remining 
	spaces.

	Arguments:
			Array_List* list 	   : list affected
			int 		index      : index item to be replaced 
			void* 		value	   : value to put on the array index 
	Example:
			list_name->[20, 30, 50, 200]
			list_set(list_name, 2, 90);
			list_name->[20, 30, 90, 200]

			list_set(list_name, 6, 25);
			list_name->[20, 30, 90, 200, 0, 0, 6]
*/
void list_set(Array_List *array_list, int index, void *value);



/* 	Check if the size of the array is bigger than
	its capacity. If it is it doubles its size

	Arguments:
			Array_List* list 	   : list affected
	Example:
			[internal use]
*/
void list_double_capacity_if_full(Array_List *array_list);




/* 	Free the memory used by the list.

	Arguments:
			Array_List* list 	   : list affected
	Example:
			list_name->[20, 30, 50, 200]
			list_free(list_name);
			list_name->NULL
*/
void list_free(Array_List *array_list);