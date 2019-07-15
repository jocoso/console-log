#define INITIAL_CAP 100
#define HT_PRIME_1 3
#define HT_PRIME_2 7

#ifndef NULL 
	#define NULL 0
	#define EQUALS(value1, value2) (value1 == value2)
#endif


// hash_table.h
typedef struct {
	char* key;
	void* value;
}Hash_Node; // ht_item

typedef struct {
	int size;
	int count;
	int base_size;
	Hash_Node** items;
} Hash_Table; // ht_hash_table

Hash_Table* new_hash(); // ht_new
void hash_insert(Hash_Table* hash, const char* key, void* value); // ht_insert 
void* hash_search(Hash_Table* hash, const char* key); // ht_search
static Hash_Node* hash_new_item(const char* k, void* v); // ht_new_item
static void hash_delete_node(Hash_Node *i); // ht_del_item
void hash_delete(Hash_Table* hash, const char* key); //ht_delete
static int hash(const char* s, const int a, const int m); // ht_hash
static int hash_code(const char* s, const int num_buckets, const int attempt); // ht_get_hash
void hash_free(Hash_Table *hash); // ht_del_hash_table
static Hash_Table *hash_new_size(const int base_size); // ht_hash_table
static void hash_resize(Hash_Table *hash, const int base_size); // ht_resize
static void hash_resize_up(Hash_Table* hash); // ht_resize_up
static void hash_resize_down(Hash_Table *hash); // ht_resize_down
