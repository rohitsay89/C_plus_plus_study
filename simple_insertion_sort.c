
#include <stdio.h>
#include <stdlib.h>

void insertionSort(int ar_size, int *ar){
    int i=0, j=0;						// define loop variables
	int v = ar[ar_size-1];				// store element in right most position in a variable
	int n = ar_size-1;					// store size of array in an other variable
	for(i=0;i<ar_size;i++,n--){			// loop for insertion sort till from 0 to < array size
		if(ar[n-1]>v){					// if the n-1th element is greater than v then 
			ar[n]=ar[n-1];				// copy the left element to the right cell
			for(j=0;j<ar_size;j++){		// print the array after copy operation
				printf("%d ",ar[j]);
			}
		}
		if(ar[n-1]<v){					// if n-1th element it is greater than v
			ar[n]=v;					// copy v at the n-1th location
			for(j=0;j<ar_size;j++){		// print the array
				printf("%d ",ar[j]);
			}
			return;						// exit the program
		}
		printf("\n");
	}

}
int main(void) {
   
	int _ar_size;
    scanf("%d", &_ar_size);
    int _ar[_ar_size], _ar_i;
    for(_ar_i = 0; _ar_i < _ar_size; _ar_i++) { 
        scanf("%d", &_ar[_ar_i]); 
    }

    insertionSort(_ar_size, _ar);
   
    return 0;
}
