#include<iostream>
#include<string>

using namespace std;
//are these global variables ?

string tens_name[] = {"", "","Twenty ", "Thirty ", "Forty ", "Fifty ", "Sixty ", "Seventy ",
"Eighty ", "Ninety "};

string units_names[] = {"","one","two", "three", "four","five","six","seven","eight", "nine"};

int main(){

	int n = 0;
	
	cout << "Enter a number from 20 to 99:" ;
	cin >> n;
	
	
	while (n < 20 ) {cout << "Enter a number from 20 to 99:";
	cin >> n;}
	
	int tens_digits = n/10; //no double meaning no decimal, hence, round-down 
	int units_digits = n%10;
	cout << "The number you entered was ";
	cout << tens_name[tens_digits] + units_names[units_digits];
	
	return 0;

}

