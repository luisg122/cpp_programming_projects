#include<iostream>
using namespace std;

void printFib(int n){
	static int n1 = 0, n2 = 1, n3 = 0;
	if(n > 0){
		n3 = n1 + n2;
		n1 = n2;
		n2 = n3;
		cout << n3 << " ";
		printFib(n -1);
	}
}
int main(void){
	int n = 0;
	cout << "Enter number of elements: ";
	cin  >> n;
	cout << "Fibonacci Series: ";
	cout << "0" << " 1 ";
	printFib(n - 2); //n-2 because 2 numbers are already printed
	
	
	return 0;
}
