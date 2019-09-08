#include<iostream>
using namespace std;
int main(){
	
	/*loops - break and continue*/
	
	for(int i = 1; i<=10; ++i){
		if(i== 3) break;
		for(int j = 1; j <= 5; ++j){
		
		cout.width(4);
		cout << i*j;
	}
		
	cout << endl;	
	}
	return 0;
	
	
	
	
	
	
	
	
}
