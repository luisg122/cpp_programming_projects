#include<iostream>
#include<vector>
#include<string>
using namespace std;

int main(){
	
	vector <string> tokens;
	string str;
	cin.ignore(1000, '\n');
	while(str.empty()){
		getline(cin, str);
		//if(str.size() == 0) break;
		//else tokens.push_back(str);
	}
	return 0;
}
