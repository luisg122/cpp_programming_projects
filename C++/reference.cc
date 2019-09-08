//reference
#include<iostream>
using namespace std;
/*reference variable*/
int main(){
	string name = "Agnus";
	cout << "Value of Variable: " << name << " address of Variable is: " << &name << endl;
	//reference variable is like a nick-name


	const string &nr_6 = name; //reference associated with a variable, and reference variable cannot change or "update" assignment values as it is declared with const(constant)
	//&nr_6 is a reference to the variable name
	//&nr_6 is like a nickname to variable name

	cout << "Value of Variable: " << nr_6 << " address of Variable is: " << &nr_6 << endl;
																			//dereferencing; want to get the address of the variable
	name = "Scott";

	cout << "Value of Variable: " << name << " address of Variable is: " << &name << endl;
	cout << "Value of Variable: " << nr_6 << " address of Variable is: " << &nr_6 << endl;

	/*
		Reference Variable must be initialized when created
		Reference Variable can't change associations/ connections
		Reference Variable must be the same type as associated variable
	*/





	return 0;









}
