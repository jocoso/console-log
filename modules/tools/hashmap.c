#include <string.h>
#include <stdio.h>
#include <stdlib.h>

#include "hashmap.h"
#include "../utilities/debug.h"


Hash_Table *new_hash_table() {
	Hash_Table *out = (Hash_Table*) malloc(sizeof(Hash_Table));
	out->bucket = (struct Hash_Node**) calloc(INITIAL_HASH_SIZE, sizeof(struct Hash_Node*));
	out->size = 0;
	out->capacity = INITIAL_HASH_SIZE;
	return out;
}

struct Hash_Node *new_hash_node(key, value) 
	char* key;
	void* value;
{
	struct Hash_Node *out = (struct Hash_Node*) malloc(sizeof(struct Hash_Node));
	out->key = key;
	out->value = value;
	out->next = NULL;
	return out;
}

// FUNCT: Add functionality that if the key already exists it won't make it again
// Create a new function hash_contains that does it
void hash_insert(table, key, value)
	Hash_Table *table; 
	char* key; 
	void* value;
{
	check_if_filled(table);

	if(is_empty(table)) return;
	unsigned int index = hash_code(table->capacity, key);
	struct Hash_Node *node = new_hash_node(key, value);

	if(table->bucket[index] == NULL) {
		table->bucket[index] = node;
	} else {
	 	insert_hash_node_in_next_available_spot(table->bucket[index], node);
	}

	table->size++;

}


void *hash_get(table, key) 
	Hash_Table *table;
	char* key;
{
	if(is_empty(table)) return NULL;
	check_if_filled(table);


	unsigned int index = hash_code(table->capacity, key);
	// Comment this out
	struct Hash_Node *select_list = table->bucket[index];

	
	if(!is_empty(select_list)) {
		struct Hash_Node *node = get_hash_node_on_list(select_list, key); 
		return (!is_empty(node)) ? node->value : NULL;
	}

	return NULL;
}

struct Hash_Node *get_hash_node_on_list(head, key) 
	struct Hash_Node *head;
	const char* key;
{
	if(strcmp(head->key, key) != 0 && is_empty(head->next)) return NULL;

	if(strcmp(head->key, key) == 0) return head;  

	head = head->next;
	while(!is_empty(head)) {
		if(strcmp(head->key, key) != 0) 
			head = head->next;
		else
			return head;
	}

	return NULL;
}


void insert_hash_node_in_next_available_spot(head, node)
	struct Hash_Node *head;
	struct Hash_Node *node;
{
	while(head->next != NULL) {
		head = head->next;
	}	

	head->next = node;
}

void free_all_nodes_in_bucket(head)
	struct Hash_Node *head;
{
	if(is_empty(head)) return;

	if(is_empty(head->next)){ 
		free(head);
		head = NULL;
		return;
	}

	while(!is_empty(head)) {
	 	struct Hash_Node *next = head->next;
	 	free(head);
	 	head = &next; 
	}
	free(head);
}

// XXX: Not tested for collision

void hash_delete(table, key) 
	Hash_Table *table;
	const char* key;
{
	if(is_empty(table)) 
		return;

	const unsigned int index = hash_code(table->capacity, key);


	if(delete_hash_node_on_list(table->bucket[index], key)){
		table->size--;
		table->bucket[index] = NULL;
	}


}


boolean delete_hash_node_on_list(head, key) 
	struct Hash_Node *head;
	const char* key;
{
	if( is_empty(head) ||
		(is_empty(head->next) && strcmp(head->key, key) != 0)
	) return false;
	
	if(strcmp(head->key, key) == 0) {
		free(head);
		return true;
	} 

	head = head->next;
	// Stores the address of the previous NODE
	struct Hash_Node *prev = NULL;

	while(!is_empty(head)) {
		prev = head;
		if(strcmp(head->key, key) != 0) {
			head = head->next;
		} else {
			prev->next = head->next;
			free(head);
			return true;
		}
	}
	return false;
}


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

void check_if_filled(table)
	Hash_Table *table;
{}

void rehash(table)
	Hash_Table *table;
{}

// Move this to utilities file and make it a MACRO
boolean is_empty(thing) 
	void *thing;
{
	return (thing == NULL);
}

void hash_free(table) 
	Hash_Table *table;
{
	if(is_empty(table)) {
	 	free(table);
	 	return;
	}
	if(table->bucket) {
		for(int i = 0; i < table->capacity; i++) {
			if(!is_empty(table->bucket[i])) {
		 		free_all_nodes_in_bucket(table->bucket[i]);
			}
	 	}
		free(table->bucket);
	}
	free(table);
}