#include <SDL3/SDL.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#include "dictionary.h"
#include "common.h"


static const DictItem age_luck_items[] = {
	{"", 4}
};

static const Dict age_luck_dict = MAKE_DICT(age_luck_items);


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
