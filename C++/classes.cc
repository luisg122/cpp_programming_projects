

#include<iostream>
#include<string>
#include<cmath>
#include<conio.h>
using namespace std;
class Fraction {
private:
    int num, den;       // main program cannot access, only class member functions
    void normalize();       // Convert to standard form.
    int gcf(int a,int b);   // Greatest Common Factor.
    int lcm(int a,int b);
public:
    void set(int n,int d);
    int get_num();
    int get_den();
    Fraction add(Fraction other);
    Fraction multi(Fraction other);
//private:
   // Lowest Common Denominator.
};

void Fraction::set(int n, int d){
	
	num = n;
	den = d;
	normalize();
}

int Fraction::get_num(){
	return num;
}

int Fraction::get_den(){
	return den;
}


int Fraction::gcf(int a, int b){  //using euclidean algorithm 
	
	if(b == 0)	return  abs(a);
	return gcf (b, a % b);
	
}

int Fraction::lcm(int a, int b){
	int g = gcf(a, b);
	
	return (a/g)*b;
	return (b/g)*a;
	
}
void Fraction::normalize(){
	if(den == 0 || num == 0){
	
	num = 0;
    den = 1;	//denominator cannot be zero, it is therefore normalized
	}
    else{
    
	if(den < 0){
		
		num*= -1;
		den*= -1;
	}
}
	int g = gcf(num,den);		//simplifying fraction
	num = num/g;
	den = den/g;
	
	
}

/*Fraction Fraction::add(Fraction other){
	Fraction fract;
	int lcd = lcm(den, other.den);
	int quot1 = lcd/den;
	int quot2 = lcd/other.den;
	
	fract.set(((num*quot1) + (other.num*quot2)), lcd);
	return fract;
	
}*/


Fraction Fraction::add(Fraction other){
	
	Fraction fract;
	int n = num*other.den + other.num*den;
	int d = den*other.den;
	fract.set(n,d);
	return fract;
}

/*Fraction Fraction::multi(Fraction other){
	
	Fraction fract;
	fract.set(num * other.num, den * other.den);
	return fract;
	
}*/

Fraction Fraction::multi(Fraction other){
	
	Fraction fract;
	int n = num*other.num;
	int d = den*other.den;
	fract.set(n,d);
	return fract;
}



int main(){

	//Fraction fr;
	//fr.set(-4,-6);
	//cout << fr.get_num() << "/" << fr.get_den();
	
	
	int a, b, c, d;
	//string str;
	char response;
	
	Fraction fract1, fract2, fract3;
	
	while (true){
	
	cout << "Enter a numerator: ";
	cin  >> a;
	cout << "Enter a denominator: ";
	cin  >>	b;
	
	fract1.set(a,b);
	
	cout << "Enter a numerator: ";
	cin  >> c;
	cout << "Enter a denominator: ";
	cin  >>	d;
	
	fract2.set(c,d);
	
	fract3 = fract1.add(fract2);	
	cout << a << "/" << b << " + " << c << "/" << d << " = ";
	cout << fract3.get_num() << "/" << fract3.get_den() << "\n";
	
	fract3 = fract1.multi(fract2);
	cout << a << "/" << b << " * " << c << "/" << d << " = ";
	cout << fract3.get_num() << "/" << fract3.get_den() << "\n";
	
	cout << "Would you like to run program again? (Y or N) ";
	cin >> response;
	/*if(!(str[0] == 'Y' || str[0] == 'y'))		//string is an array, therefore the first letter is in cell 0 of the array
		break;	
	}
	*/
	
		if(!(response == 'Y' || response == 'y')){
			break;
		}
	}
	
	
	return 0;
}

