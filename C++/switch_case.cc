//introducing switching cases, break function
#include<iostream>
using namespace std;

int main(){

	int x = 50;

	//string cannot b e used in switch cases
	switch (x) //variable x = 50, therefore case 50 is executed, and it executes every instruction until it meets curly bracket therefore it must be met with 'break instruction'
	{
		case 0:
			cout << "this is a place for the instructions that will be executed when switched value is equal to zero" << endl;
			break;
		case 25:
			cout << "this is a place for the instructions that will be executed when switched value is equal to 25" << endl;
            break;
		case 50:
			cout << "this is a place for the instructions that will be executed when switched value is equal to 50" << endl;
            break;
		default:
			cout << "this is a place for the instructions that will be executed when value of switched variable is not equal to any case" << endl;
	}



	return 0;
}
