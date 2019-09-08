#include<iostream>
using namespace std;
int factorial(int n){
	
	if(n == 0) return 1;
	else{	
		int total = 1;
		for(int i = 1; i <= n; i++)	total *= i;		
		return total;	
	}
}


int main(){
	
	int n = 0;
	cout << "Enter a positive integer: ";
	cin  >> n;
	cout << "Evaluating "   << n << "! "
		 << "which equals " << factorial(n) << endl;
	
	return 0;
}





