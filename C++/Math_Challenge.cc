#include<iostream>
#include<cmath>
using namespace std;
int g(int n){
	if(n == 0) return 1;
	else return g(n - 1)+ pow(n,2);
	//recursion, invoked function acts like an accumulator
	//similar to an accumulator in iteration 
	
}
int main(){
	int a,b,c,d;
	int n = pow(10,3);
	cout << g(100);
	
	
	
	
	return 0;	
}
