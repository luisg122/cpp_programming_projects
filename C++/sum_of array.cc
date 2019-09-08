#include<iostream>
using namespace std;

int main(){
	
	int n = 15;
	double arr[n]= {};		//arrays only take type integer as size for input? MAKES SENSE
	
	for(int i = 0.0,  j = 1.0; i < n, j <= n; i++, j++){
		cout << j << "> "; 
		cin  >> arr[i];
	}
	
	double s = 0.0;
	for(int i = 0; i < n; i++){
		s += arr[i];
	}
	
	cout << (s);
	
	return 0;
}

