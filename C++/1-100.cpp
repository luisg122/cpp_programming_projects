#include <iostream>
using namespace std;
int numbers(int k );
int main(){
	
		
		int n = 0;
		cout << "Enter number: ";
		cin >> n;
		int i = 0;
		while (i <= n){
			cout.width(4); //to produce even space between number printed on console
			cout << i << " ";
			++i;
		}
	
	
	return 0;
}
	
	
	


