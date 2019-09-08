//iterator-based iteration is better than index-based iteration

#include<iostream>
using namespace std;
int main(){
	
	for(int i= 1; i<= 3; ++i){				//for every row
		for(int j = 1; j <= 3; ++j){		//iterate for every column, meaning one row has x-amount of coloumns
											//depending on the index of the nested second for-loop
			for(int k = 1; k <= 3; ++k){
				cout << k << " ";			
											//if there is a triple for-loop( VERY RARE, but fun), the first
											//for-loops loops the following two loops
			}								//the second loops now acts as a loop for every row
			cout << endl;					//whilst the second loop acts as a loop for every column
		}		
		cout << endl;
	}
	return 0;	
}
