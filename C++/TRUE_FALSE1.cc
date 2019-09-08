#include<iostream>
using namespace std;

int main(){
	
	bool value;
	
	double a = double((100 + 1.0/3) - 100);
	double b = double(1.0)/3;
	cout << double(a) << " == " << double(b) << " Therefore  ";
	
	if(a == b){
		value = true;
		cout << value;
	}	
	
	if(a != b){
		value = false;
		cout << value;
	}
	
	
	
	return 0;
}
