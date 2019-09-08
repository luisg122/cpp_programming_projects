#include<iostream>
#include<cstring>
//do arrays and pointers achieve the SAME thing?
//why do arrays get converted into pointers when they're function parameters?
using namespace std;

int main(){
	//does string <identifier = char * <identifier>
	char s[] = "HELLO WORLD"; //strlen also takes into account space, and enumeratese it 
	char *S = "HELLO WORLD";
	int a = strlen(s);
	a     = strlen(S);
	//cout << a;
	int b = a;
	if(a == b) {
		cout << *(s);
		cout << s[1];
		cout << *(s+2);
		cout << s[3];
		cout << *(s+4);
		cout << s[5];
		cout << *(s+6);
		cout << s[7];
		cout << *(s+8);
		cout << s[9];
		cout << *(s+10);
		cout << s[11] << "!\n";
	}
	return 0;
}
