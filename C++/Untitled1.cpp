//istringstream
#include <iostream>
#include <string>
#include <sstream>
using namespace std;

string addDomain(string s){
	const string domain = "@qc.cuny.edu";
	istringstream iss(s); //using class constructor
	
	return iss.str() + domain;
	
	//string s1;
	//iss >> s1;
	//s1 += domain;
	//return s1;
}



int main(){
	string s = " ";
	cout << "Enter email ID: ";
	cin >> s;
	s = addDomain(s);
	cout << s;
	
	
	return 0;
}
