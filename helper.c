#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "main.h"

int arr1[20]; // global array declare
int arr2[20]; // global array declare

uint8_t crc8Table[256];
uint16_t crc16Table[256];
uint32_t crc32Table[256];

/* The following table was calculated from the following code:
 * The Polynomial used was 0xEDB88320L
 * static uint32_t CRCTable[0x100];
	if(!*CRCTable)
	{
		for(size_t i = 0; i < 0x100; ++i)
		{
			CRCTable[i] = crc32_for_byte(i);
		}
	}
	uint32_t crc32_for_byte(uint32_t r)
	{
		int j = 0;
		for( j = 0; j < 8; ++j )
		{
			r = (r & 1? 0: (uint32_t)POLYNOMIAL_B) ^ r >> 1;
		}
		return r ^ (uint32_t)0xFF000000L;
	}
 * */

static const uint32_t CRCTable[] =
{
		0xD202EF8D, 0xA505DF1B, 0x3C0C8EA1, 0x4B0BBE37, 0xD56F2B94, 0xA2681B02, 0x3B614AB8, 0x4C667A2E,
		0xDCD967BF, 0xABDE5729, 0x32D70693, 0x45D03605, 0xDBB4A3A6, 0xACB39330, 0x35BAC28A, 0x42BDF21C,
		0xCFB5FFE9, 0xB8B2CF7F, 0x21BB9EC5, 0x56BCAE53, 0xC8D83BF0, 0xBFDF0B66, 0x26D65ADC, 0x51D16A4A,
		0xC16E77DB, 0xB669474D, 0x2F6016F7, 0x58672661, 0xC603B3C2, 0xB1048354, 0x280DD2EE, 0x5F0AE278,
		0xE96CCF45, 0x9E6BFFD3, 0x0762AE69, 0x70659EFF, 0xEE010B5C, 0x99063BCA, 0x000F6A70, 0x77085AE6,
		0xE7B74777, 0x90B077E1, 0x09B9265B, 0x7EBE16CD, 0xE0DA836E, 0x97DDB3F8, 0x0ED4E242, 0x79D3D2D4,
		0xF4DBDF21, 0x83DCEFB7, 0x1AD5BE0D, 0x6DD28E9B, 0xF3B61B38, 0x84B12BAE, 0x1DB87A14, 0x6ABF4A82,
		0xFA005713, 0x8D076785, 0x140E363F, 0x630906A9, 0xFD6D930A, 0x8A6AA39C, 0x1363F226, 0x6464C2B0,
		0xA4DEAE1D, 0xD3D99E8B, 0x4AD0CF31, 0x3DD7FFA7, 0xA3B36A04, 0xD4B45A92, 0x4DBD0B28, 0x3ABA3BBE,
		0xAA05262F, 0xDD0216B9, 0x440B4703, 0x330C7795, 0xAD68E236, 0xDA6FD2A0, 0x4366831A, 0x3461B38C,
		0xB969BE79, 0xCE6E8EEF, 0x5767DF55, 0x2060EFC3, 0xBE047A60, 0xC9034AF6, 0x500A1B4C, 0x270D2BDA,
		0xB7B2364B, 0xC0B506DD, 0x59BC5767, 0x2EBB67F1, 0xB0DFF252, 0xC7D8C2C4, 0x5ED1937E, 0x29D6A3E8,
		0x9FB08ED5, 0xE8B7BE43, 0x71BEEFF9, 0x06B9DF6F, 0x98DD4ACC, 0xEFDA7A5A, 0x76D32BE0, 0x01D41B76,
		0x916B06E7, 0xE66C3671, 0x7F6567CB, 0x0862575D, 0x9606C2FE, 0xE101F268, 0x7808A3D2, 0x0F0F9344,
		0x82079EB1, 0xF500AE27, 0x6C09FF9D, 0x1B0ECF0B, 0x856A5AA8, 0xF26D6A3E, 0x6B643B84, 0x1C630B12,
		0x8CDC1683, 0xFBDB2615, 0x62D277AF, 0x15D54739, 0x8BB1D29A, 0xFCB6E20C, 0x65BFB3B6, 0x12B88320,
		0x3FBA6CAD, 0x48BD5C3B, 0xD1B40D81, 0xA6B33D17, 0x38D7A8B4, 0x4FD09822, 0xD6D9C998, 0xA1DEF90E,
		0x3161E49F, 0x4666D409, 0xDF6F85B3, 0xA868B525, 0x360C2086, 0x410B1010, 0xD80241AA, 0xAF05713C,
		0x220D7CC9, 0x550A4C5F, 0xCC031DE5, 0xBB042D73, 0x2560B8D0, 0x52678846, 0xCB6ED9FC, 0xBC69E96A,
		0x2CD6F4FB, 0x5BD1C46D, 0xC2D895D7, 0xB5DFA541, 0x2BBB30E2, 0x5CBC0074, 0xC5B551CE, 0xB2B26158,
		0x04D44C65, 0x73D37CF3, 0xEADA2D49, 0x9DDD1DDF, 0x03B9887C, 0x74BEB8EA, 0xEDB7E950, 0x9AB0D9C6,
		0x0A0FC457, 0x7D08F4C1, 0xE401A57B, 0x930695ED, 0x0D62004E, 0x7A6530D8, 0xE36C6162, 0x946B51F4,
		0x19635C01, 0x6E646C97, 0xF76D3D2D, 0x806A0DBB, 0x1E0E9818, 0x6909A88E, 0xF000F934, 0x8707C9A2,
		0x17B8D433, 0x60BFE4A5, 0xF9B6B51F, 0x8EB18589, 0x10D5102A, 0x67D220BC, 0xFEDB7106, 0x89DC4190,
		0x49662D3D, 0x3E611DAB, 0xA7684C11, 0xD06F7C87, 0x4E0BE924, 0x390CD9B2, 0xA0058808, 0xD702B89E,
		0x47BDA50F, 0x30BA9599, 0xA9B3C423, 0xDEB4F4B5, 0x40D06116, 0x37D75180, 0xAEDE003A, 0xD9D930AC,
		0x54D13D59, 0x23D60DCF, 0xBADF5C75, 0xCDD86CE3, 0x53BCF940, 0x24BBC9D6, 0xBDB2986C, 0xCAB5A8FA,
		0x5A0AB56B, 0x2D0D85FD, 0xB404D447, 0xC303E4D1, 0x5D677172, 0x2A6041E4, 0xB369105E, 0xC46E20C8,
		0x72080DF5, 0x050F3D63, 0x9C066CD9, 0xEB015C4F, 0x7565C9EC, 0x0262F97A, 0x9B6BA8C0, 0xEC6C9856,
		0x7CD385C7, 0x0BD4B551, 0x92DDE4EB, 0xE5DAD47D, 0x7BBE41DE, 0x0CB97148, 0x95B020F2, 0xE2B71064,
		0x6FBF1D91, 0x18B82D07, 0x81B17CBD, 0xF6B64C2B, 0x68D2D988, 0x1FD5E91E, 0x86DCB8A4, 0xF1DB8832,
		0x616495A3, 0x1663A535, 0x8F6AF48F, 0xF86DC419, 0x660951BA, 0x110E612C, 0x88073096, 0xFF000000
};

