#include<iostream>
using namespace std;

template < class AV >
AV aValue(AV a)
{
	return (a > 0 ? a : a * -1);		//conditional operator 
}

int main()
{
	int x,y;
	cout << "this program returns the absolute value.\n"
	<< "****************************************************\n\n";
	cout << "enter a positive number : ";
	cin >> x;
	cout << "enter a negative number : ";
	cin >> y;
	cout << "absolute value of " << x << " is : ";
	cout << aValue(x) << endl;
	cout << "absolute value of " << y << " is : ";
	cout << aValue(y) << endl;
	

	cin.get();
	cin.get();
	return 0;
}
