#include<iostream>
//#include<conio.h>
using namespace std;

void accumulator(int x);  //function prototype

int main(){
	
	int n = 0;
	
	cout << " Input number, n, and all the numbers spanning from 1 to n, will be added: ";
	
	cin >> n;
	
	cout << "\n\n Answer: ";
	accumulator(n);
	
	return 0;
}


void accumulator(int x){
	
	int sum = 0;
	
	for (int i = 0; i <= x; i++){
		
		sum += i;
	}
	cout << sum;
}
