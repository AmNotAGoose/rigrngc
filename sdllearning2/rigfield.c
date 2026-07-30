#include <time.h>

#include "rigfield.h"
#include "display.h"
#include "common.h"
#include "config.h" 
#include "shop.h" 
#include "dictionary.h" 


void RIG_tutorial() {
	display_message(DM_Emphasis, "This is the rigfield.");
	get_user_continue();
	display_message(DM_Emphasis, "Here, you can assemble RIGs with your MODULES.");
	get_user_continue();
	display_message(DM_Emphasis, "If you don't have any, roll for SCRAP first, then buy MODULES in the shop.");
	get_user_continue();
	display_message(DM_Emphasis, "* Due to time constraints, you may only assemble one RIG :(");
	get_user_continue();
	display_message(DM_Emphasis, "Each RIG has a Generator module and an Out module");
	get_user_continue();
	display_message(DM_Emphasis, "Both are given to you for free, and cannot be removed.");
	get_user_continue();
	display_message(DM_Emphasis, "The Generator module produces 1 PRODUCT per minute.");
	get_user_continue();
	display_message(DM_Emphasis, "You may add / swap in the middle 6 MODULES to increase production.");
	get_user_continue();
	display_message(DM_Emphasis, "When passed through Out, if a negative value is passed, it will become 0 instead.");
	get_user_continue();
}


void display_rig(Config* cfg) {
	display_divider();
	display_message(DM_Emphasis, "your rig");
	display_divider();

	display_message(DM_Emphasis, "Generator");

	for (int i = 0; i < ARRAY_COUNT(cfg->modules); i++) {
		display_message(DM_None, "[%d] %s", i, cfg->modules[i]);
	}
	
	display_message(DM_Emphasis, "Out");

	display_divider();
}

char* RIG_menu_options[] = {
	"move / swap module",
	"collect",
	"tutorial",
	"back"
};

float get_efficiency(Config* cfg) {
	float eff = 1; // generator = 1

	for (int i = 0; i < 6; i++) {

		DictItem* cur_module_item = get_item_by_key(scrap_menu_dict, cfg->modules[i]);

		switch (cur_module_item->value) {
			case M_None: {
				break;
			}
			case M_Generator: {
				break;
			}
			case M_Inverter: {
				eff = -eff;
				break;
			}
			case M_QuadrupleNegative: {
				if (eff < 0) {
					eff *= 4;
				}
				break;
			}
			case M_DoublePositive: {
				if (eff > 0) {
					eff *= 2;
				}
				break;
			}
			case M_PlusOne: {
				eff += 1;
				break;
			}
			case M_MinusThree: {
				eff -= 3;
				break;
			}
			case M_Out: {
				break;
			}
		}
	}

	return eff;
}

void swap_modules(Config* cfg) {
	display_message(DM_Prompt, "select the index of the first module: ");
	int m1 = get_user_int();

	display_message(DM_Prompt, "select the index of the second module: ");
	int m2 = get_user_int();

	if (m1 >= 0 && m1 < 6 && m2 >= 0 && m2 < 6) {
		char temp[32];

		strcpy(temp, cfg->modules[m1]);
		strcpy(cfg->modules[m1], cfg->modules[m2]);
		strcpy(cfg->modules[m2], temp);

		config_save(cfg);

		display_message(DM_Emphasis, "success");
		return;
	}

	display_message(DM_Emphasis, "failure");
	return;
}

void collect(Config* cfg) {
	int minutes = (int)(time(NULL) - cfg->last_collect_timestamp) / 60;
	int product = (int)(minutes * get_efficiency(cfg));

	display_message(DM_Emphasis, "collected %d PRODUCT at a rate of %f product/min for %d min", product, get_efficiency(cfg), minutes);

	cfg->product += product;
	cfg->last_collect_timestamp = time(NULL);

	config_save(cfg);
}

void RIG_menu(Config* cfg) {	
	while (1) {
		display_rig(cfg);
		display_message(DM_Prompt, "what would you like to do? [ product/min: %f ]", get_efficiency(cfg));

		int choice = get_user_choice(&RIG_menu_options, ARRAY_COUNT(RIG_menu_options));

		switch (choice) {
			case 0:
				display_rig(cfg);
				swap_modules(cfg);
				break;
			case 1:
				collect(cfg);
				break;
			case 2:
				RIG_tutorial();
				break;
			case 3:
				return;
			default:
				break;
		}
	}
}