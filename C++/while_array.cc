#include <iostream>
using namespace std;

int main(){
	
	const int SIZEOFARRAY = 10;
	int i = 0;
	int array[SIZEOFARRAY];
	
	while ( i < SIZEOFARRAY)
	{
		// execution array: use ++i as parameter
		//printing onto console: use i++ as parameter
		
		
		
		
		array[i] = 10 * i; // PREFIX==>> increments first, then checks // POSTFIX ==>> check first, then INCREMENTS 
		
		cout << array [i++] << endl;
		//++i; // much preferable code//  the console will print the same w/ i++regardless
	
	//	++i or i++ does not matter: however it matters when its treated as a PARAMETER;
	//when ++i or i++ get treated as parameters, the program changes !!	
	
	
	}
	
		
	//do-while loops do not check condition first 		



}
