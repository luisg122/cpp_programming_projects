#include<iostream>
using namespace std;
int multi(int j, int h);
int main(){
	
	//external for-loop is responsible for the length of the column 
	//internal for-loop is reponsible for the length of the row 
	
	//external for-loop or the first for-loop accounts for the rows
	//internal/nested for-loop or the second for-loop accounts for the columns 
	
	//using one for-loop
	for(int i = 0, j = 0; i <= 12; ++i){
		
		cout.width(4);
		cout << i * j << " ";
		
		if(i == 12)
		{
			 
			i = 0; //it loops the values of the row only to be multiplied by the incremented value of j
			cout << endl;
			++j; // (increments amount of rows and multiplies) the values of each row with numbers 1-12
			
		}
		 
		if(j == 12 + 1) { //breaks and gets out of loop after 12th row
		break ;}
		
	}
	cout << multi( j, h);
}
	
	
	int multi(int j, int h){
	
		//using two-for-loops
		for(int j = 1; j <= 12; ++j){
			for(int h = 1; h <= 12; ++h)
			{	
				cout.width(4);
				cout <<  j * h << " " ;
			}
			cout << endl;
		
	return multi;
}

}
	
	
	
	
	

