//reorganizing an array of elements in two variation sequences: least to greatest, and vice-versa
#include<iostream>
#include<cstdlib>
#include<cstdio>
using namespace std;


void bubble (int *a, int n);		//dereferencing first cell of array, and incrementing to other cells and dereferencing other cells
void bubble1(int *a, int n);		//dereferencing first cell of array, and incrementing to other cells and dereferencing other cells
void print  (int *a, int n);		//dereferencing first cell of array, and incrementing to other cells and dereferencing other cells
void swap   (int &a, int &b); 


int main(){
	
	int n;
	
	cout << "Program for restructuring an array into two variation sequences\n\n";
	cout << "How many elements would you like for your array to contain?: ";
	cin  >> n;
	cout << endl;
	
	int a[n];
	
	for(int i = 0; i < n; i++){
	
		cin >> a[i];
		a[i] = a[i];
    }
	
	cout << "Your array is [ ";
	for(int i = 0; i < n; i++){
		cout << a[i] << " ";
	}
	cout << "]\n\n";
	
	cout << "Resturctured array from least to greatest: ";
	
	bubble(a, n);
	print (a, n);
	
	cout << endl;
	cout << "Restructured array from greatest to least: ";
	
	bubble1(a, n);
	print  (a, n);
	cout << "\n\nEXITING PROGRAM . . . ";
	getchar();
	return 0;
}

void swap(int &a, int &b){		//passing by referencing 
	
	int t = a;
	a = b;
	b = t;
}



void bubble(int *a, int n){	   //values are already derefernced
							   //remember for the address of the first cell, or the offset of the array
							   //simply write the array's identifier(var_name), and use a loop to "step through" the array with an INDEX
							   
	for(int i = 0; i < n; i++){			//for each step
		for(int j = 1; j < n; j++){		//each two element previous and next with one step
			if(a[j - 1]  > a[j]){		//left to right ASCENDING order sequence
				swap(a[j - 1], a[j]);
			}
		}
		
	}
}

void bubble1(int *a, int n){   //values are already derefernced
							   //remember for the address of the first cell, or the offset of the array
							   //simply write the array's identifier(var_name), and use a loop to "step through" the array with an INDEX
							   
	for(int i = 0; i < n; i++){			//for each step
		for(int j = 1; j < n; j++){		//each two element previous and next with one step
			if(a[j - 1]  < a[j]){		//left to right DESCENDING order sequence
				swap(a[j - 1], a[j]);
			}
		}
		
	}
}

void print(int *a, int n){
	
	cout << "[ ";
	for(int i = 0; i < n; i++){
		
		cout << a[i] << " ";
	}
	cout << "]";
	
}





