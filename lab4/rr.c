/*
 * Author: Ian Seymour
 * File: rr.c
 *
 * Program to simulate a round-robin process scheduler.
 */

#include <stdio.h>
#include <stdbool.h>
#include "process.h"

int main() {
	int n;
	int quantum;
	int completed = 0;
	int currTime = 0;

	// set the array size reasonably high
	int execOrder[10000];
	int execCount = 0;

	// get num of processes
	printf("-- Round Robin Scheduling --\n");
	printf("Enter number of processes: ");
	scanf("%d", &n);

	// create process array
	Process proc[n];

	// get arrival and burst times
	for (int i = 0; i < n; i++) {
		proc[i].id = i + 1;
		printf("Proc. %d -- Enter [Arrival] [Burst] (as two integers separated by a space, e.g. 0 1): ", i + 1);
		scanf("%d %d", &proc[i].arrivalTime, &proc[i].burstTime);

		proc[i].remainderTime = proc[i].burstTime;
	}

	// get quantum
	printf("Enter quantum: ");
	scanf("%d", &quantum);

	// queue logic
	while (completed < n) {
		bool idle = true;

		for (int i = 0; i < n; i++) {
			// check process arrived and its status
			if (proc[i].arrivalTime <= currTime && proc[i].remainderTime > 0) {
				idle = false;

				// log exec order
				execOrder[execCount++] = proc[i].id;

				if (proc[i].remainderTime > quantum) {
					currTime += quantum;
					proc[i].remainderTime -= quantum;
				} else {
					// process finishes
					currTime += proc[i].remainderTime;
					proc[i].remainderTime = 0;
					completed++;

					// compute  metrics
					proc[i].turnaroundTime = currTime - proc[i].arrivalTime;
					proc[i].waitTime = proc[i].turnaroundTime - proc[i].burstTime;
				}
			}
		}

		// advance time
		if (idle) currTime++;
	}

	printf("\nExecution Order:\n");

	for (int i = 0; i < execCount; i++) {
		printf("Proc. %d \n", execOrder[i]);
	}
	printf("\n");

	displayInfo(proc, n);

	return 0;
}

