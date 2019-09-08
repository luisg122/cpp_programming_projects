#include<iostream>
//#include<bits/stdc++.h>

using namespace std;

int main(void){

	//working with bits ==> bitwise operators

	//int a = 3, b = 6;
	int a = 0, b = 0;
	cout << "a: ";
	cin  >> a;
	cout << "b: ";
	cin  >> b;

	cout << "Bitwise operations: AND(&), OR(|), XOR(^)\n";

	//therefore
	int x = a & b;      //counts the positions of a binary number if true: ONLY true when both values are true,  otherwise false
	int y = a | b;      //counts the positions of a binary number if true: ONLY False when both values are false, otherwise true
	int z = a ^ b;      //counts the positions of a binary number if true: ONLY True when ONLY ONE value is true, otherwise false

	cout << "AND:\t(a & b) = " << x << endl
		 << "OR:\t(a | b) = "  << y	<< endl
		 << "XOR:\t(a ^ b) = " << z << endl;


	return 0;
}
