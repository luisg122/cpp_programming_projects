#include<iostream>
using namespace std;
/* scope /  range of variables */
//global variables can be accessed anywhere 
//local variables an only be accessed withing a functions scope; inside a function bracket
//global and local variables can accessed after they are declared; assigned a datatype and initizialized to a value
int nr;
int globalVariable;
int main(){
	
	int localVariable;
	
	cout << "value of globalVariable: " << globalVariable;
	cout << endl;
	
	cout << "value of localVariable: " << localVariable;	
	cout << endl;
	int a = 10;
	
	if(a == 10)
	{
		int result = a * 10;
		cout << result << endl;
	}
	
 
	
	
	
	
	
	return 0;	
}
