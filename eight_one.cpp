// program to reverse an array
#include <iostream>
using namespace std;

int main ()
{
	char letterBox[4] = {0}, rev[4] = {0};														// declare and array
	int i = 0, r = 0;
	cout << "Program to reverse the characters in an Array. \n";
	cout << "Enter 4 letters from the keyboard. \n";
	for(i=0; i<4; i++)
			cin >> letterBox[i];											// input data for each elemnt of the array

	for(r = 3, i = 0;r>-1 && i<4; r--,i++){									// initialize the proper indices: i for letterBox[], r for rev[]
		rev[r] = letterBox[i];												// copy each element form letterBox[] and put in rev[]
	}
	for(i = 0; i<4; i++)
		cout << "The " << i << " element is :" << rev[i] << endl;		// print hte rev[] array on the screen

	/*int a[10], i=0;
	cout << "Program to enter the values in an Array. \n";
	for(i=0; i<10; i++)
		cin >> a[i];
	for(i=0; i<10; i++)
		cout << "The " << i << " element is :" << a[i] << endl;*/
	return 0;
}
