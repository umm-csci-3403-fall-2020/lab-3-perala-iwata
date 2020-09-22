#include "array_merge.h"


bool needsSorting(int rangeSize);
void mergeSortRange(int values[], int startIndex, int endIndex);
void mergeRanges(int values[], int size, int startIndex, int midPoint, int endIndex);


int* array_merge(int num_arrays, int* sizes, int** values) {
  // This is obviously broken. It has the right type, though, eh?
  return sizes;
}

void mergesort(int size, int values[]) {  
	mergeSortRange(values, 0, size);
}

void mergeRanges(int values[], int size, int startIndex, int midPoint, int endIndex) {
	int rangeSize = endIndex - startIndex;
	int* destination;
	destination = (int*) calloc(size + 1, sizeof(int));
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
