//condition operator ===>>> (_)?_:_
#include <iostream>

using namespace std;

main(){
	
	int a  = 50;
	int b = 50;
	//CONDITION ? so instruction that will be executed if condition is true : if condition is not true  
	string message = (a > b) ? "a > b": "a <= b";
	//  (? == if)  'a > b' then assign 'a > b' to variable 'message' (: == else) assign 'a <= b' to variable'message'  
							
							
	
	cout << message << endl;
	
	//example of CONDITION statementusing CONDITION operator
	
	cout << (( a > b ? a : b) + 10);
	
	
	
	
	
	
	
	
	
	
	
}
