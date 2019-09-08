//more types of variables

#include<iostream>
using namespace std;
int main(){
	
	//Type_of_Variable nameofvariable
	//Type_of_Variable nameofvariable1, nameofvariable2, nameofvariable3;
	//all variables are memory boxes
	//all variables have addresses
	//address consist of wierd numbers and letters, and they are hexidecimal code
	//all variables are different
	//allocating reserves space or memory for a variable
	//allocating an address to the variable
	//reserve the space for the variable
	
	int a=40,b=0,c=20;//-2billion to 2 billion; 4 BYTES for integer type
	//all datatypes are constrained by specific standards of memory
	
	cout << "a: " << a <<" address: " << &a << endl;
	cout << "b: " << b << " address: " << &b << endl;
	cout << "c: " << c << " address: " << &c << endl;
	
	short int t1=5; // -32768 to 32767; 2 BYTES
	
	cout << t1 << endl;
	
	float t2 =5.12; //4 BYTES nr that are to 38 zeros
	double t3=5.12; // 8 BYTES nr thaht are p to 308 zeros 5.61235123512351
	
	cout << t2 << endl;
	cout << t3 << endl;
	
	char t4; // character
	
	t4 = 'a';
	cout << t4 << endl;
	
	string t5 = "Hello World! :-)";
	
	cout << t5 << endl;
	 
	//combining two different strings
	
	string x = "combining ";
	string y = "strings!!!";
	string combinedStrings= x+y;
	
	cout << combinedStrings << endl;
	
	//boolean | true or false
	bool t6 = true;
	cout << t6 <<endl;
	//true is '1' and false is '0'
	//every other number is true
	
	//for unsigned short int 0 to 65535	===> only outputs or yields numbers that are not negative
	unsigned short int t7 = 3700;
	cout << t7 << endl;
	
	//constant or const. 
	//constant variables makes a value unchangeable and it is meant to be used many times
	
	const string NAMEOFGAME = "Conqueror of c++"; //variable of type string cannot be changed 
	cout << NAMEOFGAME << endl;
	
	
	
	
	return 0;
	
}
