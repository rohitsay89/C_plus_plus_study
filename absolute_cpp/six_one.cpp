/*Program to find the final grade from different tests
 * Final exam out of 100 points -> counts 50%
 * Mid term exam out of 100 points -> counts 25%
 * quiz1 + quiz2 both out of 10 points -> counts 25% combined
 * */
#include <iostream>
using namespace std;
struct record{									/* Student record structure */
	unsigned short int quiz1;
	unsigned short int quiz2;
	unsigned short int mid_term;
	unsigned short int final;
	float grade;
	float calculate(){
		grade = ((.5*final)+(0.25*mid_term)+(quiz1+quiz2)*0.25);
		return grade;							/* function to calculate grade */
	}
};
int main(){
	float g;
	record student;
	cout << " Program to find the final grade " << endl;
	cout << " Enter the points of quiz 1: " << endl;
	cin >> student.quiz1;
	cout << " Enter the points of quiz 2: " << endl;
	cin >> student.quiz2;
	cout << " Enter the points of mid term test: " << endl;
	cin >> student.mid_term;
	cout << " Enter the points of final test: " << endl;
	cin >> student.final;
	g = student.calculate();
	cout << "The final grade of the student is: " << g << endl;
	return 0;
}
