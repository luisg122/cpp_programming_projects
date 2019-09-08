#include<iostream>
using namespace std;

void double_it(int *a,int n);
void print (int *a, int n);
int main(){


	int a[3]= {2,5,7};
	double_it(a, 3);				//technically passing by refernce, but for an array
									//it's implicit == > &(a[0]), obtaining address of first cell
									//otherwise known as the offset!!!
	print(a,3);
	
	return 0;
}



void double_it(int *a, int n){
	
	for(int i = 0; i < n; i++){
		
		a[i] = 2*a[i]; 				//data transfer always from right to left
									//a[i] is not acting some sort of accumulator 
		
	}
	
	
}

void print(int *a, int n){
	
	for(int i = 0; i < n;i++){
		
		cout << a[i] << "\t ";
		
	}
	
}
