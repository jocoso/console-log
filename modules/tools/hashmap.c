#include <string.h>
#include "../utilities/stddefs.h";
#include "hashmap.h"


Hash_Table *new_hash_table() {}

struct Hash_Node *new_hash_node(key, value) 
	char* key;
	void* value;
{return NULL;}

void hash_insert(table, key, value)
	Hash_Table *table; 
	char* key; 
	void* value;
{}

void *hash_get(table, key) 
	Hash_Table *table;
	char* key;
{return NULL;}

struct Hash_Node *get_hash_node(table, key) 
	Hash_Table *table; 
	char* key;
{return NULL;}

void hash_delete(table, key) 
	Hash_Table *table;
	char* key;
{}
	
const unsigned int hash_code(size, str)
	const unsigned int size; 
	const char* str;
{return -1;}

void hash_free(table) 
	Hash_Table *table;
{}

const unsigned int hash_code(size, str) 
	// Arguments
	const unsigned int size;  // Size of hash
	const char* str;          // key

{
	unsigned int code = 0x11111111;
	
	for(int i = 0; i < strlen(str); i++) {
	 code ^= str[i];
	 code = (code >> 5) |  (code << 27);
	}

	return code%size;
}