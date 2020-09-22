#include "mergesort.h"
#include <stdlib.h>

void mergesort(int, int*) {  

	return;
}

void mergeSortRange (int values[], int startIndex, int endIndex) {
	bool needToSort = needsSorting(rangeSize);
	if (needSort == true) {
		int midPoint = (startIndex + endIndex)/2;
		mergeSortRange(values, startIndex, endIndex);
		mergeSortRange(values, midPoint, endIndex);
		mergeRanges(values, startIndex, midPoint, endIndex);
	}
}

void mergeRanges(int values[], int size, int startIndex, int midPoint, int endIndex) {
	int rangeSize = endIndex - startIndex;
	int* destination;
	destination = (int*) malloc(size + 1, sizeof(int));
	int firstIndex = startIndex;
	int secondIndex = midPoint;
	int copyIndex = 0;
	
	while (firstIndex < midPoint && secondIndex < endIndex) {
		if (values[firstIndex] < values[secondIndex]) {
			destination[copyIndex] = values[firstIndex];
			firstIndex++;
		}else{
			destination[copyIndex] = values[secondIndex];
			secondIndex++;
		}
		copyIndex++;
	}

	while (firstIndex < midPoint) {
		destination[copyIndex] = values[firstIndex];
		copyIndex++;
		firstIndex++;
	}

	while (secondIndex < endIndex) {
		destination[copyIndex] = values[secondIndex];
		copyIndex++;
		secondIndex++;
	}

	for (int i = 0; i < rangeSize; i++) {
		values[i + startIndex] = destination[i];
	}
	free(destination);
}

bool needsSorting (int rangeSize) {
	if (rangeSize >= 2) {
		return  true;
	}else{
		return false;
	}
}


