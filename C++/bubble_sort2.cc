#include<iostream>
using namespace std;

void read_list(int array[], int array_size);
void print_arr(int array[], int array_size);

int main(){
	
	int array_size;
	
	cout << "How many elements would you like for your array to contain?: ";
	cin  >> array_size;
	
	int array1[array_size];
	
	read_list(array1,array_size);
	print_arr(array1,array_size);
	
	
	return 0;
}


void read_list( int array[], int array_size ) 
{
    int i = 0;
    int x;

    cout<< "Enter list of no more than " << array_size << " integers (0 - exit): ";

    while (i < array_size && x != 0 ) 
    {
        cin >> x;
		array[i++] = x;
		
    }
}

void print_arr(int array[], int array_size){
	
	cout << "[ ";
	for(int i = 0; i < array_size; i++){
		
		cout << array[i] << " ";	
	
	}
	cout << "]";
	
}
