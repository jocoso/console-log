#ifndef HASHMAP_H
#define HASHMAP_H

	#define INITIAL_HASH_SIZE 100

	struct Hash_Node {
		char* key;
		void* value;
	} Hash_Node;

	typedef struct {
		unsigned int size;
		unsigned int capacity;
		struct Hash_Node** buckets;
	} Hash_Table;

	const unsigned int hash_code(const unsigned int size, const char* str);

#endif