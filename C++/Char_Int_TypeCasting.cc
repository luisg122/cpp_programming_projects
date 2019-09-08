#include<iostream>
using namespace std;

int main(){
	
	string a = "39";
	for(int i = 0;i< a.size(); i++){
		char a1 = a[i] + a[i++];
		cout << a1;
		//int chi = (int)a1;		//typecasting conversion
	
	}
	return 0;
}
