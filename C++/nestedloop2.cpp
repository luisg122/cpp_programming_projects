#include<iostream>
using namespace std;

int main(){
	//nested loop means a loop inside another loop
	//a LOOP INSIDE ANOTHER LOOP
	for(int i = 1; i <=10; i++) //this loop is processed first
	{
		for(int j= 1; j <=10;j++ ){// this loop is processed second
	 		cout.width(4); //creates neat spaces between output elements
			cout << i*j << " ";
		}
	cout << endl;
	
	}
	
	
	
	
	
	
	
}
