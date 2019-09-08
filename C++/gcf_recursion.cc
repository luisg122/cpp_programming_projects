// GCF function program : Recursion version: Euclid's Method
#include<iostream>
using namespace std;
double gcf(int a , int b){

	if(b==0) return a;
	else return gcf(b, a%b); //Euclid's Algorithm

}
int main(){

	cout << gcf(4140,2976) << endl; //random input values
	return 0;

}
