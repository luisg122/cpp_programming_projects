
//BUBBLE SORT
#include<iostream>
using namespace std;
void bubble(int *a, int n); // REMEMBER:array parameters are converted/or passed POINTERS
void print (int *a, int n);
void swap(int &a,int &b);   // passing by reference, exact copies/ADDRESS of variables
int main(){

	int a[8]= {1,2,4,13,6,9,23,12};
	bubble(a, 8);
	print(a, 8);

	return 0;
}
//pointers and references
void swap(int *a,int *b ){
	int t = *a;				// no point of dereferencing, just write a variable letters without the asterisk
							// passing by reference, passing exact copies/ADDRESS of variable
							// it does implicit dereferencing
	*a = *b;
	*b = t;
}

void bubble(int *a, int n){	    		    //why does this sorting algorithm work?

	for(int i = 0; i < n - 1; i++){		    //each step, stepping into the cells of array
		for(int j = 0; j < n - i - 1; j++){	//each two elements; previous and the next one; comparison =  number of cells; inputting correct value

			if(a[j + 1] < a[j]){		    //condition for swap and reorganizing data in sequence; ascending order value
				swap(&a[j + 1], &a[j]);
			}
		}

	}

}

/*void bubble(int *a, int n){

	for(int i = 0; i < n; i++){
		for(int j = 0; j < n - 1; j++){

			if(a[j] > a[j + 1]){
				swap(a[j], a[ j + 1]);
			}
		}

j	}
*/
void print(int *a, int n){

	cout << "<";
	for(int i = 0; i < n; i++){
		cout << a[i] << " ";
	}
	cout << "> ";
}
