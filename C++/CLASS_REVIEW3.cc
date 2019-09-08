//creating a Fraction Class
#include<iostream>
#include<cmath>
using namespace std;

class Fraction{
	private:			//it becomes important to restrict access to certain members
						//for one thing, you should NEVER allow a zero to be the denominator
		int num, den;
		void normalize();
		int gcf(int a, int b);
		int lcm(int a, int b);
	public:
		void set(int n, int d);
		int get_num();
		int get_den();
};
//Public  function members provide access to class data
//Private function members CANNOT be access outside of class
//Private function members can provide support fo public function members 
//Member  functions need to be defined somewhere. These definition can 
//be placed anywhere after the class declaration 
//Simple functions may be defined inside of class, "inline functions"
//inline function CANNOT make recursive calls
//comiler replaces the function call with the body of the function
//functions defined using scope :: is more optimal, NO RESTRICTIONS

void Fraction::set(int n, int d){

	num = n;
	den = d;
	normalize();
}
int  Fraction::get_num(){
	return num;
}
int  Fraction::get_den(){
	return den;
}
void Fraction::normalize(){
	//Handle cases with den == 0, is that a form of exception-handling?
	if(den == 0 || num == 0){
		num = 0;
		den = 1;
	}
	if(den < 0){
		num *= -1;
		den *= -1;
	}
	
	//Factor/divide out the GCF from both the numerator and denominator
	//simplifying fractions, 2/4 == 1/2
	int g = gcf(num, den);
	//num  = num / g;
	//den  = den / g;
	num /= g;
	den /= g;
}
int Fraction::gcf(int a, int b){		//applying Euclid's Algorithm to find the gcf
	if(b == 0) return abs(a);
	return gcf(b, a % b);
	
}
int  Fraction::lcm(int a, int b){
	int g = gcf(a,b);
	return (a/g)*b;
}

int main(){
	int n,d;
	cout << "Input Integer numerator:   ";
	cin  >> n;
	cout << "Input integer denominator: ";
	cin  >> d;
	Fraction  fr1;
	fr1.set(n,d);
	
	if(fr1.get_den() == 1){
		cout << "\nYour Rational Fraction is: " << 
		fr1.get_num();		
	}
	else { 
		cout << "\nYour Rational Fraction is: " << 
		fr1.get_num() << "/" << fr1.get_den();
	}
	
	cout << endl << endl;
	system("PAUSE");
	return 0;
}

