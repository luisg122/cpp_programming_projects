 #include <iostream>
#include <string>
#include <cstring>
#include <cmath>
using namespace std;
class Fraction{
  private:
    int num, den;      // Numerator and denominator.
    void normalize();   // Convert to standard form.
    int gcf(int a, int b) const;  // Greatest Common Factor.
    int lcm(int a, int b) const;  // Lowest Common Denom.
    void set(int n, int d)
        {num = n; den = d; normalize();}
  public:
    //int get_num()  {return num;}
    //int get_den()  {return den;}
    Fraction(int nx, int ny): num(nx),den(ny){set(num,den);} //acheives the same function as the following constructor
    Fraction():Fraction(0,0){}

	/*Fraction(int n,int d){			            //overloading Fraction constructor
      set(n,d);
    }
    Fraction(int n){
    	set(n,1);
    }
    Fraction(){
        set(0,1);
    }*/
    Fraction(const Fraction & src){
      num = src.num;
      den = src.den;
    }

    Fraction add (const Fraction & other)    const;
    Fraction operator+(const Fraction &other)const;
    Fraction mult(const Fraction & other)    const;
    Fraction operator*(const Fraction &other)const;

	bool operator==(const Fraction &other) {
    	if (num == other.num && den == other.den) return true;
    	else return false;
	}

    Fraction& operator=(const Fraction &src){
      set(src.num, src.den);
      return *this;
    }
    friend ostream& operator<<(ostream & os,const Fraction & fr){
      os << fr.num << "/" << fr.den;
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

    int n = gcf(num, den);
    num = num / n;
    den = den / n;
}
// Greatest Common Factor
//
int Fraction::gcf(int a, int b) const{
    if (b == 0) {
        return abs(a);
    } else {
        return gcf(b, a%b);
    }
}
int Fraction::lcm(int a, int b) const{
    int n = gcf(a, b);
    return a / n * b;
}
Fraction Fraction::add(const Fraction & other) const{
    int lcd = lcm(den, other.den);

	int quot1 = lcd/den;		//finding the common denominator
    int quot2 = lcd/other.den;

	return Fraction(num * quot1 + other.num * quot2, lcd);
}
Fraction Fraction::operator+(const Fraction & other) const{
      return add(other);
}
Fraction Fraction::mult(const Fraction & other) const{
    return Fraction(num * other.num, den * other.den);
}
Fraction Fraction::operator*(const Fraction & other) const{
    return mult(other);
}
int main()
{
  Fraction f1(1, 10), f2(1,15);
  Fraction f3 = f1 + f2;
  cout << f1 << " + " << f2 << " = ";
  cout << f3;
  return 0;
}
