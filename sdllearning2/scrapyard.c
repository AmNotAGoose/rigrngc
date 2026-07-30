#include "scrapyard.h"
#include "display.h"
#include "common.h"
#include "config.h"

char* SY_menu_options[] = {
	"roll now",
	"enable autoroll",
	"tutorial",
	"back"
};

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



	return total_scrap;
}

void SY_menu(Config* cfg) {
	
	while (1) {
		display_message(DM_Emphasis, "entered the scrapyard");
		display_divider();
		display_message(DM_Prompt, "what would you like to do? [ scrap: %d | rolls: %d | reset in %lld s ]", cfg->scrap, cfg->cur_rolls, cfg->last_roll_timestamp);

		int choice = get_user_choice(&SY_menu_options, ARRAY_COUNT(SY_menu_options));
	
		switch (choice) {
			case 0:

				break;
			case 1:

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
