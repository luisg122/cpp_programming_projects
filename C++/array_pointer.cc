//pointers to arrays
//symbiotic relationship, they are more or less the same thing
//both coonsist of memory address, or references, and indexes
//there is SUCH a thing known as pointer arithmetic for manipulating cell of array

#include<iostream>
using namespace std;
void Display(int *arr, int n){
	for(int i = 0; i < n; i++){
		cout << arr[i] << " ";
	}
	
}

int main(){
	
	int a[10];
	int *p = a;
	for(int i = 0; i < 10; i++){
		 p[i] = i + 1;				//MUST ASSIGN values of array prior to manipulating cells of array
		 cout << p[i] << " ";
		
	}
	cout << endl;
	Display(a, 10);
	return 0;
}
