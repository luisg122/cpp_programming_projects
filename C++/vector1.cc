#include<iostream>
#include<string>
#include<vector>
using namespace std;
//PLEASE study container data types!!

int main(){
	
	vector<int> a;
	for(int i = 1; i <= 5; i++){
		a.push_back(i);
	}	
	for(int i = 0; i < 5; i++){
		cout << a[i];
	}
	a.pop_back();	//pop_back method does not have an argument
	cout << endl;		
	for(int i = 0; i < 5; i++){
		cout << a[i];
		a.pop_back(); //?
	}	
	
	
	return 0;
}
