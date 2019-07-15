#include <stdlib.h>
#include <string.h>
#include <math.h>
#include "hashmap.h"
#include "prime.h"


static Hash_Node HASH_DELETED_NODE = {NULL, NULL};

Hash_Table* new_hash() {
	return hash_new_size(INITIAL_CAP);
}

static Hash_Table *hash_new_size(const int base_size) {
	Hash_Table *hash = malloc(sizeof(Hash_Table));
	hash->base_size = base_size;
	hash->size = next_prime(hash->base_size);
	hash->count = 0;
	hash->items =(Hash_Node**) calloc((size_t)hash->size, sizeof(Hash_Node*));
	
	return hash;
}

static void hash_resize(Hash_Table *hash, const int base_size) {
	if(base_size < INITIAL_CAP) return;

	Hash_Table *new_table = hash_new_size(base_size);

	for(int i =0; i < hash->size; i++) {
		Hash_Node *item = hash->items[i];
		if(item != NULL && item != &HASH_DELETED_NODE) {
			hash_insert(new_table, item->key, item->value);
		}
	}

	hash->base_size = new_table->base_size;
	hash->count = new_table->count;

	const int tmp_size = hash->size;
	new_table->size = tmp_size;

	Hash_Node** tmp_items = hash->items;
	hash->items = new_table->items;
	new_table->items = tmp_items;

	hash_free(new_table);

}

static void hash_resize_up(Hash_Table* hash) {
	const int new_size = hash->base_size * 2;
	hash_resize(hash, new_size);
}

static void hash_resize_down(Hash_Table *hash) {
	const int new_size = hash->base_size / 2;
	hash_resize(hash, new_size);
}

static Hash_Node* hash_new_node(const char* k, void* v) {
	//Hash_Node* node = malloc(sizeof(Hash_Node *));
	// node->key = strdup(k);
	// node->value = &v;
	// printf("key: %d, value: %d", node->key, *((int *)node->value));
	// return node;
}

void hash_insert(Hash_Table* hash, const char* key, void* value) {
	const int load = hash->count * INITIAL_CAP / hash->size;
	if(load > 70) hash_resize_up(hash);

	Hash_Node* item = hash_new_node(key, value);
	int index = hash_code(&(item->key), hash->size, 0);
	Hash_Node* cur_item = hash->items[index];
	int i = 1;
	//printf("%d\n", hash->items[index]->key);
	while(cur_item != NULL) {
		if(cur_item != &HASH_DELETED_NODE) {
			if(strcmp(cur_item->key, key) == 0) {
				hash_delete_node(cur_item);
				hash->items[index] = item;
				return;
			}
		}
	}
	// printf("%d\n%d\n", index, hash->size);
	hash->items[0] = (Hash_Node*)malloc(sizeof(Hash_Node));
	hash->items[0] = item;
	printf("%s\n", &(hash->items[0]->key));
	// hash->items[index] = item;
	//hash->count++;
}

void* hash_search(Hash_Table* hash, const char* key) {
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


static void hash_delete_node(Hash_Node *hash) {
	free(hash->key);
	free(hash->value);
	free(hash);
}

void hash_delete(Hash_Table* hash, const char* key) {
	const int load = hash->count * INITIAL_CAP / hash->size;
	if(load < 10) hash_resize_down(hash);

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

