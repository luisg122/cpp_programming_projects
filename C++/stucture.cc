#include<iostream>
#include<cstdlib> //standard c++ library with similar c-conio library functionalties
#include<string>
using namespace std;


struct personalData{
	string name;
	string surname;
	string telephoneNum;
	short age;
	
	
	
};

int main(){
	
	int n = 0, i = 0;
	cout << "How many people would like to register onto the system?: ";
	cin  >> n;
	cout << "\n\n\n";
	
	personalData person[n];	//using a user-defined data-type
	
	for(i = 0; i < n; i++){
	
		
		
		cout << "Enter First Name: ";
		cin  >> person[i].name;
		cout << "Enter Last Name: ";
		cin  >> person[i].surname;	 
		cout << "Enter Telephone Number: ";
		cin  >> person[i].telephoneNum;
		cout << "Enter Age: ";
		cin  >> person[i].age;
		
		system("cls");
	}	
	
	return 0;	
}


	/*
		cout << "------------------------------------\n";
		
		
		cout << "Here is " << person[i].name << " " << person[i].surname << "'s contact information\n";
		cout << "Phone Number: " << person[i].telephoneNum << endl;
		cout << "Age: "<< person[i].age << endl;
		
		
		cout << endl << endl;
	*/
	
