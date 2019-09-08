// s Complex Numbers.cpp : This program should allow the user to add, subtract, and multiply complex numbers.
//


#include <iostream>
using namespace std;
class Complex
{
public:
	void output()
	{	
		cout << "Your complex number is: " << r << "+" << i << "i" << endl;
	}
	void input()
	{
		cout << "Enter the real part of the complex number: ";
		cin >> r;
		cout << "Enter the imaginary part of the complex number: ";
		cin >> i;
	}
	void add (Complex n1, Complex n2)
	{
		r = n1.r + n2.r;
		i = n1.i + n2.i;
	}
	
	void subtract( Complex n1, Complex n2)
	{
		r= n1.r- n2.r;
		i = n1.i - n2.i;
	}
	void multiply (Complex n1, Complex n2)
	{
		int a,b;
		a = ((n1.r) * (n2.r)) - ((n1.i) * (n2.i));
		b = ((n1.r) * (n2.i)) + ((n2.r) * (n1.i));
	}
private:
	int r;
	int i;

};

int main()
{
	Complex number1, number2, sum, differnce, product;
	number1.input();
	number2.input();
	sum.add(number1, number2);
	differnce.subtract(number1, number2);
	product.multiply(number1, number2);
	sum.output();
	differnce.output();
	product.output();
	return 0;
}
