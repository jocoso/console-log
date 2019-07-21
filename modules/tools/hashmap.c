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

void hash_insert(table, key, value)
	Hash_Table *table; 
	char* key; 
	void* value;
{
	check_if_filled(table);

	if(is_empty(table)) return;
	unsigned int index = hash_code(table->capacity, key);
	struct Hash_Node *node = new_hash_node(key, value);

	//printf("%d\n", (int*) node->value);

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
	if(select_list != NULL) {
		if(select_list->next == NULL) {
			return select_list->value;
		} else {
			while(select_list != NULL) {
				if(strcmp(select_list->key, key)) {
					return select_list->value;
				}
				select_list = select_list->next;
			}
		}

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
	if(head == NULL) return;

	if(head->next == NULL){ 
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

void hash_delete(table, key) 
	Hash_Table *table;
	char* key;
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

void check_if_filled(table)
	Hash_Table *table;
{}

void rehash(table)
	Hash_Table *table;
{}

// Move this to utilities file
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
			if(table->bucket[i])
		 		free_all_nodes_in_bucket(table->bucket[i]);
	 	}
		free(table->bucket);
	}
	free(table);
}