/* OPERATIONS ON ARRAY */
void array_address_calculation()
{
	printf("This is Array address calculation module\n");
#if 0
	printf("1-D array address calculation\n");
	int a[10] = {1,2,3,4,5,6,7,8,9,10};
	int i = 0;
	printf("Base Address of array = 0x%08X\n", &a[0]);
	for(i=0;i<10;++i){
		printf("0x%08X: a[%d] = %d \n", &a[i], i, a[i]);
	}
	uint32_t addr = &a[0];
	// address if 5th element =
	addr = addr + 5*sizeof(int);
	printf("address of 5th element of a = 0x%08X\n", addr);
#endif

#if 1
	printf("2-D array address calculation, assuming row major format\n");
	uint32_t row = ROW_SIZE_3X3_MATRIX;
	uint32_t col = COL_SIZE_3X3_MATRIX;
	int a[ROW_SIZE_3X3_MATRIX][COL_SIZE_3X3_MATRIX] = {{1,2,3}, {4,5,6}, {7,8,9}};
	int r = 0, c = 0;
	printf("Base Address of array = 0x%08X\n", &a[0]);
	for(r=0;r<3;++r){
		for(c=0;c<3;c++){
			printf("0x%08X: a[%d][%d] = %d \n", &a[r][c], r, c, a[r][c]);
			//printf("%02X ", a[r][c]);
		}
		//printf("\n");
	}
	uint32_t addr = 0;
	uint32_t base = &a[0];

	// address of r = 2, c = 3
	r = 0;
	c = 0;
	addr = base + r*col*sizeof(int) + c*sizeof(int);
	printf("address of a[%d][%d] = 0x%08X\n", r, c, addr);

	r = 1;
	c = 2;
	addr = base + r*col*sizeof(int) + c*sizeof(int);
	printf("address of a[%d][%d] = 0x%08X\n", r, c, addr);

	r = 1;
	c = 1;
	addr = base + r*col*sizeof(int) + c*sizeof(int);
	printf("address of a[%d][%d] = 0x%08X\n", r, c, addr);

	r = 2;
	c = 2;
	addr = base + r*col*sizeof(int) + c*sizeof(int);
	printf("address of a[%d][%d] = 0x%08X\n", r, c, addr);
#endif

}

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

