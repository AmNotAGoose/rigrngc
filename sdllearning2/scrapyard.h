#ifndef SCRAPYARD_H
#define SCRAPYARD_H

#include "config.h"

int time_to_next_reset(Config* cfg);

int roll_dice(int size);
int roll_for_scrap();

void SY_tutorial();
void SY_menu(Config* cfg);

#endif