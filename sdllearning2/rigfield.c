#include <time.h>

#include "rigfield.h"
#include "display.h"
#include "common.h"
#include "config.h" 


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

char* modules[6];

void display_rig() {
	display_divider();
	display_message(DM_Emphasis, "your rig");
	display_divider();

	display_message(DM_Emphasis, "Generator");

	for (int i = 0; i < ARRAY_COUNT(modules); i++) {
		display_message(DM_Emphasis, modules[i]);
	}
	
	display_message(DM_Emphasis, "Out");

	display_divider();
}

void RIG_menu(Config* cfg) {
	display_rig();
	
	//while (1) {

	//}
}