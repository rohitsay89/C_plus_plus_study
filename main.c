#include <stdio.h>


#include "main.h"

int main(){
    //printf("Hello World \n");
    //array_sum();

    //inverse_num(55);

    //prime(55);
    //find_prime(55);

    //reverse_bits(0x02);

    //vSelectionSort();

    //vInsertionSort();

    //char str[11] = "HELLOWORLD";
    //string_reverse1(str);

	uint8_t val = 0x00;
	for( val=0x00; val < 0xFF; val++){
		//printf("CRC of 0x%x = 0x%X\n", val, Simple_CRC8(val));
		if(!(val%15))
			printf("\n");
		printf("0x%02X  ", Simple_CRC8(val));
	}

    return 0;
}
