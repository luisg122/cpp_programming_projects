#include<iostream>
using namespace std;
int main(){
	//lambda function == anonymous function
	//typical boiler-plate syntax of a lambda function
	[](int value){
		cout << "I'm inside a lambda function with value "
		<< value << endl;
	}(100);

	return 0;
}
