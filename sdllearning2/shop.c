#include <stdlib.h>


#include "config.h"
#include "display.h"
#include "common.h"
#include "shop.h"

void SHOP_tutorial() {
	display_message(DM_Emphasis, "there are two types of currency in this game: SCRAP and PRODUCT");
	get_user_continue();
	display_message(DM_Emphasis, "SCRAP can be gained from the scrapyard, where you can roll for it.");
	get_user_continue();
	display_message(DM_Emphasis, "SCRAP can be used to purchase MODULES");
	get_user_continue();
	display_message(DM_Emphasis, "MODULES can be used to build RIGS");
	get_user_continue();
	display_message(DM_Emphasis, "RIGS will generate PRODUCT");
	get_user_continue();
	display_message(DM_Emphasis, "PRODUCT can be used to purchase permanant buffs.");
	get_user_continue();
}

DictItem scrap_menu_dictitems[] = {
	{"M_Generator", M_Generator},
	{"M_Inverter", M_Inverter},
	{"M_QuadrupleNegative", M_QuadrupleNegative},
	{"M_DoublePositive,", M_DoublePositive},
	{"M_PlusOne", M_PlusOne},
	{"M_MinusThree", M_MinusThree},
	{"M_Out", M_Out}
};
Dict scrap_menu_dict = {
	scrap_menu_dictitems,
	ARRAY_COUNT(scrap_menu_dictitems),
};

void spend_scrap(Config* cfg) {
	char* scrap_menu_options[M_Out];

	for (int i = 0; i < M_Out; i++) {

	}

	display_divider();
	display_message(DM_Prompt, "what would you like to do? [ scrap: %d | product: %d ]", cfg->scrap, cfg->product);

}


char* product_menu_options[] = {
	"spend your SCRAP",
	"spend your PRODUCT",
	"tutorial",
	"back"
};

void spend_product(Config* cfg) {
	display_message(DM_Emphasis, "im buygn somethin product");

}


char* SHOP_menu_options[] = {
	"spend your SCRAP",
	"spend your PRODUCT",
	"tutorial",
	"back"
};

void SHOP_menu(Config* cfg) {
	while (1) {
		display_message(DM_Emphasis, "entered the shop");
		display_divider();
		display_message(DM_Prompt, "what would you like to do? [ scrap: %d | product: %d ]", cfg->scrap, cfg->product);

		int choice = get_user_choice(&SHOP_menu_options, ARRAY_COUNT(SHOP_menu_options));

		switch (choice) {
			case 0:
				spend_scrap(cfg);
				break;
			case 1:
				spend_product(cfg);
				break;
			case 2:
				SHOP_tutorial();
				break;
			case 3:
				return;
			default:
				break;
		}
	}
}