#ifndef HASHMAP_H
#define HASHMAP_H
	#include "../utilities/stddefs.h"

	#define INITIAL_HASH_SIZE 100
	#define EXAMINE_HASH_NODE(node) (printf("KEY: %s\n", node->key))

	struct Hash_Node {
		char* key;
		void* value;
		struct Hash_Node *next;
	};

	typedef struct Hash_Table{
		struct Hash_Node **bucket;
		unsigned int size;
		unsigned int capacity;
	} Hash_Table;

	Hash_Table *new_hash_table();
	struct Hash_Node *new_hash_node(char* key, void* value);
	void hash_insert(Hash_Table *table, char* key, void* value);
	void *hash_get(Hash_Table *table, char* key);
	struct Hash_Node *get_hash_node_on_list(struct Hash_Node *head, const char* key);
	void insert_hash_node_in_next_available_spot(struct Hash_Node *head, struct Hash_Node *node);
	void free_all_nodes_in_bucket(struct Hash_Node *head);
	void hash_delete(Hash_Table *table, const char* key);
	boolean delete_hash_node_on_list(struct Hash_Node *head, const char* key);
	const unsigned int hash_code(const unsigned int size, const char* str);
	void check_if_filled(Hash_Table *table);
	void rehash(Hash_Table *table);
	boolean is_empty(void *thing);
	void hash_free(Hash_Table *table);
	

#endif