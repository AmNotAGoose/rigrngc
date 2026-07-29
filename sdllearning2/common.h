#ifndef COMMON_H
#define COMMON_H

#define ARRAY_COUNT(x) (sizeof(x) / sizeof(x[0]))
#define MAKE_DICT(items) { &items, ARRAY_COUNT(items) };

#endif // !COMMON_H
