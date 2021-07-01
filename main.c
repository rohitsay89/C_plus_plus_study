#include <stdio.h>
#include <string.h>

#define __STDC_FORMAT_MACROS

#include <inttypes.h>

#include "main.h"
#include "logging/log.h"

int main(){
	log_trace("C program to learn some C basics");
	log_debug("Build date = %s, Time = %s", __DATE__, __TIME__);
	log_info("This is test information log");
	log_warn("This is test warning log");
	log_error("This is test error log");
	log_fatal("This is test fatal log");
    //printf("C program to learn some C basics \n");
    //printf("Build date = %s, Time = %s\n\n", __DATE__, __TIME__);

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

	log_trace("Program execution has ended\n");
    return 0;
}


