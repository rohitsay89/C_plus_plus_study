#include <stdio.h>
#include <string.h>


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

	CRC_Practice();


    return 0;
}

void CRC_Practice(){


	printf("CRC8 of 0x%X = 0x%X\n", 0xC2, Simple_CRC8_II(0xC2));
#if 0
	uint8_t val = 0x00;
	for( val=0x00; val < 0xFF; val++){
		//printf("CRC of 0x%x = 0x%X\n", val, Simple_CRC8(val));
		if(!(val%15))
			printf("\n");
		printf("0x%02X  ", Simple_CRC8_II(val));
	}

	CRC8_table();
	uint8_t arr[2] = {0x01, 0x02};
	//printf("CRC = 0x%0X\n", Simple_CRC8_III(arr, 2));
	printf("CRC = 0x%0X\n", Simple_CRC8_IV(arr, 2));
	//printf("CRC of 0x%X = 0x%X\n", 0xC2, Simple_CRC16_I(0xC2));
	//uint8_t arr[2] = {0x01, 0x02};
	//CRC16_table();
	//printf("CRC = 0x%0X\n", Simple_CRC16_II(arr, 2));


	//Simple_CRC32_I(0x01);
	//uint8_t arr[2] = {0x01, 0x02};
	//CRC32_table();
	//printf("CRC = 0x%08X\n", Simple_CRC32_II(arr, 2));
#endif

#if 0
	// CRC32 calculation of a binary file:
	FILE *fp = NULL;
	uint8_t readBuf[20];
	int application_size = 0;
	uint8_t application_file_buffer[FILE_SIZE_128k] = {0};
	uint32_t CRC32 = 0;

	memset(readBuf, 0x00, 20);
	int i = 0;

	fp = fopen("sample_files/test.bin", "rb");
	if(fp){
		//file opened
		fseek(fp, 0L, SEEK_END);
		application_size = ftell(fp);
		printf("Application size = %d\n", application_size);
		fseek(fp, 0L, SEEK_SET);
		fread(application_file_buffer, 1, application_size, fp);
		crc32(application_file_buffer, application_size, &CRC32);
		printf("CRC32 = 0x%08X\n", CRC32);
		//CRC32_table();
		//printf("CRC = 0x%08X\n", Simple_CRC32_II(application_file_buffer, application_size));

		fclose(fp);
	}
	else{
		printf("Unable to open the file mentioned\n");
	}
#endif

}

