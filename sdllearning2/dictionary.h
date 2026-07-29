#ifndef DICTIONARY_H
#define DICTIONARY_H

#include <stdlib.h>

typedef struct {
	const char* key;
	int value;
} DictItem;

typedef struct {
	const char** key;
	size_t count;
} DictKeys;

typedef struct {
	int** value;
	size_t count;
} DictValues;

typedef struct {
	DictItem* items;
	size_t count;
} Dict;

DictItem* get_item_by_key(Dict dict, const char* key);
DictKeys get_keys(Dict dict);
DictValues get_values(Dict dict);

#endif
