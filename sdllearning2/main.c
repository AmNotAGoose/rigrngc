#define _CRT_SECURE_NO_WARNINGS

#include <SDL3/SDL.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#include "dictionary.h"
#include "display.h"
#include "common.h"


static const DictItem age_luck_items[] = {
	{"-13", 3},
	{"14-25", 6},
	{"26-", -3},
};
static const Dict age_luck_dict = MAKE_DICT(age_luck_items);


static DictItem color_luck_items[] = {
	{"red", 3},
	{"blue", 10},
	{"green", -1},
};
static const Dict color_luck_dict = MAKE_DICT(color_luck_items);


static float luck = 0;
unsigned int seed = 0;



int roll_dice(int size) {
	return (rand() % size) + 1;
}

int scrapyard() {
	return roll_dice(6) + roll_dice(6);
}

void onboarding() {
	display_message(DM_Emphasis, "welcome. to rigrng (c).");
	display_message(DM_Section, "seed: %d", seed);

	int age_input_raw;
	char* age_key = NULL;
	char color_key[16];
	
	display_message(DM_None, "firstly, tell me about yourself. this will significantly impact your LUCK in the game.");
	
	while (1) {
		const char* age_luck_ranges;
		get_keys(age_luck_dict, &age_luck_ranges);

		age_key = get_user_choice(&age_luck_ranges, age_luck_dict.count);

		printf(age_key);

		//if (age_input_raw >= 0 && age_input_raw <= 13) {
		//	age_key = "-13";
		//}
		//else if (age_input_raw > 13 && age_input_raw <= 25) {
		//	age_key = "14-25";
		//}
		//else if (age_input_raw > 25) {
		//	age_key = "26-";
		//}
		//else {
		//	age_key = "";
		//}

		printf("\nwhat is your favorite COLOR ? \n> ");
		scanf("%15s", color_key);

		DictItem* age_item = get_item_by_key(age_luck_dict, age_key);
		DictItem* color_item = get_item_by_key(color_luck_dict, color_key);

		if (!age_item || !color_item) {
			printf("\ntry again but think harder about it");
			continue;
		}

		luck = (*age_item).value + (*color_item).value;

		printf("\nyour AGE is %d, your favorite COLOR is %s, your LUCK is therefore %f", 3, color_key, luck);

		break;
	}
}

int main_menu() {
	int menu = 0;
	printf("\n\n-------------\nwhat would you like to do? \n[1] roll once\n[2] exit \n-------------\n> ");
	scanf("%d", &menu);
	return (menu > 0 && menu <= 2 ? menu : -1);
}

int main() {
	seed = (int)time(NULL);
	srand(seed);

	onboarding();

	while (1) {
		int menu = main_menu();
		printf("%d", menu);
	}

	return 0;
}
