//simple calculator program
#include <iostream>

using namespace std;

int main(){

	beginning: //it allows for the program to "loop" itself
	//system ("cls"); //system 'clear screen'
	cout << "Calculator " << endl << endl << endl;

	double var_1, var_2;


	cout << "Enter first number: ";
	cin >> var_1;

	cout << "Enter second number: ";
	cin >> var_2;

	cout << "What do you want do you want to do with those numbers?" << endl;

	cout << "+(Add)" << endl;
	cout << "-(Subtract)" << endl;
	cout << "*(Multiply" << endl;
	cout << "/(Divide)" << endl;

	char decision;
	cin >> decision;
	//system ("cls"); //system 'clear screen'

	// when it comes to 'char' space matters in terms of the value it takes
	switch (decision){

			case '+':
				cout << var_1 << " + " << var_2 << " = " << (var_1 + var_2) << endl;
			break;
			case '-':
				cout << var_1 << " - " << var_2 << " = " << (var_1 - var_2) << endl;
			break;
			case '*':
				cout << var_1 << " * " << var_2 << " = " << (var_1 * var_2) << endl;
			break;
			case '/':
				if(var_2 != 0) cout << var_1 << " / " << var_2 << " = " << (var_1 / var_2) << endl;

				else cout << "You can't divide by 0" << endl;
			break;
			default: // executed when none of the 'cases' can be executed
				cout << "You typed wrong operation character!" << endl;

	}
	char decision2;

	cout << "Do you want to continue that program? (Y/N):";
	cin >> decision2;

	if(decision2 == 'y' || decision2 == 'Y')
		goto beginning;



	return 0;
}
