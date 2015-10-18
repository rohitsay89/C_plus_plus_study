/* Program for Selection sort 
   Written by: ROHIT DESHPANDE
   date: 10/18/2015
*/

#include <stdio.h>

#define SIZE(arr)	(sizeof(arr)/sizeof(arr[1]))		            /* Macro for returning size of array */

int main(){
  int i_index = 0, size_of=0, j_index = 0, y=0;
	int array[] = {77,44,33,55,22,11};
	size_of = SIZE(array);                                      /* size of array from a macro */
	printf("Size of array is: %d elements \n",size_of);					/* print the size of array */
	printf("Original array: \n");
	for (i_index = 0;i_index<size_of;i_index++){				        /* print whole array */
		printf("array[%d]:%d | ", i_index,array[i_index]);        /* print the given array */
	}
	printf("\n");

	for(y = 0, i_index = 0;y<size_of; y++,i_index++){           /* start selection sorting */ 
		for(j_index=i_index+1;j_index<size_of;j_index++){
			if(array[i_index]>array[j_index]){					            /* Swap two variables without using 3rd */
				array[i_index] = array[i_index]+array[j_index];       /* Step 1 */
				array[j_index] = array[i_index]-array[j_index];	      /* Step 2 */
				array[i_index] = array[i_index]-array[j_index];	      /* Step 3 */
			}
		}
	}
	printf("Sorted array: \n");
	for (i_index = 0;i_index<size_of;i_index++){
		printf("array[%d]:%d | ", i_index,array[i_index]);
	}
	
	return 0;
}
