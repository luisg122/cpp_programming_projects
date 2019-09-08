#include<iostream>
using namespace std;

int main(){
	
	int  n = 0; 
	char m = 0;
	 

	
	while(true){
	
		cout << "Input a number: ";
		cin >> n;
		cout << endl;
		
		for(int row = 1; row <= n; row++){
			for(int col = n; col >= 1; col--){
				if(row == col || row == ((n - col) + 1)){	//condition to print two diagonal lines
					 cout << "X";
				}
				//else if(row == 9 || col== 9)cout << "X"; profoundly STUPID CODE
				
				else cout <<  "-";
			
			}
			cout << endl;
		}
		//---------------------------------------------------------------------------
		
		cout << "\nWOULD YOU LIKE TO RUN THIS PROGRAM AGAIN? (Y/N): ";
		cin >> m;
		if(!(m == 'Y' || m == 'y')) break;
		else system("cls");
	}
	return 0;	
}
