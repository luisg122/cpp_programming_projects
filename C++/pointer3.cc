#include<iostream>
using namespace std;

int main(){

	int a = 2;

	int b = 3;

	int *p = &a;
	//error *p = &b;
	*p += 1;


	cout << a << " = " << b;
	cout << " \n" << b;
	cout << endl;

	 p = &b;             //changing pointer to correspond to b, therefore changing value of b
	*p*= 60;             //dereferencing while changing value corresponding to memory address of variable b

	cout << a << " != " << b;
	cout << "\n" << b;

	return 0;
}



//pointers change value of varaiables in sequence
