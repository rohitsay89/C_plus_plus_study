  #include <stdio.h>
  #define min(a, b)	((a<b)?a:b)			//macro for minimum of 2 numbers //
  int main(){
    int a = 0, b = 0;
  	printf("To find the minimum of two numbers using Macro \n");
  	printf("Enter first number : \n");
  	scanf("%d", &a);
  	printf("Enter second number : \n");
  	scanf("%d", &b);
  	printf("the minimum number is: %d \n", min(a, b));//
	
	return 0;
	}
