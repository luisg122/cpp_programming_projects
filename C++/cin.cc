//cin with extraction operator
#include<iostream>
using namespace std;
int main(){
	
	/*int a;
	cin >> a; //CONSOLE INPUT
	
	cout << "Variable named a=" << a << endl;*/
	
	string name, surname, completename;
	
	cout << "Enter your name: ";
	cin >> name;
	
	cout << "Enter your surname: ";
	cin >> surname;
	
	completename= "Welcome " + name + " " + surname + "!!!!";
	cout << completename << endl;
	
	
	
	return 0;
	
	
	
	
	
}
