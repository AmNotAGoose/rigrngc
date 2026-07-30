#include <time.h>

#include "scrapyard.h"
#include "display.h"
#include "common.h"
#include "config.h" 


int roll_dice(int size) {
	return (rand() % size) + 1;
}

void SY_tutorial() {
	display_message(DM_Emphasis, "This is the scrapyard.");
	get_user_continue();
	display_message(DM_Emphasis, "Here, you can roll for SCRAP.");
	get_user_continue();
	display_message(DM_Emphasis, "You get 5 rolls every 5 minutes.");
	get_user_continue();
	display_message(DM_Emphasis, "SCRAP can be used to create MODULES.");
	get_user_continue();
}

int roll_for_scrap() {
	int total_scrap = 0;

	total_scrap = roll_dice(6) + roll_dice(6);

	return total_scrap;
}

int time_to_next_reset(Config* cfg) {
	//printf("%lld\n", cfg->last_roll_timestamp);
	//printf("%lld\n", time(NULL));
	//printf("%lld\n", time(NULL) - cfg->last_roll_timestamp);
	int ttnr = (500 - (int)(time(NULL) - cfg->last_roll_timestamp));
	return ttnr >= 0 ? ttnr : 0;
}

char* SY_menu_options[] = {
	"roll now",
	"reset",
	"tutorial",
	"back"
};

void SY_menu(Config* cfg) {
	
	while (1) {
		display_message(DM_Emphasis, "entered the scrapyard");
		display_divider();
		display_message(DM_Prompt, "what would you like to do? [ scrap: %d | rolls: %d | reset in %d s ]", cfg->scrap, cfg->cur_rolls, time_to_next_reset(cfg));

		int choice = get_user_choice(&SY_menu_options, ARRAY_COUNT(SY_menu_options));
	
		switch (choice) {
			case 0:
				if (cfg->cur_rolls == 0) {
					display_message(DM_Emphasis, "you're out of rolls! wait until the reset.");
					break;
				}

				int scrap_gained = roll_for_scrap();

				cfg->scrap += scrap_gained;
				cfg->cur_rolls -= 1;

				display_message(DM_Emphasis, "you gained +%d SCRAP. you now have %d SCRAP", scrap_gained, cfg->scrap);
				
				config_save(cfg);
				break;
			case 1:
				if (time_to_next_reset(cfg) != 0) {
					display_message(DM_Emphasis, "wait until the next reset.");
					break;
				}

				cfg->cur_rolls = cfg->rolls_per_reset;
				cfg->last_roll_timestamp = time(NULL);

				display_message(DM_Emphasis, "reset. +%d rolls.", cfg->rolls_per_reset);
				config_save(cfg);
				break;
			case 2:
				SY_tutorial();
				break;
			case 3:
				return;
			default:
				break;
		}
	}
}
