/*
 * Author: Ian Seymour
 * File: address.c
 *
 * Program to translate logical addresses to physical addresses,
 * and to compute the offset, frame num, and page num.
 */

#include <stdio.h>

#define NUM_PAGES 4
#define PAGE 1024

int main() {
	// page table with frame mapping
	int pageTable[NUM_PAGES] = {5, 2, 9, 1};

	int numAddresses;
	int logAddress;

	printf("Enter number of logical addresses (N): \n");
	if (scanf("%d", &numAddresses) != 1) {
		printf("Must enter num of logical addresses.");
		return 1;
	}

	printf("Enter logical address(es), one per line: \n");

	for (int i = 0; i < numAddresses; i++) {
		if (scanf("%d", &logAddress) != 1) {
			break;
		}

		// calculate page num/offset
		int pageNum = logAddress / PAGE;
		int offset = logAddress % PAGE;

		// check if page num are within max num of pages
		if (pageNum < 0 || pageNum >= NUM_PAGES) {
			printf("Logical: %d | INVALID (page out of range)\n", logAddress);
		} else {
			// check frame num and calculate physical address
			int frameNum = pageTable[pageNum];
			int physicalAddress = (frameNum * PAGE) + offset;

			// print translation
			printf("Logical: %d | Page: %d | Offset: %d | Frame: %d | Physical: %d\n",
					logAddress, pageNum, offset, frameNum, physicalAddress);
		}
	}

	return 0;
}
