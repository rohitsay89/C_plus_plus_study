
// C++ Program to Display Prime Numbers Between Intervals by Making Function
/*
#include<iostream>
using namespace std;

void fun(int &n1, int &n2){ // function for printing all the prime numbers between n1 and n2
	for(; n1<n2; n1++){
		if(n1%2 != 0){ // check for 2
			if(n1%3 != 0){ // check for 3
				if(n1%5 != 0){ // check for 5
					if(n1%7 != 0){ // check for 7
						cout << n1 << " " << endl; // if found prime, just print it on the screen
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
			continue; // else continue with the next number n1++
	}
}

int main(){
	int n1 = 0, n2 = 0;
	cout << "Enter the first number :" << endl;
	cin >> n1; // first number
	cout << "Enter the second number :" << endl;
	cin >> n2; // second number
	fun(n1, n2); // pass then numbers by reference
	return 0;
}
*/
// C++ Program to Check Prime and Armstrong Number by Making Function

// C++ program to Check Whether a Number can be Express as Sum of Two Prime Numbers
// credit to Dheerendra Panwar also
#include <iostream>

using namespace std;
int arr1[20]; // global array declare
int arr2[20]; // global array declare
void prime(int n){
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
		cout << "The num is : " << arr1[j] << endl;
		//cout << "The num is : " << arr2[j] << endl;
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
				cout << "Sum found !! :" << arr1[i] << " + " << arr2[j] << " = " << num << endl;
				// if true then print the array elements on the screen
			}
			else
				continue;
		}
	}
}

int main(){
	int num = 0;
	cout << "Enter a number : " << endl; // input the number from user
	cin >> num;
	prime(num); // store all the prime numbers in an array from 0 to given number
	find_prime(num); // find the combination of sum of array elements for prime numbers
	return 0;
}
