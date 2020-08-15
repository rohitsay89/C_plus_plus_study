#ifndef MAIN_H
#define MAIN_H

/* Includes */
#include <stdint.h>

/* MACROS */
#define cmp(h)	~h
#define min(a, b)	((a<b)?a:b)			/* macro for minimum of 2 numbers */
#define SIZE(arr)	(sizeof(arr)/sizeof(arr[1]))		           	/* Macro for returning size of array */
#define POLYNOMIAL_8_BIT				0x1Du
#define POLYNOMIAL_16_BIT				0x1021

#define POLYNOMIAL_32_BIT_STM32			0x04C11DB7
#define POLYNOMIAL_32_BIT_7ZIP			0x1EDC6F41
#define POLYNOMIAL_B					0xEDB88320

#define FILE_SIZE_128k					131072

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

void CRC_Practice();
uint8_t Simple_CRC8_I(uint8_t val);
uint8_t Simple_CRC8_II(uint8_t val);
uint8_t Simple_CRC8_III(uint8_t* val, uint8_t len);
uint8_t Simple_CRC8_IV(uint8_t* val, uint8_t len);
void CRC8_table();

uint16_t Simple_CRC16_I(uint8_t val);
uint16_t Simple_CRC16_II(uint8_t* val, uint8_t len);
void CRC16_table();

uint32_t Simple_CRC32_I(uint8_t val);
uint32_t Simple_CRC32_II(uint8_t* val, uint8_t len);
void CRC32_table();

void GenerateCRC32Table();
uint32_t crc32_for_byte(uint32_t r, uint32_t POLY);
void crc32(const void *data, size_t n_bytes, uint32_t* crc);

uint32_t calculateSTM32F4crc(uint8_t *buff, uint32_t len);

#endif
