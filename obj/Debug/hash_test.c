#include <stdio.h>
#include <stdlib.h>

#include "../../modules/utilities/debug.h"
#include "../../modules/utilities/stddefs.h"
#include "../../modules/tools/hashmap.h"

// Success
boolean can_call_new_and_free_without_a_segfault() {
    Hash_Table *table_test = new_hash_table();
    hash_free(table_test);
    return true;
}

// Success
boolean can_call_once_insert_and_get() {
    Hash_Table *table_test = new_hash_table();
    hash_insert(table_test, "Josh", 23);
    int answer = (int*) hash_get(table_test, "Josh");
    hash_free(table_test);
    return (answer == 23);
}

// Success
boolean can_call_multiple_insert_and_get() {
    Hash_Table *table_test = new_hash_table();

    hash_insert(table_test, "Josh", 23);
    hash_insert(table_test, "Rosemary", 57);
    hash_insert(table_test, "Manatee", 200);

    int answer1 = (int*) hash_get(table_test, "Josh");
    int answer2 = (int*) hash_get(table_test, "Rosemary");
    int answer3 = (int*) hash_get(table_test, "Manatee");

    hash_free(table_test);
    
    return ((answer1 == 23) && (answer2 == 57) && (answer3 == 200));
}

// Success
boolean does_is_empty_do_its_job() {
    Hash_Table *table_test1 = new_hash_table();
    Hash_Table *table_test2 = NULL;
    return !is_empty(table_test1) && is_empty(table_test2);
}

// Success
boolean can_delete_hash_nodes() {
    Hash_Table *table_test = new_hash_table();

    hash_insert(table_test, "Josh", 23);
    hash_insert(table_test, "Rosemary", 57);
    hash_insert(table_test, "Manatee", 200);

    hash_delete(table_test, "Manatee");

    int answer1 = (int*) hash_get(table_test, "Josh");
    int answer2 = (int*) hash_get(table_test, "Rosemary");
    void* answer3 = hash_get(table_test, "Manatee");
    hash_free(table_test);

    return (!is_empty(answer1) && !is_empty(answer2)) && is_empty(answer3);
}


int main() {
    boolean test1 = can_call_new_and_free_without_a_segfault();
    boolean test2 = can_call_once_insert_and_get();
    boolean test3 = can_call_multiple_insert_and_get(); 
    boolean test4 = does_is_empty_do_its_job();
    boolean test5 = can_delete_hash_nodes();

    PNT_DEBUG("Can call new() and free() functions without a segfault?", test1, true); 
    PNT_DEBUG("Can call once insert() and get() functions?", test2, true);
    PNT_DEBUG("Can call multiple insert() and get() functions?", test3, true);
    PNT_DEBUG("Does is_empty() do its job", test4, true);
    PNT_DEBUG("Can delete hash nodes?", test5, true);

    return 0;
}
