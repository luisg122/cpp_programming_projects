//data engineer, data scientist, financial engineer, software engineer, machine learning engineer
#include<iostream>
using namespace std;
struct box{
	int x = 4;
	int y = 3;
};
int main(){
	box *p = new box;
	cout << p -> x << endl;	//dereferences the pointer to get an object and access a specifed memeber of object
	cout << p -> y;
	
	delete p;               //de-allocate memory after dynamic memory allocation
	
	return 0;
}
