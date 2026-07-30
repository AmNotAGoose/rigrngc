#ifndef COMMON_H
#define COMMON_H

#define ARRAY_COUNT(x) (sizeof(x) / sizeof(x[0]))
#define MAKE_DICT(items) { &items, ARRAY_COUNT(items) };

typedef struct {
	char** data;
	size_t count;
} StringArray;

#endif // !COMMON_H
