#include<iostream>
using namespace std;

int main(){
	
	int a[4]= {1,2,3,4};
	
	int *p = a;
	p = p + 2;  //accessing the third element of array
	
	*p = *p + 8; //dereferncing and adding value to 8
	
	cout << *(a + 2);
	cout << a[2];
	cout << *p;
	
	
	
	
	
	cout << endl;
	
	int b = 7;
	int *z= &b;
	
	*z += 34;
	cout << *z << " = " << b;
	
	
}

//pointer changes the value of corresponding variable, or an elment of it(array) 
