#include <stdio.h>
#include "modules/argshandler.h"
#include "modules/tools/hashmap.h"

int main(int argc, char** argv) {
	Hash_Table *hash = new_hash();
	hash_insert(hash, "--argument", "rojo");
	char* rojo = hash_search(hash, "--argument");
	printf("%s\n", rojo);
	hash_free(hash);
}