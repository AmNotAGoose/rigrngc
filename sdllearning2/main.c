#include <SDL3/SDL.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#include "dictionary.h"
#include "common.h"


static const DictItem age_luck_items[] = {
	{"0-13", 3},
	{"14-25", 6},
	{"26-100", -3},
};

static const Dict age_luck_dict = MAKE_DICT(age_luck_items);


static DictItem color_luck_items[] = {
	{"red", 3},
	{"blue", 10},
	{"green", -1},
};


float luck = 0;


int roll_dice() {
	return (rand() % 6) + 1;
}

int random_pull() {
	return roll_dice() + roll_dice();
}

void onboarding() {
	int age;
	
	
	printf("firstly, tell me about yourself. this will significantly impact your experience in the game.");
	

}

int main() {
	unsigned int seed = (int)time(NULL);
	srand(seed);

	printf("welcome. to rigrng (c). \n------------- \nseed: %d\n", seed);

	onboarding();

	while (1) {
		printf("what would you like to do ?");
		


	}


	return 0;
}
