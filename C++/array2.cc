//array2
#include<iostream>
using namespace std;

int main(){
	//arrays are indexed, and are indexed at 0 by default 
	//to assign values to arrays, you must index the arra
	//each element in an array has an  'address'
	int array [4];
	//to assign values to values to element of an array, you must first index an array
	//addresses of each element in an array are expressed in hexadecimal notation 
	//every variable is a "box of allocated memory" and that specific memory has an address
	//to find the address of a variable, or an element of an array, you must use &NAME_OF_VARIABLE
	//try to  understand hexadecimal
	array[0] = 10;
	array[1] = 50;
	array[2] = 256;
	array[3] = 512;
	
	 
	cout << "array [0] = " << array[0] << ", address: " << &array[0] << endl;
	cout << "array [1] = " << array[1] << ", address: " << &array[1] << endl;
	cout << "array [2] = " << array[2] << ", address: " << &array[2] << endl;
	cout << "array [3] = " << array[3] << ", address: " << &array[3] << endl;
	
	//the address of the first element in an array is equal to address of that same variable
	cout << "array [0] = " << array[0] << ", address: " <<	array << endl;
	if( &array[0] == array)
		cout << "that's true" << endl;
	
	return 0;
}
