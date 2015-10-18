/* Program for Bubble sort 
   Written by: ROHIT DESHPANDE
   date: 10/18/2015
*/

#include <stdio.h>

#define SIZE(arr)	(sizeof(arr)/sizeof(arr[1]))		//Macro for returning size of array //
  
int main(){  
  int i_index = 0, size_of=0, j_index = 0, y=0;
	int array[] = {77,44,33,55,22,11};
	size_of = SIZE(array);										//size of array from a macro
	printf("Size of array is: %d elements \n",size_of);					// print the size of array
	printf("Original array: \n");
	for (i_index = 0;i_index<size_of;i_index++){				// print whole array
		printf("array[%d]:%d | ", i_index,array[i_index]);		// print the given array
	}
	printf("\n");
	
	for(j_index=0, y=4;j_index<6;j_index++,y--){			// for bubble sort
		for(i_index = 0; i_index<=y; i_index++){
			if(array[i_index]>array[i_index+1]){	// swap if next is greater that first one
				array[i_index] = array[i_index]+array[i_index+1];		// Step 1
				array[i_index+1] = array[i_index]-array[i_index+1];	// Step 2
				array[i_index] = array[i_index]-array[i_index+1];		// Step 3
			}
		}
	}
	printf("Sorted array: \n");
	for (i_index = 0;i_index<size_of;i_index++){
		printf("array[%d]:%d | ", i_index,array[i_index]);
	}
	return 0;
}
