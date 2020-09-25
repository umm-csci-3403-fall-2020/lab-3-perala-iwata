#include "array_merge.h"
#include "../mergesort/mergesort.h"
#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>

int* array_merge(int num_arrays, int* sizes, int** values) {
	
	// Variable used to see how many total elements there are in all sub-arrays
	int* combArray
	
	// Index to count
	int i = 0;

	// While loop to add the sum of elements in the original arrays
	while (i < num_arrays){
		combArray = combArray + size[i];
		i++;
	}
	
	// Array to hold the unique values of the subarrays
	int *altArray = (int*) calloc(combArray, sizeof(int));
	
	int index = 0;

	for(int i = 0; i < num_arrays; i++){
		for(int j = 0; j < sizes[i]; j++){
			combArray[index] = values[j][i];
			index++;
		}
	}

	// Sorting the array to find unique numbers
	mergesort(combArray, altArray);
	
	// Counter for unique values
	int unique = 0;

	// Iterator for the while loop
	int j = 0;

	while(j < combArray) {
		if(altArray[i] != altArray[i - 1]){
			unique++;
		}
	}

	// Final array to hold the unique values as well as the count of unique values
	int* finalArray = (int*) calloc(unique+1, sizeof(int));

	// Adding the value of unique numbers to the first position in the array
	finalArray[0] = unique;

	for(int k = 1; i < combArray; i++) {
		if (combArray[i] != combArray[i-1]){
			finalArray[k] = altArray[k];
		}
	}
	free(combArray);
  return finalArray;
}

/* What to do next:
Fill the forloop on line 24 to fill the altArray with unique values.
Sort the array
Create a new array with space in the beginning to hold the count for the number of unique values.
Set the new array at index 0 to be the value of the unique values.
Fill the new array with the unique values starting at posistion one.
Be sure to free the new array.
Return the finalized sorted array.
Done?
