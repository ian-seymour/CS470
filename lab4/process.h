/* Author: Ian Seymour
 * proccess.h
 *
 * Header file to establish process structure
 * and to provide a function to display info.
 */

#ifndef PROCESS_H
#define PROCESS_H
#include <stdio.h>

typedef struct {
	int id;
	int arrivalTime;
	int burstTime;
	int remainderTime;
	int waitTime;
	int turnaroundTime;
	int completionTime;
} Process;

/*
 * displayInfo
 * input: process array, int n number of processes
 *
 * Displays metrics after each scheduler simulation is complete.
 */
static void displayInfo(Process proc[], int n) {
	float totalWait = 0;
	float totalTurn = 0;

	printf("\n%-7s %-7s %-7s %-7s %-7s\n", "ID", "Arrival", "Burst", "Wait", "Turn");
	printf("----------------------------------------\n");

	for (int i = 0; i < n; i++) {
		totalWait += proc[i].waitTime;
		totalTurn += proc[i].turnaroundTime;

		printf("%-7d %-7d %-7d %-7d %-7d\n", proc[i].id, proc[i].arrivalTime, proc[i].burstTime,
				proc[i].waitTime, proc[i].turnaroundTime);
	}
	printf("\nAverage Wait Time: %.2f", totalWait / n);
	printf("\nAverage Turnaround Time: %.2f", totalTurn / n);
}

#endif
