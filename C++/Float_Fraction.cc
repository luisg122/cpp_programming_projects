#include<iostream>
#include<cmath>
using namespace std;
class Fraction{
	protected:
		int x, y;
	public:
		Fraction(int nx, int ny):x(nx), y(ny){} //inherit constructor to obtain access initialized data members of superclass

};
class FloatFraction: public Fraction{


	public:
	using Fraction::Fraction;
		  //FloatFraction(x,y);  //inheriting the initializer constructor

	double get_float(){
		double  z = 1.0*(x)/y;
		return  z;

	}
};

int main(){

	cout << "Luis Gualpa Project - 4\n";
	FloatFraction f(1,4);
	cout<< f.get_float();	//0.25

	return 0;
}
