#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <string.h>

#include "config.h";



int config_load(Config* cfg) {
    FILE* file = fopen("config.txt", "r");
    if (!file) {
        cfg->seed = 0;
        cfg->luck = 0;
        cfg->cur_rolls = 0;
        cfg->last_roll_timestamp = 0;
        cfg->scrap = 0;
        return 0;
    }

    char line[128];

    while (fgets(line, sizeof(line), file)) {
        sscanf(line, "seed=%d", &cfg->seed);
        sscanf(line, "luck=%d", &cfg->luck);
        sscanf(line, "cur_rolls=%d", &cfg->cur_rolls);
        sscanf(line, "last_roll_timestamp=%lld", (long long*)&cfg->last_roll_timestamp);
        sscanf(line, "scrap=%d\n", &cfg->scrap);
    }

    fclose(file);
    return 0;
}

int config_save(Config* cfg) {
    FILE* file = fopen("config.txt", "w");
    if (!file) {
        return -1;
    }

    fprintf(file, "seed=%d\n", cfg->seed);
    fprintf(file, "luck=%d\n", cfg->luck);
    fprintf(file, "cur_rolls=%d\n", cfg->cur_rolls);
    fprintf(file, "last_roll_timestamp=%d\n", cfg->last_roll_timestamp);
    fprintf(file, "scrap=%d\n", cfg->scrap);

    fclose(file);
    return 0;
}