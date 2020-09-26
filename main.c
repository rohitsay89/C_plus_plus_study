#include <stdio.h>
#include <string.h>

#define __STDC_FORMAT_MACROS

#include <inttypes.h>

#include "main.h"

int main(){
    printf("C program to learn some C basics \n");
    printf("Build date = %s, Time = %s\n\n", __DATE__, __TIME__);
    //array_sum();

    //inverse_num(55);

    //prime(55);
    //find_prime(55);

    //reverse_bits(0x02);

    //vSelectionSort();

    //vInsertionSort();

    //char str[11] = "HELLOWORLD";
    //string_reverse1(str);

	//CRC_Practice();

    //printf("%X", vFibonacciSequence(100));
    int i = 0;
    for(i=1; i<=100; ++i){
    	printf(" %" PRIu64 " \n", vFibonacciSequence(i));
    }


    return 0;
}


