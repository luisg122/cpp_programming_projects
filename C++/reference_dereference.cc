#include<iostream>
using namespace std;

int main(){

	/*Dereferencing a pointer means getting the value that is stored in
    the memory location pointed by the pointer.
	The operator * is used to do this, and is called the dereferencing operator.*/
	int a = 5;
	int *ptr = &a;
	//*ptr = 6;    passing by reference allows you to obtain the address, and modify the value inside that memory address

	cout << *ptr << endl; //returns variable 'a' value 5, is this considered to be dereferencing?

	cout << ptr << endl; // returns the address of int variable 'a'



}
