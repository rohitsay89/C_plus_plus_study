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

#if 0
	printf("CRC of 0x%X = 0x%X\n", 0xC2, Simple_CRC8_II(0xC2));
	uint8_t val = 0x00;
	for( val=0x00; val < 0xFF; val++){
		//printf("CRC of 0x%x = 0x%X\n", val, Simple_CRC8(val));
		if(!(val%15))
			printf("\n");
		printf("0x%02X  ", Simple_CRC8_II(val));
	}
#endif
	CRC8_table();
	uint8_t arr[2] = {0x01, 0x02};
	//printf("CRC = 0x%0X\n", Simple_CRC8_III(arr, 2));
	printf("CRC = 0x%0X\n", Simple_CRC8_IV(arr, 2));

    return 0;
}
