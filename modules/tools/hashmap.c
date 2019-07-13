#include <stdlib.h>
#include <string.h>
#include <math.h>
#include "hashmap.h"


static Hash_Node HASH_DELETED_NODE = {NULL, NULL};


static Hash_Node* hash_new_node(const char* k, const char* v) {
	Hash_Node* node = malloc(sizeof(Hash_Node));
	node->key = strdup(k);
	node->value = strdup(v);
	return node;
}

// hash_insert(hash, "--argument", "rojo");
void hash_insert(Hash_Table* hash, const char* key, const char* value) {
	Hash_Node* item = hash_new_node(key, value);
	int index = hash_code(item->key, hash->size, 0);
	Hash_Node* cur_item = hash->items[index];
	int i = 1;
	while(cur_item != NULL) {
		if(cur_item != &HASH_DELETED_NODE) {
			if(strcmp(cur_item->key, key) == 0) {
				hash_delete_node(cur_item);
				hash->items[index] = item;
				return;
			}
		}
	}
	
	hash->items[index] = item;
	hash->count++;
}

// hash_search(hash, "--argument");
char* hash_search(Hash_Table* hash, const char* key) {
	int index = hash_code(key, hash->size, 0);
	Hash_Node *item = hash->items[index];
	int i = 1;
	
	while(item != NULL) {
		if(strcmp(item->key, key) == 0) {
			return item->value;
		}
		index = hash_code(key, hash->size, i);
		item = hash->items[index];
		i++;
	}
	return NULL;
}

Hash_Table* new_hash() {
	Hash_Table *hash = malloc(sizeof(Hash_Table));
	
	hash->size = 53;
	hash->count = 0;
	hash->items = calloc((size_t)hash->size, sizeof(Hash_Node*));
	
	return hash;
}

static void hash_delete_node(Hash_Node *hash) {
	free(hash->key);
	free(hash->value);
	free(hash);
}

void hash_delete(Hash_Table* hash, const char* key) {
	int index = hash_code(key, hash->size, 0);
	Hash_Node* node = hash->items[index];
	
	int i = 1;
	while(node != NULL) {
		if(node != &HASH_DELETED_NODE) {
			if(strcmp(node->key, key) == 0) {
				hash_delete_node(node);
				hash->items[index] = &HASH_DELETED_NODE;
			}
		}
		index = hash_code(key, hash->size, i);
		node = hash->items[index];
		i++;
	}
	hash->count--;
}

static int hash(const char* s, const int a, const int m) {
	long hash = 0;
	const int len_s = strlen(s);
	
	for(int i = 0; i < len_s; i++) {
		hash += pow(a, len_s - (i+1)) * s[i];
		hash = hash % m;
	}
	
	return (int)hash;
}

static int hash_code(const char* s, const int num_buckets, const int attempt) {
	const int hash_a = hash(s, HT_PRIME_1, num_buckets);
	const int hash_b = hash(s, HT_PRIME_2, num_buckets);
	return (hash_a + (attempt * (hash_b + 1))) % num_buckets;
}

void hash_free(Hash_Table *hash) {
	for(int i = 0; i < hash->size; i++) {
		Hash_Node* item = hash->items[i];
		if(item != NULL) {
			hash_delete_node(item);
		}
	}
	
	free(hash->items);
	free(hash);
}

