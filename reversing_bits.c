#include <stdio.h>

unsigned short int reverse(unsigned short int n){		// Function for reversing a binary number //
	short int j = 0, i = 0;								// Array counters //
	unsigned short int rev[8];							// comparison array //
	unsigned short int r = 0x00;						// local result variable
	unsigned short int mask[] = {0x01, 0x02, 0x04, 0x08, 0x10, 0x20, 0x40, 0x80};
	/*
	 * The elements of mask register are used to mask a particular bit.
	 * 	0x01	0b 0000 0001 -> bit 0
	 * 	0x02	0b 0000 0010 -> bit 1
	 * 	0x04	0b 0000 0100 -> bit 3
	 * 	0x08	0b 0000 1000 -> bit 4
	 * 	0x10	0b 0001 0000 -> bit 5
	 * 	0x20	0b 0010 0000 -> bit 6
	 * 	0x40	0b 0100 0000 -> bit 7
	 * 	0x80	0b 1000 0000 -> bit 8
	 */
	
	for(i = 0; i<8; i++){								// loop for checking each bit in the number //
		if(mask[i] == (n&mask[i])){
			rev[i] = 0x01;								// Store 1 if bit is 1 //
		}
		else{
			rev[i] = 0x00;								// store 0 if bit is 0 //
		}
	}
	for(i=7, j = 0;i>=0;i--, j++){						// Array for reversing of bits in //
		if(rev[i] == 1){
			r = r|mask[j];
		}
	}
	return r;											// Return the revrsed number //
}

int main(){
    unsigned short int num = 0x00;
	unsigned short int uni = 0x00;
	unsigned short int ten = 0x00;
	unsigned short int re = 0x00;
	printf("Enter the number : \n");
	scanf("%hd", &num);									// input the number
	uni = num & MASK;									// find the unit's digit
	ten = num >> 4;										// find the tenth's digit
	printf("The number in Hex is : 0x%x \n", num);		// print the Hex vaue
	printf("The units digit is : 0x%x \n", uni);		// print the unit's digit
	printf("The tens digit is : 0x%x \n", ten);			// print the tenth's digit
	re = reverse(num);									// function for reversing of number.
	printf("the reverse number is : 0x%x \n", re);		// print the reversed number.
	
  	return 0;
  }
