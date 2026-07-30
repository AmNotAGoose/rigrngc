#include <stdio.h>
#include <stdarg.h>
#include <stdlib.h>
#include <string.h>

#include "display.h";

bool display_divider() {
	printf("---------------\n");
	return true;
}

bool display_message(DisplayMode display_mode, const char* message, ...) {
	va_list args;
	va_start(args, message);
	
	//size_t fmessage_size = 512 * sizeof(char);
	//char* fmessage = malloc(fmessage_size);

	//vsnprintf(fmessage, fmessage_size, message, args);

	const char* prefill = "";
	const char* postfill = "";
	
	switch (display_mode) {
		case DM_Emphasis:
			prefill = "[ ";
			postfill = " ]\n";
			break;
		case DM_Section:
			prefill = "---------------\n";
			postfill = "\n---------------\n";
			break;
		case DM_Prompt:
			prefill = "-> ";
			postfill = "\n";
			break;
		case DM_Choice:
			prefill = "    ";
			postfill = "\n";
			break;
		default:
			postfill = "\n";
			break;
	}

	printf(prefill);
	vprintf(message, args);
	printf(postfill);
	
	va_end(args);

	return true;
}

bool get_user_input(char* buffer, size_t buffer_size) {
	printf("YOUR INPUT: ");
	fgets(buffer, buffer_size, stdin);
	return true;
}

int get_user_choice(char** choices, size_t count) {
	int choice;

	while (1) {
		for (int i = 0; i < count; i++) {
			display_message(DM_Choice, "[%d] %s", i, choices[i]);
		}

		char input[32];
		get_user_input(input, 32);
		input[strcspn(input, "\n")] = '\0';

		char* last_char;
		choice = (int)strtol(input, &last_char, 10);

		if (*last_char == '\0' && 0 <= choice && choice < count) {
			break;
		}

		display_message(DM_None, "that's not a valid choice. try again.");
	}

	display_message(DM_Emphasis, "saved");
	return choice;
}
