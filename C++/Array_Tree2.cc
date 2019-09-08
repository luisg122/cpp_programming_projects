#include <math.h>
#include<iostream>
using namespace std;   
void printSpace(int count){
    for (int x = 0; x < count; x++) {
        cout<<"-";
    }
}
void printHeap(int heap[], int size){
    
    int height = ceil(log(size)+1); //+1 handle the last leaves
    int width  = pow(2, height)*height;
    int index = 0;
    for (int x = 0; x <= height; x++) { 		//for each level of the tree
        for (int z = 0; z < pow(2, x); z++) { 	// for each node on that tree level
            
			int digitWidth = 1;
            if(heap[index] != 0) digitWidth = floor(log10(abs(heap[index]))) + 1;
            printSpace(width/(pow(2,x))-digitWidth);
            if(index < size) cout << heap[index++];
            else cout << "-";
            printSpace(width/(pow(2,x)));
        }
        cout << endl;
    	cout << endl;
	}
}
int main(){
	int a[260];
	for(int i = 0; i <= 18; i++){
		a[i] = i;
	}
	
	printHeap(a , 19);

	return 0;
}
