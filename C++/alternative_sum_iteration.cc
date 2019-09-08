//alternative_sum iteration 
#include<iostream>
using namespace std;
double f(int n){
	
	double s=0.0; // must provide initialization/declaration of summation variable 
	for(int i= 1; i<=n; ++i){
		
		if(i%2==1) s+= 1.0/i; //addition sign before the odd fraction
		else s-= 1.0/i; //subtraction before the even fraction
		
	}
	return s;
	
}




int main(){
	
	cout << f(10) << endl;// calling function j
	return 0;
	
}