float array_avg(){
	printf("Calculating average of an array\n");
	int a[5] = {1,2,3,4,5};
	float b = 0.0f, av = 0;
	int i;
	for (i=0; i<5;i++)
	{
		av = av+a[i];
	}
	b = av/5;
	printf("Average = %f\n", b);
	return b;
}

void array_even_odd_sum(){
	printf("Calculating sum of even and odd position values\n");
	int a[5] = {1,2,3,4,5};
	int ead = 0, od = 0;
	int i;
	for(i =0;i<5;i++)
	{
		if(i%2)
			od = od+a[i];
		else
			ead = ead+a[i];
	}
	printf("The sum of even values is: %d \n", ead);
	printf("The sum of odd values is: %d \n", od);
}

void array_reverse(){
	printf("Reversing array using new array\n");
	int a[5] = {1,2,3,4,5};
	int rev[5];
	int r = 0,i = 0;
	for (i = 0, r = 4; i<5 && r>-1; i++, r--)
	{
		rev[r] = a[i];
	}

	printf(" The reversed array is as follows: \n");
	for (r=0; r<5;r++)
		printf(" a[%d] : %d\t", r, rev[r]);
	printf("\n");
}

void array_prime(){
	printf("Checking primes in an array\n");
	int a[5] = {1,2,3,4,5};
	int i = 0, count = 0;
	for(i=0;i<5;i++){
		if(a[i]%2){
			if(a[i]%3){
				count++;
				//printf("  %d is a Prime number \n", a[i]);
			}
			else
				printf("  %d is Not a prime number \n", a[i]);
		}
		else
			printf("  %d is Not a prime number \n", a[i]);
	}
	printf(" There are %d prime numbers in the array \n", count);
}

/* OPERATIONS ON NUMBERS */

/* Complement of a number */
uint32_t inverse_num(uint32_t num){
	printf("The original number is: %d, in hex: 0x%X", num, num);
	printf("The complement is: %d in hex: 0x%X", cmp(num), cmp(num));
	return cmp(num);
}


// Function to Check Whether a Number can be Express as Sum of Two Prime Numbers
void sum_of_prime(int n){
	int i = 0, j = 0, a = 0; // some local variables declared

	// loop algorithm for saving all the prime numbers from '0 to n'
	// in two arrays : arr1 and arr2.
	for(i = 0; i<n; i++){
		if(i%2 != 0){
			if(i%3 != 0){
				if(i%5 != 0){
					if(i%7 != 0){
						arr1[a] = i; // if prime save in array arr1
						arr2[a] = i; // if prime save in array arr2
						a++;
					}
					else
						continue;
				}
				else
					continue;
			}
			else
				continue;
		}
		else
			continue;
	}
	// printing the array of prime numbers on the screen
	for(j = 0; j<=20;j++){
		printf("The sum is: %d\t", arr1[j]);
	}
}

