/* This program is written to reverse a string input from user.
   there are many ways to do it, out of which 3 are discribed below.
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

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

/* Function to reverse a string using pointers */
void string_reverse1(char *string){	
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
}

/* to reverse a string without using any new variable */
void reverse(char *string){
	int len = strlen(string)-1;       // calculate lenthg of string
	int i=0; 
	for(i=0;i<strlen(string)/2;i++,len--){  // traverse the string till half way
		string[i] = string[i]+string[len];    // swap two variables
		string[len] = string[i]-string[len];  // swap two variables
		string[i] = string[i]-string[len];    // swap two variables
	}
	// shift the start pointer 'string' away from start and shift the end pointer 'len' away from end till it reaches halfway.
}

int main(){
	char str[10];                   // take an input string from user
	printf("Input a string: ");     
	scanf("%s", str);               
	printf("%s \n", str);           // print it to screen 
	
	reverse(str);                   // reverse the dtring
	//string_reverse1(str);
	//string_reverse2(str);
	
	printf("%s \n", str);           // print the reversed string
	return 0;
}
