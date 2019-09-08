//use reference when dealing with arrays?
//passing by value
//passing by reference

//passig by value = pass a copy of variable value to function,
//and therefore cannot change value of variable inside of that function

//passing by reference = pass the variable's address 
//meaning the original variable can be modified inside the function 

#include<iostream>
#include<conio.h>
using namespace std;

void passByValue(int x);
void passByRef(int *x);


int main(){
	int betty =  13;
	int sandy =  13;
	
	passByValue(betty); //passing by value to function = passing a copy of the variable to function, meaning value cannot be modified 
	passByRef(&sandy);  //passing by reference to function = passing address for pointer to reference, and for pointer to modify value
	
	
	cout << "Betty is now " << betty << endl;
	cout << "Sandy is now " << sandy << endl;
	return 0;
}


void passByValue(int x){
	
	x = 99;
}


void passByRef(int *x){
	
	
	*x = 69;
}
