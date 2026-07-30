#include "dictionary.h"

DictItem* get_item_by_key(Dict dict, const char* key) {
	// its linear search for now
	for (int i = 0; i < dict.count; i++) {
		DictItem* cur_item = &(dict.items[i]);
		if (strcmp((*cur_item).key, key) == 0) {
			return cur_item;
		}
	}
	return NULL;
}

//void get_keys(Dict dict, const char** buffer) { // the buffer should be the same size as the dict.count
//	for (size_t i = 0; i < dict.count; i++) {
//		buffer[i] = dict.items[i].key;
//	}
//}

const char** get_keys(Dict* dict) {
	const char** keys = malloc(sizeof(char*) * dict->count);
	for (size_t i = 0; i < dict->count; i++) {
		keys[i] = dict->items[i].key;
	}

	return keys;
}