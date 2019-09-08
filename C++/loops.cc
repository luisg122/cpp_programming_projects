//loops 
#include<iostream>
using namespace std; //what exactly is a 'namespace'

int main(){
	/*
		for (intialization; condition; inc/dec)
	*/
	
	/*for (int i = 0; i < 3; ++i)	//standard notation of a for-loop structure
	//execution will be made if condition is met 
	{
		cout << i << endl;
		
	} // loops are meant for convenience, "autpmated repetitions 
	cout << "lalalal" << endl;
	*/
int array[100];

for (int i = 0; i < 100; ++i)
{ 	array[i] = 0;
	cout << i << endl;
} //0,1,2,3 == >> element of array[4]

for (;;) //infinite loops
cout << "lalal" << endl;


return 0;	
}
