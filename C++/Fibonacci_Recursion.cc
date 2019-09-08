#include<iostream>

using namespace std;

int fib(int n){
	
	//if(n == 0) return 0;
	//if(n == 1) return 1;
	//else       return fib(n - 1) + fib(n - 2);
	return n <= 1 ? n : fib(n - 1) + fib(n - 2); 
	//1 1 2 3 5 8 13 21 34 55
	// 0 1 1 2 3 5 8 13 21 34 55 (considered the FIRST terms sequence)
}

int main(){
	
	int n = 0;
	cout << "Enter number of terms for Fibonacci Series: ";
	cin  >> n;
	cout << "Fibonacci(" << n << " terms excluding the 0 term ) = " << fib(n) << endl; 
	
	
	return 0;
}
