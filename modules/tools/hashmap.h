#define INITIAL_CAP 100
#define HT_PRIME_1 3
#define HT_PRIME_2 7

#ifndef NULL 
	#define NULL 0
	#define EQUALS(value1, value2) (value1 == value2)
#endif

#define TEST(value) printf("test--(%d)\n", value)


// hash_table.h
typedef struct {
	char* key;
	char* value;
}Hash_Node; // ht_item

typedef struct {
	int size;
	int count;
	Hash_Node** items;
} Hash_Table; // ht_hash_table

Hash_Table* new_hash(); // ht_new
void hash_insert(Hash_Table* hash, const char* key, const char* value); // ht_insert 
char* hash_search(Hash_Table* hash, const char* key); // ht_search
static Hash_Node* hash_new_item(const char* k, const char* v); // ht_new_item
static void hash_delete_node(Hash_Node *i); // ht_del_item
void hash_delete(Hash_Table* hash, const char* key); //ht_delete
static int hash(const char* s, const int a, const int m); // ht_hash
static int hash_code(const char* s, const int num_buckets, const int attempt); // ht_get_hash
void hash_free(Hash_Table *hash); // ht_del_hash_table
