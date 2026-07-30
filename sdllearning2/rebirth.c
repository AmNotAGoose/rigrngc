#include "rebirth.h"
#include "display.h"
#include "common.h"
#include "config.h"
#include "scrapyard.h"

char* REBIRTH_choices[] = {
	"yes",
	"no"
};

void REBIRTH_menu(Config* cfg) {
	display_divider();
	display_message(DM_Emphasis, "PRODUCT: %d", cfg->product);
	display_message(DM_Emphasis, "To REBIRTH, you must have at least %d PRODUCT.", cfg->rebirth_product);
	display_message(DM_Emphasis, "REBIRTH clears all your SCRAP, PRODUCT, and MODULES");
	display_message(DM_Emphasis, "Your Generators produce the amount of REBIRTHs + 1 (if your LUCKY, you may get a double REBIRTH!)");
	display_message(DM_Emphasis, "Do you wish to REBIRTH?");

	int choice = get_user_choice(REBIRTH_choices, ARRAY_COUNT(REBIRTH_choices));

	if (choice == 0) {
		if (cfg->product < cfg->rebirth_product) {
			display_message(DM_Emphasis, "You do not have enough PRODUCT.");
			return;
		}

		display_divider();
		display_message(DM_Emphasis, "REBIRTH: rolling dice");
		int score = roll_dice(6) + roll_dice(6) + roll_dice(12) * 0.1 * cfg->luck;
		if (score > 12) {
			display_message(DM_Emphasis, "REBIRTH: you are LUCKY. +2 REBIRTH");
			cfg->rebirths += 2;
		}
		else {
			display_message(DM_Emphasis, "REBIRTH: +1 REBIRTH");
			cfg->rebirths += 1;
		}

		cfg->rebirth_product += (int)(cfg->rebirth_product * (roll_dice(6) / 3));

		display_message(DM_Emphasis, "REBIRTH: next REBIRTH threshold is %d PRODUCT", cfg->rebirth_product);

		cfg->scrap = 0;
		cfg->product = 0;

		for (int i = 0; i < 6; i++) {
			strcpy(cfg->modules[i], "None");
		}

		display_message(DM_Emphasis, "REBIRTH: REBIRTH complete.");
	}

	return;
}