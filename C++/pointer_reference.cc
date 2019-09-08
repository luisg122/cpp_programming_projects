#include<iostream>
using namespace std;

int main(){
	
	int b[3] = {1,2,3}; 			//address/offset of array, address of cell 0
	cout << "ADDRESS OF ARRAY(FIRST CELL ADDRESS) B: (" << b << ")" << endl;
//----------------------------------------------------------------------------------------------------	
	int *a = b;							//a POINTER IS A VARIABLE, with its OWN MEMORY ADDRESS;
									    //DANGLING POINTER, not pointing to ANYTHING
	cout << "ADDRESS OF POINTER A: (" << &a  << ")" << endl;
	//cout << a << endl;			    //does the address of a dangling pointer change EVERYTIME?
	
	int **aa = &a;
	cout << "ADDRESS OF POINTER A: (" << aa  << ")" << endl; 
	cout << &aa << endl;
	
	int ***aaa = &aa;
	cout << aaa << endl;	
	
	
	a = b;							//a POINTER CONTAINS AN ADDRESS, an ADDRESS CONTAINING AN ADDRESS
	cout << "ADDRESS OF ARRAY(FIRST CELL ADDRESS) B: (" << a << ")" << endl;				
									//by definition then, pointers are FLEXIBLE, and CHANGE!!
//----------------------------------------------------------------------------------------------------
	
	for(int i = 0; i < 3; i++){
		
		cout << a[i] << "\t";		//a pointer can take the form of an array
									// a form of implicit DEREFERNCING
	}
	cout << endl;
	for(int i = 0; i < 3; i++){
		cout << *(a++) << "\t";		//Pointers can iterate over an array, 
									//we can use ++ to go to the next 
									//item that a pointer is pointing to
									//MUST HAVE AN EXPLICT *(DEREFERENCER) USING 
									//AN INCREMENTING INDEX!! 
	}  
	
	
	
	
	cout << endl;
	for(int i = 0; i < 3; i++){
		cout << a++ << endl;
	}
	
	int d = 3;
	int &c = d;						//unlike, a pointer, a reference HAS to be initialized
									//to some indentifier of the SAME type
	
	cout << c << endl;				//self auto-dereferencing pointer
	
	cout << &d << endl;
	cout << &c << endl;
	
	
	//c = &b;						//COMPILER ERROR!!
	//cout << c;
									//unlike a pointer, a reference 
									//CANNOT be reassigned different addreesses
	
	
		
	return 0;
}
