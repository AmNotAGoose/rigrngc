#include <stdio.h>
#include <stdarg.h>
#include <stdlib.h>

#include "display.h";

int display_message(DisplayMode display_mode, const char* message, ...) {
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
		default:
			break;
	}

	printf(prefill);
	vprintf(message, args);
	printf(postfill);
	
	va_end(args);

	return 1;
}

int get_user_input(const char* prompt, char* buffer, size_t buffer_size) {
	
	return 1;
}


int get_user_choice(const char* prompt, Choices choices) {
	return 0;
}
