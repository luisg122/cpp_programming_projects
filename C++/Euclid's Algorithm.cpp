#include"iostream"
#include<cmath>
using namespace std;
void swap(int a, int b);
void gcf_steps (int a, int b);

int main(){
	int a = 0, b = 0;
	cout << "Enter a: ";
	cin  >> a;
	cout << "Enter b: ";
	cin  >> b;
	system("cls");
	cout << "GCF(" << a << "," << b << ") =>" << endl; 
	gcf_steps(a,b);				//cout object does not work on void functions for ouputs
	return 0;
}
void swap(int a, int b){
	
		int t = 0;
		t = a % b;
		a = b;
		b = t;
		cout << "GCF(" << a << "," << b << ") =>" << endl;
		if(b == 0) cout << "\n\nTherefore the GCF is: " << a;
}
void gcf_steps(int a, int b){
	
	do{				
		
		swap(a,b);
		b = a % b;	
		
	}
	while(b);			//if b != 0
	
	
	
}
