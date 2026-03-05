/*
 * Name: Ian Seymour
 * File: seymour_libFS.c
 *
 * Functions for libFS with file creation, writing,
 * opening, deleting, and closing.
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "seymour_libFS.h"

/*
 * createFile
 * input: string filename
 *
 * Creates a file with the sepecified name.
 */
void createFile(const char* filename) {
	FILE* file = fopen(filename, "w");

	if (file) {
		printf("File '%s' created.\n", filename);
		fclose(file);
	} else {
		printf("ERROR: File could not be created.\n");
	}
}

/*
 * writeFile
 * input: file pointer, string data
 *
 * Writes data to file.
 */
void writeFile(FILE* file, const char* data) {
	if (file) {
		fprintf(file, "%s", data);
		printf("File has been written to successfully.\n");
	} else {
		printf("ERROR: Invalid file pointer. Ensure file is open.\n");
	}
}

/*
 * closeFile
 * input: file pointer
 *
 * Closes a file.
 */
void closeFile(FILE* file) {
	if (file) {
		fclose(file);
		printf("File closed.\n");
	}
}

/*
 * openFile
 * input: string filename, string mode
 * output: file pointer
 *
 * Opens file with specified name in specified mode.
 */
FILE* openFile(const char* filename, const char* mode) {
	FILE* file = fopen(filename, mode);
	if (file) {
		printf("File '%s' opened with '%s' mode.\n", filename, mode);
		return file;
	}
	printf("ERROR: File '%s' could not be opened.\n", filename);

	return NULL;
}

/*
 * readFile
 * input: file pointer
 *
 * Reads file to buffer, then prints the buffer,
 * then repeats this until EOF.
 */
void readFile(FILE* file) {
	if (file) {
		char buffer[256];

		printf("\nReading File:\n");

		while (fgets(buffer, sizeof(buffer), file) != NULL) {
			printf("%s", buffer);
		}

		printf("\nEnd File Contents\n");
	} else{
		printf("ERROR: Invalid file pointer. Ensure file is open.\n");
	}
}

/*
 * removeFile
 * input: string filename
 *
 * Removes file with specified name.
 */
void removeFile(const char* filename) {
	if(remove(filename) == 0) {
		printf("File '%s' removed.\n", filename);
	} else {
		printf("ERROR: Unable to delete file '%s'.\n", filename);
	}
}