void find_prime(int num){
	int i = 0, j = 0; // declare some local variables
	int sum = 0;
	// loop algorithm for summing the elemts of two array i.e. arr1 and arr2 with different combinations
	// arr1[0] + arr2[0]
	// arr1[0] + arr2[1]
	// arr1[0] + arr2[2]
	// arr1[0] + arr2[3]
	//	..			..
	// arr1[0] + arr2[20]
	//	..			..
	//	..			..
	// arr1[1] + arr2[0]
	//	..			..
	//	..			..
	// arr1[20] + arr2[20]
	// and so on
	for(i =0; i<=20;i++){
		for(j = 0; j<=20; j++){
			sum = arr1[i] + arr2[j];
			if(sum == num){ // check if sum is equal to given number
				printf("Sum found !!: %d + %d = %d\n", arr1[i], arr2[j], num);
				//cout << "Sum found !! :" << arr1[i] << " + " << arr2[j] << " = " << num << endl;
				// if true then print the array elements on the screen
			}
			else
				continue;
		}
	}
}

/* Function for Reversing of bits in a number
   Written by: ROHIT
   date: 10/18/2015
*/
uint8_t reverse_bits(uint8_t n)
{
	printf("Input number = 0x%X\n", n);
	short int j = 0, i = 0;								/* Array counters */
	unsigned short int rev[8];							/* comparison array */
	unsigned short int r = 0x00;							/* local result variable */
	unsigned short int mask[] = {0x01, 0x02, 0x04, 0x08, 0x10, 0x20, 0x40, 0x80};
	/*
	 * The elements of mask register are used to mask all bits except the required one.
	 * 	0x01	0b 0000 0001 -> bit 0
	 * 	0x02	0b 0000 0010 -> bit 1
	 * 	0x04	0b 0000 0100 -> bit 3
	 * 	0x08	0b 0000 1000 -> bit 4
	 * 	0x10	0b 0001 0000 -> bit 5
	 * 	0x20	0b 0010 0000 -> bit 6
	 * 	0x40	0b 0100 0000 -> bit 7
	 * 	0x80	0b 1000 0000 -> bit 8
	 */

	for(i = 0; i<8; i++){					/* loop for checking each bit in the number */
		if(mask[i] == (n&mask[i])){
			rev[i] = 0x01;				/* Store 1 if bit is 1 */
		}
		else{
			rev[i] = 0x00;				/* store 0 if bit is 0 */
		}
	}
	for(i=7, j = 0;i>=0;i--, j++){				/* Array for reversing of bits in */
		if(rev[i] == 1){
			r = r|mask[j];
		}
	}
	return r;						/* Return the revrsed number */
}



/* Code for parsing through a file for email address and printing them on the console
 * Author: Rohit
 * Date: 10/20/2015
 * */
void email_parsing(){
	FILE *fp = NULL;						/* file pointer */
	char *str = {0};						/* character pointer */
	int c=1;								/* count for number of email address */
	fp = fopen("test.txt", "r");			/* open the file */
	int n=0;
	if(fp == NULL){							/* check for availability of file */
		printf("File cannot be opened");}
	do{										/* do while loop till end of file */
		str = (char*)malloc(1000);			/* allocate 1000 bytes for the string, depending in the file size */
		fscanf(fp,"%s", str);				/* read form the file and store the string(word) in the string 'str' */
	    for(n = 0; n<30; n++){				/* scan for a letter in the string */
	    	if(str[n] == '@'){				/* if the letter is '@' */
	    		printf("%d: %s \n",c,str);	/* print the string */
	    		c++;						/* increment a counter */
	    		continue;					/* continue for next line */
	    	}
	      }
	   }while( !feof(fp) );					/* check for end of file */
	fclose(fp);								/* close the file */
	printf("There are %d number of emails in this file", c-1);
}

