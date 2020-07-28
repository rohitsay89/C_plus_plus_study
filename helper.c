#include <stdio.h>
#include <stdlib.h>

#include "main.h"

/* ARRAY SUM */
int array_sum(){
    printf("This is function for adding contents of an array\n");
    int n = 0;
    int sum = 0;
    int i = 0;
    printf("Enter the array size: ");
    scanf("%d", &n);
    if(n<1){
        printf("Please enter a valid size of array, rerun the code\n");
        return -1;
    }
    int *arr = (int*)malloc(sizeof(int)*n);
    printf("Size of array = %d\n", n);
    
    //int arr[6] = {1,2,3,4,10,11};
    printf("Now enter each element of array: \n");
    for(i = 0; i<n;i++){
        scanf("%d", &arr[i]);
    }
    printf("Calculating the sum of contents of array\n");
    for(i = 0;i<n;i++){
        sum = sum + arr[i];
    }
    printf("Sum = %d",sum);
    free(arr);
    return 0;
}