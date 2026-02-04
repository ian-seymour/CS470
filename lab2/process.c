/*
 * Name: Ian Seymour
 * File: process.c
 *
 * Program to create a parent process and 15 child processes
 * to execute various Bash commands while logging exit codes
 * and signal terminations.
 *
 */

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>
#include <sys/types.h>

#define MAX_CHILDREN 15

int main () {

	pid_t child_pids[MAX_CHILDREN];

	char *commands[MAX_CHILDREN] = {
		"ls", "pwd", "date", "whoami", "hostname",
		"id", "df", "ps", "uptime", "uname"
	};

	//Counters
	int normal_zeros = 0;
	int normal_nonzeros = 0;
	int sig_terms = 0;

	printf("New Parent Process ID: %d\n", getpid());

	// Loop to create child processes (including the mandatory ones):
	for (int i = 0; i < MAX_CHILDREN; i++) {
		pid_t pid = fork();

		if (pid < 0) {
			printf("Fork failed.");
			exit(1);
		} else if (pid == 0) {
			if (i == 0) { 
				printf("CHILD %d PID %d executing: %s\n", i + 1, getpid(), commands[i]);
				char *args[] = {"echo", "Hello Ian Seymour", NULL};
				execvp(args[0], args);
			
			} else if (i == 1 || i == 2) {
				printf("CHILD %d PID %d executing: %s\n", i + 1, getpid(), commands[i]);
				char *args[] = {"wrong_command", NULL};
				execvp(args[0], args);
				printf("execvp failed");

				exit(127);
			
			} else if (i == 3 || i ==4) {
				printf("CHILD %d PID %d executing: %s\n", i + 1, getpid(), commands[i]);
				printf("Aborting with Signal Termination...");
				abort();
			
			} else {
				// prevents out of bounds
				int index = (i - 5) % 10;
				
				printf("CHILD %d PID %d executing: %s\n", i + 1, getpid(), commands[index]);

				// execute command
				char *args[] = {commands[index], NULL};
				execvp(args[0], args);
			}

			// fallback
			exit(1);
		} else {
			// record pid
			child_pids[i] = pid;
		}
	}

	// wait for all children
	for (int i = 0; i < MAX_CHILDREN; i++) {
		int status;
		
		waitpid(child_pids[i], &status, 0);

		if (WIFEXITED(status)) {
			printf("Child %d PID %d exited with status: %d\n", i, child_pids[i], WEXITSTATUS(status));
			int exit_code = WEXITSTATUS(status);

			if (exit_code == 0) normal_zeros++;
			else normal_nonzeros++;

		} else if (WIFSIGNALED(status)) {
			printf("Child %d PID %d killed by signal: %d\n", i, child_pids[i], WTERMSIG(status));

			sig_terms++;
		}
	}

	printf("--SUMMARY--\n");
	printf("Normal exits: %d\n", normal_zeros);
	printf("Normal non-zero exits: %d\n", normal_nonzeros);
	printf("Signal terminations: %d\n", sig_terms);

	return 0;
}
