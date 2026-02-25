/*
 * Author: Ian Seymour
 * File: sjf.c
 *
 * Program to simulate SJF scheduler.
 */

#include <stdio.h>
#include <stdbool.h>
#include "process.h"
#include <limits.h>

int main() {
	int n;
	int completed = 0;
	int currTime = 0;

	// get num processes
	printf("-- SJF Scheduling --\n");
	printf("Enter number of processes: ");
	scanf("%d", &n);

	// create process array
	Process proc[n];

	bool isCompleted[n];
	int execOrder[n];

	// get arrival and burst times
	for (int i = 0; i < n; i++) {
		proc[i].id = i + 1;
		printf("Proc. %d -- Enter [Arrival Time] [Burst Time] (two integers separated by a space, e.g. 0 1): ", i + 1);
		scanf("%d %d", &proc[i].arrivalTime, &proc[i].burstTime);
		isCompleted[i] = false;
	}

	while (completed < n) {
		int index = -1;
		int minBurst = INT_MAX;

		for (int i = 0; i < n; i++) {
			// check if proc arrived and is not complete yet
			if (proc[i].arrivalTime <= currTime && !isCompleted[i]) {
				if (proc[i].burstTime < minBurst) {
					minBurst = proc[i].burstTime;
					index = i;
				}
			}
		}

		if (index != -1) {
			// execute process
			execOrder[completed] = proc[index].id;
			proc[index].waitTime = currTime - proc[index].arrivalTime;
			currTime += proc[index].burstTime;
			proc[index].turnaroundTime = proc[index].waitTime + proc[index].burstTime;
			isCompleted[index] = true;
			completed++;
		} else {
			// nothing ready, advanced time
			currTime++;
		}
	}

	printf("\nExecution Order:\n");

	for (int i = 0; i < n; i++) {
		printf("Proc. %d\n", execOrder[i]);
	}
	printf("\n");

	displayInfo(proc, n);

	return 0;
}
