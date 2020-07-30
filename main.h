#ifndef MAIN_H
#define MAIN_H

/* Includes */
#include <stdint.h>

/* MACROS */
#define cmp(h)	~h
#define min(a, b)	((a<b)?a:b)			/* macro for minimum of 2 numbers */
#define SIZE(arr)	(sizeof(arr)/sizeof(arr[1]))		           	/* Macro for returning size of array */

/* Function Prototypes */

int array_sum();
float array_avg();
void array_even_odd_sum();
void array_reverse();
void array_prime();

uint32_t inverse_num();

void sum_of_prime(int n);
void find_prime(int num);

uint8_t reverse_bits(uint8_t n);

void vSelectionSort();
void vInsertionSort();

void string_reverse1(char *string);
void string_reverse2(char *string);
void string_reverse3(char *string);

void num_swapping_pointers(int *, int *);



#endif
