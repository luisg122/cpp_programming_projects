#include <iostream>
 
using namespace std;
const int MAX = 3;
 
int main () {
   int  var[MAX] = {10, 100, 200};
   int  *ptr = var;									// let us have array address in pointer
   
   //int a = *var + 2;
   //int b = *ptr + 2;
   
 
   for (int i = 0; i < MAX; i++, ptr++) {
      cout << "Address of var[" << i << "] = ";		//how to manipulate memory addresses
      cout << ptr << endl << endl;
 
      cout << "Value of var[" << i << "] = ";
      cout << *ptr << endl << endl;
 		
 		
 	  
      
	  
	  // point to the next location
      
	  //an array name generates a pointer constant(OFFSET), it can still be used in pointer-style expressions
	  //as long as it is not modified
     
   }
   
   return 0;
}
