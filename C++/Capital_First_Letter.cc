#include<iostream>
#include<string>
#include<cstring>
using namespace std;

int main(){
	
	string str = "something";
	str[0] = toupper(str[0]);
	
	cout << str << endl;
	
	return 0;
}
