#define _CRT_SECURE_NO_WARNINGS

#include <SDL3/SDL.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#include "dictionary.h"
#include "display.h"
#include "common.h"


static const DictItem age_luck_items[] = {
	{"0-13", 3},
	{"14-25", 6},
	{"26+", -3},
};
static const Dict age_luck_dict = MAKE_DICT(age_luck_items);


static DictItem color_luck_items[] = {
	{"red", 3},
	{"blue", 10},
	{"green", -1},
};
static const Dict color_luck_dict = MAKE_DICT(color_luck_items);

const char* main_menu_choices[] = {
	"roll for scrap",
	"spend your scrap",
	"build rigs"
};

static float luck = 0;
unsigned int seed = 0;


void onboarding() {
	display_message(DM_Emphasis, "welcome. to rigrng (c).");
	display_message(DM_Section, "seed: %d", seed);
	
	char* age_key = NULL;
	char* color_key = NULL;
	
	display_message(DM_None, "firstly, tell me about yourself. this will significantly impact your LUCK in the game.");
	 
	const char** age_luck_ranges = malloc(sizeof(char*) * age_luck_dict.count);
	get_keys(age_luck_dict, age_luck_ranges);

	display_message(DM_Prompt, "what is your age?");
	age_key = age_luck_dict.items[get_user_choice(age_luck_ranges, age_luck_dict.count)].key;

	const char** color_luck_ranges = malloc(sizeof(char*) * color_luck_dict.count);
	get_keys(color_luck_dict, color_luck_ranges);

	display_message(DM_Prompt, "what is your favorite color?");
	color_key = color_luck_dict.items[get_user_choice(color_luck_ranges, color_luck_dict.count)].key;

	DictItem* age_item = get_item_by_key(age_luck_dict, age_key);
	DictItem* color_item = get_item_by_key(color_luck_dict, color_key);

	free(age_luck_ranges);
	free(color_luck_ranges); 

	int age_luck_value = age_item->value;
	int color_luck_value = age_item->value;

	luck = age_luck_value + color_luck_value;
		
	display_message(DM_Emphasis, "your AGE scores you %d", age_luck_value);
	display_message(DM_Emphasis, "your favorite COLOR scores you %d", color_luck_value);
	display_message(DM_Emphasis, "your LUCK is therefore %f", luck);
}

int main_menu() {
	int menu = 0;
	
	display_divider();
	display_message(DM_Prompt, "what would you like to do?");
	int choice = get_user_choice(&main_menu_choices, ARRAY_COUNT(main_menu_choices));
	return choice;
}

int main() {
	seed = (int)time(NULL);
	srand(seed);

	onboarding();

	while (1) {
		int menu = main_menu();


	}

	return 0;
}
