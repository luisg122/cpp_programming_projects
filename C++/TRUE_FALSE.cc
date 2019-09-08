//(100+1.0/3) - 100 == 1.0/3

#include<iostream>
using namespace std;

bool statement(void){
	bool value;
	
	double a = double((100 + 1.0/3) - 100);
	double b = double(1.0)/3;
	cout << double(a) << " == " << double(b) << " Therefore  ";
	if(a == b){
		value = true;
		return value;
	}	
	//if(a != b) value = false;
	else return false;
	
}
int main(void){
		
	cout << statement() << endl;
	cout << 1.0/3;
	cout << endl << ((100 + 1.0/3) - 100);
	//getchar();
	return 0;
	
}
