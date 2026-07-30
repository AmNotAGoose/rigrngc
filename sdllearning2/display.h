#ifndef DISPLAY_H
#define DISPLAY_H

#include <stddef.h>
#include <stdbool.h>

typedef struct {
	char** data;
	size_t count;
} Choices;

typedef enum {
	DM_None,
	DM_Emphasis,
	DM_Section,
	DM_Prompt,
	DM_Choice
} DisplayMode;

int display_message(DisplayMode display_mode, const char* message, ...);

int get_user_input(char* buffer, size_t buffer_size);
int get_user_choice(Choices choices);


#endif