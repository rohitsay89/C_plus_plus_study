/*
* Program to just define a class for an unsigned counter and 
* change its values using different functions
*/
#include <iostream>
using namespace std;

class CounterType{                                              /* Class */
public:
	unsigned int count;
	void set(unsigned int arg);
	void inc();                                                   /* Mutator function for increment */
	void dec();                                                   /* Mutator function for decrement*/
	unsigned int ret();                                           /* Accessor function */
	void out();                                                   /* Accessor function for console ouput */
};

void CounterType::set(unsigned int arg){
	count = arg;
}
void CounterType::inc(){
	count = count + 1;
}
void CounterType::dec(){
	count = count - 1;
	if(count < 0){
			cout << "Count becoming -ve so adding 1 now" << endl;
			count = count +1;
		}
}
unsigned int CounterType::ret(){
	return count;
}
void CounterType::out(){
	cout << "The present value of count is: " << count << endl;
}
int main(){
	CounterType type1;
	unsigned int x = 0;
	type1.set(5);
	//cout << "the count value is :" << type1.count << endl;
	type1.set(500);
	type1.inc();
	//type1.dec();
	x = type1.ret();
	cout << "the count return value is :" << x << endl;
	type1.out();
	return 0;
}
