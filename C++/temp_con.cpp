#include<iostream>
using namespace std;
//const double kelvin_c = 273.15;


int main(){
	
	double first = 0.0; 
	
	cout << "Temperature Conversion: Kelvin, Celsius, Fahrenheit \n\n\n";
	
	cout << "Key:\n\nk(Kelvin)\nc(Celsius)\nf(Fahrenheit)\n";	
	cout << "\n";
	cout << "Choose one metric: ";
	
	
	char decision_1;
	cin >> decision_1;
	
	cout << endl;
	
	switch(decision_1){
		
		case 'k':
		 	cout << "Value in Kelvin: ";
			cin >> first;
			break;
		case 'c':
			cout << "Value in Celsius: ";
			cin >> first;
			break;
		case 'f':
			cout << "Value in Fahrenheit: ";
			cin >> first;
			break;
		default: // executed when none of the 'cases' can be executed
			cout << "You typed the wrong character!" << endl;
			
	}
	//corresponding char numerical value to a character from ASCII
	
	/*if (decision_1 == 107) {
		cout << "Value in Kelvin: ";
		cin >> first;
	}
	
	else if(decision_1 == 99){
		cout << "Value in Celsius: ";
		cin >> first; 
	}
	
	else { 
		cout << "Value in Farenheit: ";
		cin >> first; 
	}	
	*/
	
	cout << "\nChoose ANOTHER metric for conversion: ";
	
	char decision_2;
	cin >> decision_2;
	
	cout << endl;
	
	cout << "Conversion from " << decision_1 << " to " << decision_2 << " is ";
	
	if (decision_1 == 102 || decision_2 == 99){ //conversion (f to c)
		
		cout << double((first - 32)*(5.0/9)) << endl;
		
		
	}
	
	if (decision_1 == 99 || decision_2 == 102){ //conversion (c to f)
		
		cout << (double(first*(9.0/5) + 32)); 
		
		
		
	}

	if (decision_1 == 99 || decision_2 == 107){ // conversion (c to k)
		
		cout << (double(first + 273.15));
		
	}








}
