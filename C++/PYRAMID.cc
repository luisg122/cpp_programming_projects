//Printing a pyramid, by using a for-loop

#include<iostream>
#include<cstdlib>
using namespace std;

int main(){
	for(int i = 1; i <= 5; i++){			//NO WONDER THIS IS REFERED TO AS ROW!!!!!
		for(int j = 0; j < i; j++){			//NO WONDER THIS IS REFERED TO AS COLUMN!!
			cout << j;
		}
			cout << endl;					//END LINE AFTER FIRST-OUTER loop is processed
											//and continue to do so after FIRST-OUTER
											//loop is FULLY processed 
	}
	
	cout << "\n\n\nPRESS ANY KEY TO EXIT PROGRAM ....";
	getchar();
	return 0;
}



