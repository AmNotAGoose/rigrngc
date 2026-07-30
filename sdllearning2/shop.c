#include <stdlib.h>
#include <string.h>

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


const int module_to_cost(Module _module) {
	switch (_module) {
	case M_None: return 0;
	case M_Generator: return 0;
	case M_Inverter: return 50;
	case M_QuadrupleNegative: return 60;
	case M_DoublePositive: return 60;
	case M_PlusOne: return 20;
	case M_MinusThree: return 20;
	case M_Out: return 0;
	}
}

DictItem scrap_menu_dictitems[] = {
	//{"Generator", M_Generator},
	{"Inverter", M_Inverter},
	{"QuadrupleNegative", M_QuadrupleNegative},
	{"DoublePositive,", M_DoublePositive},
	{"PlusOne", M_PlusOne},
	{"MinusThree", M_MinusThree},
	//{"Out", M_Out}
};
Dict scrap_menu_dict = {
	scrap_menu_dictitems,
	ARRAY_COUNT(scrap_menu_dictitems),
};

bool add_module_to_inv(Config* cfg, char* module_key) {
	for (int i = 0; i < 6; i++) {
		if (strcmp(cfg->modules[i], "None") == 0) {
			cfg->modules[i] = module_key;
			return true;
		}
	}
	return false;
}

void spend_scrap(Config* cfg) {
	char** scrap_menu_keys = get_keys(&scrap_menu_dict);

	display_divider();
	display_message(DM_Prompt, "what would you like to do? [ scrap: %d | product: %d ]", cfg->scrap, cfg->product);

	int choice = get_user_choice(scrap_menu_keys, scrap_menu_dict.count);

	DictItem* choice_item = &scrap_menu_dictitems[choice];
	int choice_cost = module_to_cost(choice_item->value);

	if (!(cfg->scrap >= choice_cost)) {
		display_message(DM_Emphasis, "you dont have enough! you need %d SCRAP for this.", choice_cost);
		return;
	}

	if (add_module_to_inv(cfg, choice_item->key)) {
		display_message(DM_Emphasis, "successfully purchased");
		cfg->scrap -= choice_cost;
		config_save(cfg);
		return;
	}

	display_message(DM_Emphasis, "out of space!");
	return;
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