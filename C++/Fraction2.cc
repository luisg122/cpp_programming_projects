#include <iostream>
#include <cmath>
using namespace std;
class Fraction {
private:
    int num, den;      		// Numerator and denominator.
    void normalize();   	// Convert to standard form.
    int gcf(int a, int b);  // Greatest Common Factor.
    int lcm(int a, int b);  // Lowest Common Denom.
public:
    void set(int n, int d)
    {num = n; den = d; normalize();}
    //int get_num()  {return num;}
    //int get_den()  {return den;}
    
    Fraction(int nx, int ny): num(nx), den(ny){set(num,den);}	//delegating constructor with implicit exception handling
    Fraction():Fraction(0,1){}
	Fraction(int nx):num(nx), den(1){set(num,den);}
    //Fraction(int n,int d){									//implicit excecption-handling using set member-function
																//inside constructor
    //	set(n,d);
	//}
	/*Fraction(int n){
		set(n,1);
	}
	Fraction(){
		set(0,1);
	}*/
	
	
	Fraction(const Fraction &other){				//in-line copy constructor
		num = other.num;
		den = other.den;
	} 
    
	
	Fraction add(const Fraction &other);
    Fraction operator+(const Fraction &other);
	Fraction mult(const Fraction &other);
	Fraction operator*(const Fraction &other);
	
	
	bool operator==(const Fraction &other){
		if(num == other.num && den == other.den) return true;
		else return false;
	}
	
	Fraction &operator=(const Fraction &other){
		set(other.num, other.den);
		return *this;
	}
	
	friend ostream &operator<<(ostream &os, const Fraction &x){
		if(x.num == x.den)                  os << 1;
		if(x.den == 1 && (x.num != x.den))  os << x.num;
		else if(x.num != x.den)             os << x.num << "/" << x.den;
		
		return os;
	}
};

void Fraction::normalize(){

    // Handle cases involving 0

    if (den == 0 || num == 0) {
        num = 0;
        den = 1;
    }

    // Put neg. sign in numerator only.

    if (den < 0) {
        num *= -1;
        den *= -1;
    }
    // Factor out GCF from numerator and denominator.

	if(num != den){
		int n = gcf(num, den);
    	num = num / n;
    	den = den / n;
	}
    
}
// Greatest Common Factor
//
int Fraction::gcf(int a, int b) {
    if (b == 0) {
        return abs(a);
    } else {
        return gcf(b, a%b);
    }
}
// Lowest Common Denominator
//
int Fraction::lcm(int a, int b){
    int n = gcf(a, b);
    return (a / n) * b;
}
Fraction Fraction::add(const Fraction &other) {
	
	int lcd = lcm(den, other.den);
    int quot1 = lcd/den;
    int quot2 = lcd/other.den;
    return Fraction(num * quot1 + other.num * quot2, lcd);
	
}
Fraction Fraction::operator+(const Fraction &other){
	return add(other);
}
Fraction Fraction::mult(const Fraction &other) {
	
	int n=num*other.num;
	int d=den*other.den;
	return Fraction(n,d);
}
Fraction Fraction::operator*(const Fraction &other){
	return mult(other);
}

int main()
{
    Fraction fract1(1,10), fract2(1,15),fract4(12);
    cout << fract4 << endl;

    Fraction fract3 = fract1 + fract2;
    cout << fract1 << " + " << fract2 << " = " << fract3;

    return 0;
}
