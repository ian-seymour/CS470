/*
 * Name: Ian Seymour
 * File: seymour_testlibFS.c
 *
 * Program to test libFS functionality with a command
 * line menu and UI.
 */

#include <stdio.h>
#include <string.h>
#include "seymour_libFS.h"

// constants for test file
#define FILENAME "seymour_introduction.txt"

const char* INTRO = "I'm Ian Seymour. I'm from Mill A, Washington."
        "I work as a data scientist. Do photography and videography for fun.\n\n"
        "I like going to metal concerts and playing guitar as well. I've lived"
        "all over the U.S. and spent a year abroad between Germany, France, Italy,"
        "Greece, Poland, and Lithuania.\n";

/*
 * menu
 *
 * Displays menu options.
 */
void menu() {
	printf("\nMenu Commands:\n");
	printf(" create - Create demo file.\n");
	printf(" open-w - Opens file with write option\n");
	printf(" open-r - Opens file with read option\n");
	printf(" close - Close file.\n");
	printf(" read - Prints file contents\n");
	printf(" write - Writes demo data to file\n");
	printf(" remove - Removes file.\n");
	printf(" help - Display available commands\n");
	printf(" exit - Exits demo program\n");
}

int main () {
	char input[64];
	FILE* currFile = NULL;

	printf("Welcome to the libFS Demo\n");
	printf("Type 'help' to see available commands.\n");

	// loop to run program
	while (1) {
		// get user input from prompt
		printf("\nlibFS> ");
		if (scanf("%63s", input) != 1) break;

		if (strcmp(input, "help") == 0) {
			menu();
		}

		else if (strcmp(input, "create") == 0) {
			createFile(FILENAME);
		}

		else if (strcmp(input, "open-w") == 0) {
			currFile = openFile(FILENAME, "w");
		}

		else if (strcmp(input, "open-r") == 0) {
			currFile = openFile(FILENAME, "r");
		}

		else if (strcmp(input, "close") == 0) {
			closeFile(currFile);
			currFile = NULL;
		}

		else if (strcmp(input, "read") == 0) {
			if (currFile) readFile(currFile);
			else printf("ERROR: No file open. Ensure a file is open.\n");
		}

		else if (strcmp(input, "write") == 0) {
			if (currFile) writeFile(currFile, INTRO);
			else printf("ERROR: No file open. Ensure a file is open.\n");
		}

		else if (strcmp(input, "remove") == 0) {
			removeFile(FILENAME);
		}

		else if (strcmp(input, "exit") == 0) {
			if (currFile) closeFile(currFile);
			printf("Exiting libFS Demo...\n");
			break;
		}

		else {
			printf("Unknown command: %s. Use 'help' for available commands.\n", input);
		}
	}

	return 0;
}
