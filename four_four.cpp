// Program for converting feet & inches to Meters and Centimeters

#include <iostream>

using namespace std;
/* Function prototypes */
void input(int& ,int&);				/* function for taking input from user, call by referance */
int conv(int, int, int&, int&);			/* for converting to meter and cm */
void output(int, int);				/* printing on the screen, call by value */
char end = 's';

int main(){
	int ft=0, in=0, mt=0, cm=0;
	cout << "Program for converting feet & inches to Meters and Cm " << endl;
	do{
		input(ft, in);			/* a do-while loop: run the code till the user wants, exit if pressed 'e' */
		conv(ft, in, mt, cm);
		output(mt, cm);
	}while (end != 'e');			/* check the user input: if 'e' exit the loop */
	return 0;
}

void input(int& ft, int& in){
	cout << "enter the length of Feet :" << endl;
	cin >> ft;				/* Enter the values from user */
	cout << "enter the length of Inches :" << endl;
	cin >> in;
}

int conv(int ft, int in, int& mt, int& cm){
	int c;
	c = (ft * 0.3048)*1000;
	mt = c/1000;
	cm = c%1000;				/* Convert the values */
	return 0;
}

void output(int mt, int cm){
	cout << "the value in Meters is :" << mt << endl;
	cout << "the value in Centimeters is :" << cm << endl;
	cout << "Press 'e' to end and s to continue :" << endl;
	cin >> end;				/* record the user choice */
}
