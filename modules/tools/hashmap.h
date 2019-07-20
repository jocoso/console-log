#ifndef HASHMAP_H
#define HASHMAP_H

	#define INITIAL_HASH_SIZE 100

	struct Hash_Node {
		char* key;
		void* value;
	};

	typedef struct Hash_Table{
		unsigned int size;
		unsigned int capacity;
		struct Hash_Node** buckets;
	} Hash_Table;

	Hash_Table *new_hash_table();
	struct Hash_Node *new_hash_node(char* key, void* value);
	void hash_insert(Hash_Table *table, char* key, void* value);
	void *hash_get(Hash_Table *table, char* key);
	struct Hash_Node *get_hash_node(Hash_Table *table, char* key);
	void hash_delete(Hash_Table *table, char* key);
	const unsigned int hash_code(const unsigned int size, const char* str);
	void hash_free(Hash_Table *table);
	

#endif