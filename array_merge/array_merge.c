#include "array_merge.h"
#include "../mergesort/mergesort.h"
#include "../mergesort/mergesort.c"
#include <stdlib.h>
#include <stdio.h>

int* array_merge(int num_arrays, int* sizes, int** values) {
	
	// Variable used to see how many total elements there are in all sub-arrays
	int arrSize = 0;
	
	// While loop to add the sum of elements in the original arrays
	for (int i = 0; i < num_arrays; i++) {
		arrSize = arrSize + sizes[i];
	}
	
	// Array to hold the unique values of the subarrays
	int *altArray = (int*) calloc(arrSize, sizeof(int));
	
	int index = 0;

	for (int i = 0; i < num_arrays; i++){
		for(int j = 0; j < sizes[i]; j++){
			altArray[index] = values[i][j];
			index++;
		}
	}

	// Sorting the array to find unique numbers
	mergesort(arrSize, altArray);
	
	// Counter for unique values
	int unique = 0;

	if (num_arrays != 0) {
		unique = 1;
	}else{
		unique = 0;
	}

	for (int i = 0; i < arrSize; i++) {
		if(altArray[i] != altArray[i - 1]){
			unique++;
		}
	}

	// Final array to hold the unique values as well as the count of unique values
	int* finalArray = (int*) calloc(unique+1, sizeof(int));

	// Adding the value of unique numbers to the first position in the array
	finalArray[0] = unique;

	for(int i = 1; i < arrSize; i++) {
		if (altArray[i] != altArray[i-1]){
			finalArray[i] = altArray[i];
		}
	}
  free(altArray);
  return finalArray;
}
