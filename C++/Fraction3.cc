#include <iostream>
#include <string>
#include <cstring>
#include <cmath>
using namespace std;
class Fraction{
  private:
    int num, den;      			  // Numerator and denominator.
    void normalize();   		  // Convert to standard form.
    int gcf(int a, int b) const;  // Greatest Common Factor.
    int lcm(int a, int b) const;  // Lowest Common Denom.
    void set(int n, int d)
        {num = n; den = d; normalize();}
  public:
    //int get_num()  {return num;}
    //int get_den()  {return den;}
    Fraction(int n,int d){
      set(n,d);
    }
    Fraction(int n){
      set(n,1);
    }
    Fraction(){
      set(0,1);
    }
    Fraction(const Fraction & src){
      num=src.num;
      den=src.den;
    }
    
	
	Fraction add(const Fraction & other) const;
	Fraction operator+(const Fraction &other);
    Fraction mult(const Fraction &other) const;
    Fraction operator*(const Fraction &other);
    
	bool operator==(const Fraction &other) {
    if (num == other.num && den == other.den) {
        return true;
    } else {
        return false;
    }
}
   
    /*friend Fraction operator+(const Fraction & f1, const Fraction & f2){
      return f1.add(f2);
    }*/
/*    
    friend Fraction operator+(int n, const Fraction & other){
      return Fraction(n,1)+other;
    }
    friend Fraction operator+(const Fraction & other, int n){
      return other.add(Fraction(n,1));
    }
*/
    Fraction &operator=(const Fraction &src){
      set(src.num, src.den);
      return *this;
    }
    friend ostream& operator<<(ostream & os,const Fraction & fr){
      os<<fr.num<<"/"<<fr.den;
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
    num /= n;
    den /= n;
}
// Greatest Common Factor using Euclid's Algorithm
//--------------------------------------------------------------------
int Fraction::gcf(int a, int b) const{	//variables keep updating 
    //if (b == 0) return abs(a);
    //else return gcf(b, a % b);
    return (b == 0) ? abs(a): gcf(b, a % b);   //conditional operator ((condition) ? (if = true):(else = false))    
}
int Fraction::lcm(int a, int b) const{
    int n = gcf(a, b);
    return (a / n )* b;
    return (b / n )* a;
}
//--------------------------------------------------------------------
Fraction Fraction::add(const Fraction &other) const{
    int lcd = lcm(den, other.den);
    int quot1 = lcd/den;
    int quot2 = lcd/other.den;
    return Fraction(num * quot1 + other.num * quot2, lcd);
}		
Fraction Fraction::operator+(const Fraction &other){
	return add(other);
}
Fraction Fraction::mult(const Fraction &other) const{
    return Fraction(num * other.num, den * other.den);
}
Fraction Fraction::operator*(const Fraction &other){
	return mult(other);
}
int main()
{
  Fraction f1(2, 3),f2(9,6), f(12);
  Fraction f3 = f1 + f2;
  cout << f3 << endl;
  
  f3  = f1 * f2;
  cout <<  f3 	   << "\n";	//this is normalized(exception-handling) with set function
  cout <<  f1 + f2 << "\n";
  cout <<  f1 * f2 << "\n";
  cout <<  f3 * f2 << "\n";  
  
  cout << f;
  return 0;
}
