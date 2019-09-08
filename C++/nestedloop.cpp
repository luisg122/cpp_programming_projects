//counting a number's digits
#include<iostream>
using namespace std;

int main(){
	//it's all about computational syntax
	int nr = 0; //4 digits
	
	//when the data type in declaring a variable is int, dividing numbers that are bound to have decimals, ALWAYS gets round down
	/*cout << 1234/10 << endl; //it takes four operations to get to zero: for a four-digit number
	cout << 123/10 << endl;		//hence, this would explain the while loop
	cout << 12/10 << endl;		//algorithmically if it reaches 0, the last digit is obtained 
	cout << 1/10 << endl;		//execution of while loop stops at 0 
	*/
	cout << "Enter a number: ";
	cin >> nr;
	
	int temp = nr; //not supposed to actually compute nr, that's why you need a temp variable 
	int nrOFDIGITS = 1; //initializing matters 
	while (temp /= 10) // nr= nr/10 : operation and assignment operator only works for VARIABLES
		nrOFDIGITS++;
	
	if (nrOFDIGITS == 1) cout << "the number " << nr << " has " << nrOFDIGITS << " one digit" << endl;
	
	else cout << "the number " << nr << " has " << nrOFDIGITS << " digits" << endl;
	

	return 0;
}
