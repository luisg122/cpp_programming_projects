//operators
#include<iostream>
using namespace std;
int main(){

	int a =10;
	int b =4;

	cout << a + b << endl; //addition operation
	cout << a - b << endl;
	cout << a * b << endl;
	cout << a/b << endl;
	//when we divide two integer numbers the result will always be an integer and it rounds down
	//example
	double c=3;
	double d=4;
	cout << c/d << endl;

	//10/4 = 2.5
	//10% 4= 5
	//remainder operator or modular operator only gives the number's remainder
	//what amount is left over after the division of two integers
	cout << a % b << endl; //modular operator does work on variables of type 'double'


	return 0;






}
