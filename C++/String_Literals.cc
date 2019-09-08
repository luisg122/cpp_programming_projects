//difference between char *s and char s[]
//WHAT IS A NAMESPACE??
#include<iostream>
#include<string>
#include<cstring>
using namespace std;
int main(){
	
	//the contents of arrays are always modifiable
	char s[] = "Hello World";
	char v[] = {'H','e', 'l','l','o', ' ',
				'W','o','r','l','d', '\0'};
				
	cout << s;
	cout << endl << v;
	cout << endl << sizeof(s);
	cout << endl << sizeof(v);
	
	char *s1 = "Hello World";
	cout << endl << s1;
	
	
	
	return 0;
}
