#ifndef CONFIG_H
#define CONFIG_H

#include <time.h>

#include "dictionary.h"

typedef enum {
	M_None,
	M_Generator,
	M_Inverter,
	M_QuadrupleNegative,
	M_DoublePositive,
	M_PlusOne,
	M_MinusThree,
	M_Out
} Module;


typedef struct {
	int seed;
	int luck;
	int cur_rolls;
	time_t last_roll_timestamp;
	int scrap;
	int product;
	char modules[6][32];
	int rolls_per_reset;
} Config;

int config_load(Config* cfg);
int config_save(Config* cfg);


#endif