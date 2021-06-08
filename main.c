#include <stdio.h>
#include <string.h>

#define __STDC_FORMAT_MACROS

#include <inttypes.h>

#include "main.h"

int main(){
    printf("C program to learn some C basics \n");
    printf("Build date = %s, Time = %s\n\n", __DATE__, __TIME__);

    //array_address_calculation();
    //array_sum();
    //inverse_num(55);
    //prime(55);
    //find_prime(55);
    //reverse_bits(0x02);
    //vSelectionSort();
    //vInsertionSort();
    //char str[11] = "HELLOWORLD";
    //string_reverse1(str);
    //vstringSearch();
	//CRC_Practice();
    //printf("%X", vFibonacciSequence(100));
    // polynomial using array:
    //vpolynomialUsingArray();
    //vLearnRecursion();
    //vListFilesInDir();
    vLearnStateMachine();

    printf("Program execution has ended\n");
    return 0;
}


