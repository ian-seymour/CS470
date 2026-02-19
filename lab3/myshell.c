#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <unistd.h>
#include <string.h>
#include <sys/wait.h>
#include <ctype.h>
#include <fcntl.h>

#define MAX_LENGTH 1000
#define MAX_ARGS 50

// Command structure:
typedef struct {
	char *args[MAX_ARGS];
	char *inputFile;
	char *outputFile;
	char *appendFile;
} Command;

// Function declarations:
void displayPrompt();
int getInput(char *line);
int parseCommand(char *line, Command *cmd);
int processCommand(Command *cmd);
void externCommand(Command *cmd);
void redirection(Command *cmd);

int main() {
	char line[MAX_LENGTH];
	Command cmd;

	while (true) {
		// if end of file (ctrl d)
		if (!getInput(line)) break;

		parseCommand(line, &cmd);

		if (processCommand(&cmd) == 0) {
			break;
		}
	}

	return 0;
}

/*
 * displayPrompt
 *
 * Displays prompt to user, clears buffer so prompt is
 * immediately dispalyed at all times.
 */
void displayPrompt() {
	printf("> ");
	fflush(stdout);
}

/*
 * getInput
 *
 * Input: char pointer to start of command
 * Output: flag to continue or end main
 *
 * Cleans the return from commands or ends
 * main if ctrl d is entered.
 */
int getInput(char *line) {
	displayPrompt();

	if (fgets(line, MAX_LENGTH, stdin) == NULL) {
		printf("\n");
		return 0;
	}

	line[strcspn(line, "\n")] = 0;

	return 1;
}

/*
 * parseCommand
 *
 * Input: char pointer to start of command, command struct
 * Output: flag to continue or end main
 *
 * Tokenizes commands entered by user and handles various
 * cases (like quotes) and handles redirect commands.
 */
int parseCommand(char *line, Command *cmd) {
	// reset cmd struct
	cmd->inputFile = NULL;
	cmd->outputFile = NULL;
	cmd->appendFile = NULL;
	
	int argCount = 0;

	char *ptr = line;

	while (*ptr) {
		while (isspace(*ptr)) ptr++;
		if (*ptr == '\0') break;

		// check for redirection command
		if (strncmp(ptr, ">>", 2) == 0) {
			ptr += 2;
			while (isspace(*ptr)) ptr++;

			char *start = ptr;

			while (*ptr && !isspace(*ptr)) ptr++;

			if (ptr != start) {
				char temp = *ptr;

				// null terminate file
				*ptr = '\0';
				cmd->appendFile = start;
				if (temp != '\0') ptr++;
			}

			continue;
		}

		if (*ptr == '>') {
			ptr++;

			while (isspace(*ptr)) ptr++;

			char *start = ptr;

			while (*ptr && !isspace(*ptr)) ptr++;

			if (ptr != start) {
				char temp = *ptr;

				*ptr = '\0';

				cmd->outputFile = start;

				if (temp != '\0') ptr++;
			}

			continue;
		}

		if (*ptr == '<') {
			ptr++;

			while (isspace(*ptr)) ptr++;
			
			char *start = ptr;

			while (*ptr && !isspace(*ptr)) ptr++;

			if (ptr != start) {
				char temp = *ptr;

				*ptr = '\0';

				cmd->inputFile = start;

				if (temp != '\0') ptr++;
			}

			continue;
		}

		// handle quotes
		if (*ptr == '"') {
			ptr++; // move past first quote
			cmd->args[argCount++] = ptr;

			while (*ptr && *ptr != '"') ptr++;

			if (*ptr == '"') {
				char temp = *ptr;

				*ptr = '\0'; // null terminate

				if (temp != '\0') ptr++;
			}
		}

		// regular commands
		else {
			cmd->args[argCount++] = ptr;
			while (*ptr && !isspace(*ptr)) ptr++;

			if (*ptr) {
				char temp = *ptr;

				*ptr = '\0'; //null terminate

				if (temp != '\0') ptr++;
			}
		}

		if (argCount >= MAX_ARGS -1) break;
	}

	// null terminate for execvp
	cmd->args[argCount] = NULL;
	return 0;
}

/*
 * processCommand
 * 
 * Input: Command struct
 * Output: flag to continue or end main
 *
 * Takes parsed command and determines action, internally handles
 * exit and cd, then will use external commands for the rest.
 */
int processCommand(Command *cmd) {
	// check for empty command
	if (cmd->args[0] == NULL) {
		return 1;
	}

	// if exit
	if (strcmp(cmd->args[0], "exit") == 0) {
		return 0;
	}

	// cd
	if (strcmp(cmd->args[0], "cd") == 0) {
		char *targetDirectory = cmd->args[1];

		if (targetDirectory == NULL) {
			targetDirectory = getenv("HOME");

			if (targetDirectory == NULL) {
				fprintf(stderr, "cd: HOME environment variable not set or available\n");
				return 1;
			}
		}
			
		if (chdir(targetDirectory) != 0) {
			perror("cd: failed");
		}

		return 1; // continue
	}

	// external commands
	externCommand(cmd);
	return 1; // continue
}

/*
 * externCommand
 *
 * Input: Command struct
 *
 * Uses fork and execvp to create processes for commands.
 */
void externCommand(Command *cmd) {
	pid_t pid = fork();

	if (pid < 0) {
		perror("Fork failed");
		return;
	}

	if (pid == 0) {
		redirection(cmd);
		
		execvp(cmd->args[0], cmd->args);
		perror("Command failed");
		exit(1);

	} else {
		wait(NULL);
	}
}

/*
 * redirection
 *
 * Input: Command struct
 *
 * Handles file inputs for redirection commands.
 */
void redirection(Command *cmd) {
	// "<" input
	if (cmd->inputFile) {
		int fd = open(cmd->inputFile, O_RDONLY);

		if (fd < 0) {
			perror("redirect: error opening input file");
			exit(1);
		}

		dup2(fd, STDIN_FILENO);
		close(fd);
	}

	// ">" output
	if (cmd->outputFile) {
		int fd = open(cmd->outputFile, O_WRONLY | O_CREAT | O_TRUNC, 0644);

		if (fd < 0) {
			perror("redirect: error opening output file");
			exit(1);
		}

		dup2(fd, STDOUT_FILENO);
		close(fd);
	}

	// ">>" append
	if (cmd->appendFile) {
		int fd = open(cmd->appendFile, O_WRONLY | O_CREAT | O_APPEND, 0644);

		if (fd < 0) {
			perror("redirect: error opening append file");
			exit(1);
		}

		dup2(fd, STDOUT_FILENO);
		close(fd);
	}
}

