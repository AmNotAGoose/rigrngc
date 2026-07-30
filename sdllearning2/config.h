#ifndef CONFIG_H
#define CONFIG_H

#include <time.h>


typedef struct {
	int seed;
	int luck;
	int cur_rolls;
	time_t last_roll_timestamp;
	int scrap;
} Config;

int config_load(Config* cfg);
int config_save(Config* cfg);


#endif