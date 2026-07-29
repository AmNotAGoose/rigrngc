#include <stdlib.h>
#include "dictionary.h"

DictItem* get_item_by_key(Dict dict, const char* key) {
	// its linear search for now
	for (int i = 0; i < dict.count; i++) {
		DictItem cur_item = dict.items[i];
		if (strcmp(cur_item.key, key)) {
			return &cur_item;
		}
	}
	return NULL;
}
