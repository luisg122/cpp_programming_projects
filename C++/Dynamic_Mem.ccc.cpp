#include<iostream>
using namespace std;
void callFunction(int *a, int n);

int main(){
	
	//int *pInt = new int[10];
	int LInt[10];
	int *pInt = LInt;
	for(int i = 1; i < 10; i++){
		 //pInt[i] = i;
		 //cout << *(pInt++ ) << "->";
		 pInt[i] = i;
		 cout << pInt[i] <<  " -> " ;		
	}
	//pInt[9] = 10;
	//cout << pInt[9] << endl;
	cout << 10 << endl;
	
	callFunction(LInt, 10);
	
	return 0;
}

void callFunction(int *a, int n){
	for(int i = 1; i < n; i++){
		cout << a[i] << " -> ";
	}
	cout << 10 << endl;
}