/* ALGORITHMS */
void vSelectionSort(){
  	int i_index = 0, size_of=0, j_index = 0, y=0;
	int array[] = {77,44,33,55,22,11};
	size_of = SIZE(array);                                      		/* size of array from a macro */
	printf("Size of array is: %d elements \n",size_of);			/* print the size of array */
	printf("Original array: \n");
	for (i_index = 0;i_index<size_of;i_index++){				/* print whole array */
		printf("array[%d]:%d | ", i_index,array[i_index]);        	/* print the given array */
	}
	printf("\n");

	for(y = 0, i_index = 0;y<size_of; y++,i_index++){           		/* start selection sorting */
		for(j_index=i_index+1;j_index<size_of;j_index++){
			if(array[i_index]>array[j_index]){			/* Swap two variables without using 3rd */
				array[i_index] = array[i_index]+array[j_index];       /* Step 1 */
				array[j_index] = array[i_index]-array[j_index];	      /* Step 2 */
				array[i_index] = array[i_index]-array[j_index];	      /* Step 3 */
			}
		}
	}
	printf("Sorted array: \n");						/* Print the sorted array */
	for (i_index = 0;i_index<size_of;i_index++){
		printf("array[%d]:%d | ", i_index,array[i_index]);
	}
}

void vInsertionSort(){
	int ar_size = 10;
	int ar[10] = {100,-5,66,-2,-3,-2,-1,550,99,11};

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

/* This program is written to reverse a string input from user.
   there are many ways to do it, out of which 3 are discribed below.
*/
/* Function to reverse a string using pointers */
void string_reverse1(char *string){
	printf("Original string = %s\n", string);
	char temp;                        // declare a temporary variable
	char* end;                        // declare a character pointer
	end = string + strlen(string)-1;  // define it to point at end of string

	while(end>string){                // while loop to traverse throught the striing
		temp = *end;                    // store the last element in temp
		*end = *string;                 // store the first element at last location
		*string = temp;                 // now store the temp to first location
		end--;                          // shift end pointer one location away from end
		string++;                       // shift start pointer one location away from start
	}                                 //        start ======> <====== end
	printf("Reversed string = %s\n", string);
}

/* to reverse array using new array */
void string_reverse2(char *string)
{
	int len = 0;                      // declare a string length variable
	len = sizeof(string);             // define it
	//printf("%d \n", len);           // print it
	char str[len];                    // create a new string of length 'len', string is an array of characters
	int i=0,j=0;                      // define array counteres
	for(i=0,j=len;i<=len;i++,j--){    // for loop to traverse through the string
		str[i]=string[j];               // store the data from old string to the new string in reverse order
		printf("%c", str[i]);           // print string element by element
	}
	printf("\n");
	printf("%s\n", str);              // print the string
}

/* to reverse a string without using any new variable */
void string_reverse3(char *string){
	int len = strlen(string)-1;       // calculate lenthg of string
	int i=0;
	for(i=0;i<strlen(string)/2;i++,len--){  // traverse the string till half way
		string[i] = string[i]+string[len];    // swap two variables
		string[len] = string[i]-string[len];  // swap two variables
		string[i] = string[i]-string[len];    // swap two variables
	}
	// shift the start pointer 'string' away from start and shift the end pointer 'len' away from end till it reaches halfway.
}

void vstringSearch(){
	char s1[] = "Actually, these are the hardest to explain, so we will come back to this later";
	char s2[] = "explain";
	strSrch(s1, s2);
}

void strSrch(char *s1, char *s2){
	int i = 0, j=0, k=0;
	while(s1[i] != '\0'){
		i++;
	}
	printf("S1 length = %d\n", i);
	int I1 = i;
	i=0;
	while(s2[i] != '\0'){
		i++;
	}
	printf("S2 length = %d\n", i);
	int I2 = i;
	printf("Str1 = %s\nStr2 = %s\n", s1, s2);
	for(i=0;i<=I1-I2;i++)
	{
		j=0;
		k=i;
		while( (s1[k] == s2[j]) && (j<I2) )
		{
			k++;
			j++;
		}
		if(j == I2){
			printf("String found\n");
			return ;
		}
	}
	printf("String not found\n");
	return ;
}

void num_swapping_pointers(int *p1, int *p2){
	int N1=10;
	int N2=20;
	printf("Before Swapping\n");
	printf("N1:%d N2:%d\n", N1, N2);
	int temp;
	temp = *p1;
	*p1 = *p2;
	*p2 = temp;
	printf("Before Swapping\n");
	printf("N1:%d N2:%d\n", N1, N2);
}

char check_age_18_plus(int *day, int *mnth, int *year){
	//int suc = -1;
	if(*year >= 1997)
		if(*mnth >= 9)
			if(*day >= 2)
				return 'P';
			else
				return 'N';
		else
			return 'N';
	else
		return 'N';
}

/*
* Write a program to read 5 digit number & evaluate the sum of all its even & odd locations print separatly
		12345 --> 1+3+5
		2+4 --> ?
		Then reverse the same number & check for palindrome
		rev == original
		Also count numbef of odd & even digits in the number
*/

uint8_t Simple_CRC8_I(uint8_t val){
	uint8_t crc = 0x00;
	uint16_t value = 0x00;
	value = value + (val << 8);

	int j = 0;
	for(j=15; j >= 0; --j)
	{
		if((crc & 0x80) != 0){
			// MSB set so shift it out of the crc register
			crc = (uint8_t)(crc << 1);
			// check the next bit of the input stream,
			// if its one then set the 0th bit in crc variable
			// else reset the 0th bit in crc variable
			crc = ((value & (1 << j)) != 0) ? (crc | 0x01) : (crc & 0xFE);

			// XOR now
			crc = crc ^ POLYNOMIAL_8_BIT;
		}
		else{
			// MSB not set
			crc = (uint8_t)(crc << 1);

			// check the next bit of the input stream,
			// if its one then set the 0th bit in crc variable
			// else reset the 0th bit in crc variable
			crc = ((value & (1 << j)) != 0) ? (crc | 0x01) : (crc & 0xFE);
		}
		//printf("crc = 0x%X\n", crc);
	}
	return crc;
}

// Calculation of 1 byte data
uint8_t Simple_CRC8_II(uint8_t val){
	uint8_t crc = 0x00;
	crc = val;
	int bitPos = 0;

	for( bitPos = 0; bitPos < 8; ++bitPos){
		if( ( crc & 0x80 ) ){
			crc = ( (crc << 1) ^ POLYNOMIAL_8_BIT );
		}
		else{
			crc = crc << 1;
		}
	}
	return crc;
}

uint8_t Simple_CRC8_III(uint8_t* val, uint8_t len){
	// initialise CRC with 0x00
	uint8_t crc = 0x00;
	int j = 0, i = 0;

	// loop through each byte in the array val
	for(i=0;i<len;i++){
		crc = crc ^ val[i];
		//printf("Crc III start of loop = 0x%X\n", crc);
		// Loop through each bit in the byte and calculate CRC for that byte
		// by the end of this inner loop
		for( j = 0; j < 8; ++j){
			if( ( crc & 0x80 ) ){
				crc = ( (crc << 1) ^ POLYNOMIAL_8_BIT );
			}
			else{
				crc = crc << 1;
			}
		}
		//printf("Crc III end of loop = 0x%X\n", crc);
	}
	return crc;
}

// Calculation of all possible 8 bit values (0 to 255) and create lookup table
void CRC8_table(){
	memset(crc8Table, 0x00, 256);
	int val = 0x00;
	uint8_t crc = 0x00;
	for( val=0x00; val < 256; ++val){
		//if(!(val%15))
		//	printf("\n");
		crc = Simple_CRC8_II(val);
		crc8Table[val] = crc;
		//printf("crc8Table[%d] = 0x%02X \n",val, crc);
	}
}

// Calculate CRC from the look up table
uint8_t Simple_CRC8_IV(uint8_t* val, uint8_t len){
	uint8_t crc = 0x00;
	int index = 0;

	// loop through each byte in the array val
	for( index = 0; index < len; index++ ){
		crc = crc ^ val[index];
		crc = crc8Table[crc];
	}
	return crc;
}

uint16_t Simple_CRC16_I(uint8_t val){
	uint16_t crc = 0x00;
	crc = crc ^ (val << 8);

	int bitPos = 0;
	for(bitPos = 0; bitPos < 8; ++bitPos){
		if( ( crc & 0x8000 ) ){
			crc = ( ( crc << 1 ) ^ POLYNOMIAL_16_BIT );
		}
		else{
			crc = crc << 1;
		}
	}
	return crc;
}

uint16_t Simple_CRC16_II(uint8_t* val, uint8_t len){
	uint16_t crc = 0x00;
	int index = 0;
	int bitPos = 0;
	for( index = 0; index < len; ++index ){
		crc = crc ^ (val[index] << 8);
		// calculate CRC for 1 byte
		for( bitPos = 0; bitPos < 8; ++bitPos ){
			if( crc & 0x8000 ){
				crc = ( ( crc << 1 ) ^ POLYNOMIAL_16_BIT );
			}
			else{
				crc = crc << 1;
			}
		}
		printf("CRC = 0x%04X\t", crc);
	}
	return crc;

}

uint16_t Simple_CRC16_III(uint8_t* val, uint8_t len){
	uint16_t crc = 0x00;
	uint8_t pos = 0;

	int index = 0;
	for( index = 0; index < len; ++index){
		pos = ( (crc ^ (val[index] << 8) >> 8) );
		crc = crc ^ crc16Table[pos];
	}

	return crc;
}

void CRC16_table(){
	memset(crc16Table, 0x00, sizeof(uint16_t) * 256);
	int val = 0x00;
	uint16_t crc = 0x00;
	for( val=0x00; val < 256; ++val){
		//if(!(val%15))
		//	printf("\n");
		crc = Simple_CRC16_I(val);
		crc16Table[val] = crc;
		printf("crc8Table[%d] = 0x%04X \n",val, crc);
	}
}

uint32_t Simple_CRC32_I(uint8_t val){
	//printf("val = 0x%X\n", val);
	uint32_t crc = 0;
	crc = crc ^ (uint32_t)(val << 24);
	//printf("crc = 0x%08X, val = 0x%X\n", crc, val);

	int bitPos = 0;
	for( bitPos = 0; bitPos < 8; ++bitPos){
		if( crc & 0x80000000 ){
			crc = ( (crc << 1) ^ POLYNOMIAL_32_BIT_7ZIP );
		}
		else{
			crc = crc << 1;
		}
		//printf("crc = 0x%08X\n", crc);
	}
	return crc;
}

void CRC32_table(){
	memset(crc32Table, 0x00, sizeof(uint32_t)*256);
	uint32_t crc = 0;

	int index = 0;
	for( index = 0; index < 256; ++index ){
		crc = Simple_CRC32_I((uint32_t)index);
		crc32Table[index] = crc;
		if(!(index % 8)){
			printf("\n");
		}
		printf("0x%08X ", crc);
	}
}

uint32_t Simple_CRC32_II(uint8_t* val, uint8_t len){
	uint32_t crc = 0x00;
	uint8_t pos = 0;

	int index = 0;
	for( index = 0; index < len; ++index){
		pos = ( (crc ^ (val[index] << 24) >> 24) );
		crc = (crc << 8) ^ crc32Table[pos];
	}

	return crc;
}

/* Generate CRCTable */

void GenerateCRC32Table(uint32_t POLY)
{
	printf("Generate table using POLY = 0x%08X\n", POLY);
	static uint32_t GenerateCRCTable[0x100];
	for(size_t i = 0; i < 0x100; ++i)
	{
		GenerateCRCTable[i] = crc32_for_byte(i, POLY);
		printf("0x%08X  ", GenerateCRCTable[i]);
		if(!((i+1)%8)){
			printf("\n");
		}
	}
}

uint32_t crc32_for_byte(uint32_t r, uint32_t POLY)
{
	int j = 0;
	for( j = 0; j < 8; ++j )
	{
		r = (r & 1? 0: (uint32_t)POLY) ^ r >> 1;
	}
	return r ^ (uint32_t)0xFF000000L;
}

// The following algorithm produces the same CRC value as produced by 7-Zip software (right click bin file and click CRC-SHA)
void crc32(const void *data, size_t n_bytes, uint32_t* crc)
{
	for(size_t i = 0; i < n_bytes; ++i)
	{
		*crc = CRCTable[(uint8_t)*crc ^ ((uint8_t*)data)[i]] ^ *crc >> 8;
	}
}


/*
 * CRC Calculation for compatibility with STM32F4's CRC peripheral
 */
uint32_t calculateSTM32F4crc(uint8_t *buff, uint32_t len)
{
    uint32_t i;

    uint32_t Crc = 0XFFFFFFFF;

    for(uint32_t n = 0 ; n < len ; n++ )
    {
        uint32_t data = buff[n];
        Crc = Crc ^ data;
        for(i=0; i<32; i++)
        {

        if (Crc & 0x80000000)
            Crc = (Crc << 1) ^ POLYNOMIAL_32_BIT_STM32; // Polynomial used in STM32
        else
            Crc = (Crc << 1);
        }

    }

  return(Crc);
}

void CRC_Practice()
{
	uint8_t data = 0xC2;
	printf("CRC for 0x%X = 0x%X\n", data, calculateSTM32F4crc(&data, 1));
#if 0
	//GenerateCRC32Table(POLYNOMIAL_B);
	uint32_t CRC32 = 0;
	crc32(&data, 1, &CRC32);
	printf("CRC8 of 0x%X = 0x%X\n", 0xC2, Simple_CRC8_II(0xC2));
	printf("CRC8 of 0x%X = 0x%X\n", 0xC2, CRC32);
//#if 0
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


	printf("CRC for 0x%X = 0x%X\n", data, Simple_CRC32_I(data));
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


// ======================= MATH Functions ================= //

// Print Fibonacci sequence upto nth number
uint64_t vFibonacciSequence(uint32_t n)
{
	// using recursion
#if 0
	static uint32_t febSeq;
	if(n <= 1){
		return n;
	}
	else{
		febSeq = vFibonacciSequence(n-1) + vFibonacciSequence(n-2);
		//if(n%2)
			//printf("\t\t");
		//printf("febSeq = %d\n", febSeq);
		return febSeq;
	}
#endif


	// using for loop
#if 1
	uint32_t i = 0;
	uint64_t prev = 0LL;
	uint64_t current = 1LL;
	uint64_t next = 0LL;

	//printf("%d\n%d\n", prev, current);
	for( i = 1; i <= n-1; ++i )
	{
		next = prev + current;
		//printf("%d\n", next);
		prev = current;
		current = next;
	}
	return next;
#endif


	return 0;
}

void polynomialUsingArray(){
	poly_t p1, p2, p3;
	initPoly(&p1);
	initPoly(&p2);
	initPoly(&p3);

	polyAppend(&p1, 78,7);
	polyAppend(&p1, 3,6);
	polyAppend(&p1, 44,5);
	polyAppend(&p1, 45,4);
	polyAppend(&p1, 2,3);
	polyAppend(&p1, 2,2);
	polyAppend(&p1, 1,1);
	polyAppend(&p1, 90,0);

	printPoly(&p1);


}

void initPoly(poly_t *p){
	p->noofitmes = 0;

	// fill up zeros for all coefficients
	int i = 0;
	for(i=0;i<10; ++i){
		p->t[i].coeff = 0;
		p->t[i].exp = 0;
	}
}

void polyAppend(poly_t *p, int coff, uint32_t exp){
	p->t[p->noofitmes].coeff = coff;
	p->t[p->noofitmes].exp = exp;
	(p->noofitmes)++;
}

void printPoly(poly_t *p){
	int i = 0;
	for(i=0; i<p->noofitmes; ++i){
		printf("%dx^%d + ", p->t[i].coeff, p->t[i].exp);
	}
}


