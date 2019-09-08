// C++ program to print reverse of a string
//#include <bits/stdc++.h>
//#include <string>
//Clearing the buffer
#include <iostream>
#include<string>
using namespace std;

// Function to reverse a string
void reverse(string &str)       //want to change the value of a variable, DO NOT PASS IT BY VALUE, simply pass it by reference
{
   for (int i = str.length() - 1; i >= 0; i--) // substracting the NULL terminator
      cout << str[i];
}

// Driver code
int main()
{
	cout << "STRING REVERSAL PROGRAM\n";
	string s;
	do{

    	cout <<  "\nINPUT A STRING (ENTER to quit): ";
		getline(cin, s);    //clears buffers in strings

		reverse(s);
		cout << endl;
	}
	while(s.size() != 0);

	return 0;
}
