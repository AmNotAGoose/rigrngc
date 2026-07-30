#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <string.h>
#include <time.h>

#include "config.h";



int config_load(Config* cfg) {
    FILE* file = fopen("config.txt", "r");
    if (!file) {
        cfg->seed = 0;
        cfg->luck = 0;
        cfg->cur_rolls = 0;
        cfg->last_roll_timestamp = time(NULL);
        cfg->last_collect_timestamp = time(NULL);
        cfg->scrap = 0;
        cfg->product = 0;
        cfg->rolls_per_reset = 5;

        for (int i = 0; i < 6; i++) {
            strcpy(cfg->modules[i], "None");
        }

        return 0;
    }

    char line[128];

    while (fgets(line, sizeof(line), file)) {
        sscanf(line, "seed=%d", &cfg->seed);
        sscanf(line, "luck=%d", &cfg->luck);
        sscanf(line, "cur_rolls=%d", &cfg->cur_rolls);
        sscanf(line, "last_roll_timestamp=%lld", (long long*)&cfg->last_roll_timestamp);
        sscanf(line, "last_collect_timestamp=%lld", (long long*)&cfg->last_collect_timestamp);
        sscanf(line, "scrap=%d", &cfg->scrap);
        sscanf(line, "product=%d", &cfg->product);
        sscanf(line, "rolls_per_reset=%d", &cfg->rolls_per_reset);

        sscanf(line,
            "modules=%31[^,],%31[^,],%31[^,],%31[^,],%31[^,],%31s",
            cfg->modules[0],
            cfg->modules[1],
            cfg->modules[2],
            cfg->modules[3],
            cfg->modules[4],
            cfg->modules[5]);
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
    fprintf(file, "last_collect_timestamp=%d\n", cfg->last_collect_timestamp);
    fprintf(file, "scrap=%d\n", cfg->scrap);
    fprintf(file, "product=%d\n", cfg->product);
    fprintf(file, "rolls_per_reset=%d\n", cfg->rolls_per_reset);

    fprintf(file, "modules=%s,%s,%s,%s,%s,%s\n",
        cfg->modules[0],
        cfg->modules[1],
        cfg->modules[2],
        cfg->modules[3],
        cfg->modules[4],
        cfg->modules[5]);

    fclose(file);
    return 0;
}