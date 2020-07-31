#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "main.h"

int arr1[20]; // global array declare
int arr2[20]; // global array declare

/* OPERATIONS ON ARRAY */
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

uint8_t Simple_CRC8(uint16_t val){
	uint8_t POLY = 0x1D;
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
			crc = crc ^ POLY;
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

