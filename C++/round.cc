//round to one decimal place
//<stdio used in language C
#include<iostream>
#include<cmath>
using namespace std;

int main(){
	
	cout << "Rouding project" << endl;
	
	double a = 10.9, b = 6.68;
	
	//cout << "\n";
	cout << endl;
	cout << "Compute the division of (a = 10.9) and (b = 6.68) = ";
	double c = double(a/b);
	//cout << c ; //computes actual and precise and answer
	cout << std::round(double(c*1000))/1000 << endl;
	
	return 0;
	
	
	
}
