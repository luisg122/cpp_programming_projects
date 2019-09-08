
//C++ is a strongly typed language meaning data types assigned to variables must be consistent throughout program
//alternative_sum recursion
#include<iostream>
#include<cmath>
using namespace std;
double f(double n); //function prototype
int main(){

	cout << f(10) << endl; // for input of function



}
double f(double n){

	if(n == 1.0) return 1.0;

	//alternative sum code
	//else if (n%2.0 == 1) return f(n-1.0) + 1.0/n;  // if odd, add, also please note that %(modulus operator only works for integer data types
	
	double z = fmod(n,2.0); // fmod is the equivalent of modulus but for double data types
	if (z == 1) return f(n-1.0) + 1.0/n;
	else return f(n-1.0) - 1.0/n;              // if even, subtract
}
