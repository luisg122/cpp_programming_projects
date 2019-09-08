//arrays
#include <iostream>
using namespace std;

int main(){
	
	int a;
	/* int a,b,c,d,e .....
	   int var_1,var_2,var_3 ...
	   what happens if you want 1000 varibables?
	*/
	// must keep in mind the compiler allocates memory 
	// TYPEofvariable NAMEofvariale[SIZE_NR_OF_ELEMENTS]
	//array is a series of elements of the same type
	// they are placed in memory that way there are no other 
	//things stored between array's values
	//for an array, we are "exanding memory" upong the memory that is normally allocated 
	//to a type of variable
	cout << "array[3] = [10][20][30]" << endl;
	int arr[3]; //example of an array 
	arr[0] = 10; //arrays are by default indexed at 0
	arr[1] = 20;
	arr[2] = 30;
	
	cout << "array [0] = " << arr[0] << endl;
	cout << "array [1] = " << arr[1] << endl;
	cout << "array [2] = " << arr[2] << endl;
	
	
	return 0;	
}
