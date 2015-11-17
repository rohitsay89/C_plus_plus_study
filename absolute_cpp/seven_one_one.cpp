#include <iostream>

using namespace std;

class Month{
public:
	//void read(unsigned short int mn);
	unsigned short int read(char a, char b, char c);
	void month_name(unsigned short int mn);
	Month(char a, char b, char c);

	Month();
	unsigned short int mon;
};

Month::Month(char a, char b, char c){
		if((a=='J')||(a=='j')){				// check for J
			if((b=='A')||(b=='a'))
				mon = 1;					// month is January
			else if((b=='u')||(b=='U')){
				if((c=='N')||(c=='n')){
					mon = 6;				// if true then month is June
				}
				else
					mon = 7;				// else month is July
			}
			else
				cout << "Please insert a valid month letter" << endl;
		}
		else if((a=='F')||(a=='f')){
			mon = 2;						// month is February
		}
		else if((a=='M')||(a=='m')){
			if((c=='r')||(c=='R')){
				mon = 3;}					// month is March
			else{
				mon = 5;}					// else month is May
		}
		else if((a=='A')||(a=='a')){
			if((b=='P')||(b=='p')){
				mon = 4;
			}
			else
				mon = 8;
		}else if((a=='S')||(a=='s')){
			mon = 9;
		}
		else if((a=='O')||(a=='o')){
			mon =10;}
		else if((a=='N')||(a=='n')){
			mon = 11;
		}
		else if((a=='D')||(a=='d'))
			mon = 12;
		else
			cout << "Please insert a valid month letter" << endl;
		cout << "Month number :" << mon << endl;
		month_name(mon);
		//return mon;
}

void Month::month_name(unsigned short int mn){
	switch(mn){
		case 1:
			cout << "January" << endl;
			break;
		case 2:
			cout << "February" << endl;
			break;
		case 3:
			cout << "March" << endl;
			break;
		case 4:
			cout << "April" << endl;
			break;
		case 5:
			cout << "May" << endl;
			break;
		case 6:
			cout << "June" << endl;
			break;
		case 7:
			cout << "July" << endl;
			break;
		case 8:
			cout << "August" << endl;
			break;
		case 9:
			cout << "September" << endl;
			break;
		case 10:
			cout << "October" << endl;
			break;
		case 11:
			cout << "November" << endl;
			break;
		case 12:
			cout << "December" << endl;
			break;
		}
}

int main(){
	int x=0;
	Month m('M','A','Y');
	cout << "Enter the month number :" << endl;
	cin >> x;
	m.month_name(x);
	cout << x;
	return 0;
}
