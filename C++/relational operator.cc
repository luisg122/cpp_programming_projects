//relational operators; operators with relations or conditions 
#include<iostream>
using namespace std;
int main(){
	int a = 10;
	int b = 5;
	
	//EXAMPLES OR RELATION OPERATORS: RELATIONAL meaning 'CONDITIONAL'
	
	cout << (a==b) << endl;// true (1) when both variables have the same values 
	
	cout << (a!=b) << endl;//true (1) when both variables DO NOT have the same values or are not equal to each other 
	
	//insertion (cin) and exctraction (cout) are operators
	
	cout << (a > b) << endl;//true (1) when value of var 'a' is greater than value of variable 'b'
	
	cout << (a < b) << endl;//true (1) when value of variable 'a' is less than value of variable 'b'
	
	cout << (a >= b) << endl;// true (1) when 'a' is greater than or equal to 'b'
	
	cout << (a <= b) << endl;//true (1) when 'a' is less than or equal to 'b'
	
	cout  << !(a == b) << endl; // a is not equal making the condition true; it constrasts to the first condition 
	
	
	
	return 0;
	
	
	
	
	
}
