#include<iostream>
using namespace std;

void bubbleSort(int *a, int n){
	for(int i = 0; i < n; i++){
		for(int j = 1; j < n - i ; j++){
			int temp = 0;
			if(a[j - 1] > a[j]){
				temp = a[j - 1];
				a[j - 1] = a[j];
				a[j] = temp;
			}
		}
	}
}

void print(int *a, int n){
	for(int i = 0; i < n; i++){
		cout << (i + 1) << ") " << a[i] << endl;
	}
}



int main(){

	int arr[] = {1,2,4,12,4,3,1,9};
	int n = sizeof(arr)/sizeof(*arr);
	bubbleSort(arr, n);
	print(arr, n);

	return 0;
}




