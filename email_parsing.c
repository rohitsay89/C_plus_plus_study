/* Code for parsing through a file for email address and printing them on the console
 * Author: Rohit Deshpande
 * Date: 10/20/2015
 * */
#include <stdio.h>
#include <stdlib.h>

int main(){
	FILE *fp = NULL;								// file pointer
	char *str = {0};								// character pointer
	int c=1;										// count for number of email address
	fp = fopen("test.txt", "r");				// open the file
	int n=0;
	if(fp == NULL){									// check for availability of file
		printf("File cannot be opened");}
	do{												// do while loop till end of file
		str = (char*)malloc(1000);					// allocate 1000 bytes for the string, depending in the file size
		fscanf(fp,"%s", str);						// read form the file and store the string(word) in the string 'str'
	    for(n = 0; n<30; n++){						// scan for a letter in the string
	    	if(str[n] == '@'){						// if the letter is '@'
	    		printf("%d: %s \n",c,str);			// print the string
	    		c++;								// increment a counter
	    		continue;							// continue for next line
	    	}
	      }
	   }while( !feof(fp) );							// check for end of file
	fclose(fp);										// close the file
	printf("There are %d number of emails in this file", c-1);
	return 0;										// print the number of email addresses found
}
