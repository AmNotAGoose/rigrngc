#ifndef DICTIONARY_H
#define DICTIONARY_H

#include <stdlib.h>

typedef struct {
	const char* key;
	int value;
} DictItem;

typedef struct {
	DictItem* items;
	size_t count;
} Dict;

DictItem* get_item_by_key(Dict dict, const char* key);
void get_keys(Dict dict, const char** buffer);

#endif
