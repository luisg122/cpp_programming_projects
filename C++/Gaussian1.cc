#include<iostream>
#include<cmath>
#include<cstdlib>


using namespace std;

class Gaussian{
	
	private:
		int a,b;
	
	public :
		
		Gaussian(int nx,int ny):a(nx),b(ny){}		//in-class initializer constructor
    	Gaussian():Gaussian(0,0){}
													//default consturctor with delegating constructor
		Gaussian(const Gaussian &other);			//copy constructor

		/*Gaussian(int n){							//convert int to Gaussian int constuctor 
			a = n;
			b = 0;
		}*/
		Gaussian(int n):a(n){}		//using a delegating constructor 
									//to convert int -> Gaussian int
		
		int norm(){					//norm function (a^2 + b^2)
			a *= a;
			b *= b;
			return a + b;
		}
		//int get_a(){return a;}
		//int get_b(){return b;}
		
		//-----------------------------------------------------------------------------------
		
		Gaussian   add(const Gaussian &other)   const;
		Gaussian   operator+(const Gaussian &other);
		Gaussian   sub(const Gaussian &other)   const;
		Gaussian   operator-(const Gaussian &other);
		Gaussian   multi(const Gaussian &other) const;
		Gaussian   operator*(const Gaussian &other);
		bool       div(const Gaussian &other);
		bool       operator|(const Gaussian &other);		
		//------------------------------------------------------------------------------------
		
		bool operator==(const Gaussian &other){
    	if (a == other.a && b == other.b) return true;
		else return false;
	    }
		//WHY do you have to 'friend keyword' for ostream
		friend ostream &operator<<(ostream &os, const Gaussian &x){			//notation is really important
		//OVERLOADING THE INSERTION OPERATOR																		//this function does away with x.get_a(), and x.get_b(), it looks ugly
																				//insertion operator == overflow operator? 
	
			if(x.a != 0 && x.b    == -1)  os << x.a   << " - i";
    		if(x.a != 0 && x.b     < -1)  os << x.a   << " - " << x.b*(-1) << "i";
    		if(x.a != 0 && x.b    ==  1)  os << x.a   << " + i";
    		if(x.a != 0 && x.b    ==  0)  os << x.a;
    		if(x.a == 0 && x.b    ==  0)  os << false;
    		if(x.a == 0 && x.b    == -1)  os << "-i";
    		if(x.a == 0 && x.b    ==  1)  os << "i" ;
			if(x.a == 0 && x.b    <  -1)  os << "-" << x.b*(-1) << "i";
		    if(x.a == 0 && x.b    >   1)  os << x.b << "i";
			else if(x.a != 0 && x.b > 1)  os << x.a   << " + " << x.b << "i";
		    
			
			return os;
		}	

		Gaussian &operator=(const Gaussian &other){
			a = other.a;
			b = other.b;
			return *this;
		}


};
//------------------------------------------------------------------------------------------------

Gaussian::Gaussian(const Gaussian &other){

	a = other.a;
	b = other.b;
}

Gaussian Gaussian::add(const Gaussian &other)const{
	
	return Gaussian(a + other.a, b + other.b);			//this is why you need a delegating constructor!!!
}
Gaussian Gaussian::operator+(const Gaussian &other){
	
	return add(other);
	
}
Gaussian Gaussian::sub(const Gaussian &other)const{

	return Gaussian(a - other.a, b - other.b);			// this is why you need a delegating constructor!!!
	}
Gaussian Gaussian::operator-(const Gaussian &other){

	return sub(other);
	
}
Gaussian Gaussian::multi(const Gaussian &other)const{
	
	Gaussian n1;
	
	n1.a = ((a) * (other.a)) - ((b) * (other.b));		//i^2 == -1, therefore -(b*other.b) takes care of that  
	n1.b = ((a) * (other.b)) + ((b) * (other.a));
	
	
	return Gaussian(n1.a, n1.b);						// this is why you need a delegating constructor!!!
	
}
Gaussian Gaussian::operator*(const Gaussian &other){
	return multi(other);
	
}
bool Gaussian::div(const Gaussian &other){				 
	int x,y;
	bool isPrime = true;
    Gaussian n1(a,b),n2(other.a,other.b), conj_n1(a, (-1)*b);
  
    Gaussian n3 = n2*conj_n1;
    Gaussian n4 = n1*conj_n1;
    int den =  n4.a + n4.b;
    int c = double(n3.a)/den;
    int d = double(n3.b)/den;								
	
	int z = pow(c,2) + pow(d,2);		//implicit normalization
	x = n1.norm();				
	y = n2.norm();					
    
	if(x != 0){
			if((y % x) == 0){
				if(y == x*z)return true;
				else return false;
			}
	}
	else return false;
} 
bool Gaussian::operator|(const Gaussian &other){
	return div(other);
}

//-------------------------------------------------------------------------------------------------

int main(){
	cout << "Luis Gualpa - Project 1" << endl;
	cout << "===================================================\n";
	
    
	cout << "CHECK Expected OUTPUT\n";
	const Gaussian  x1, x2(3), x3(0,1), x4(0,-1), x5(1,2), x6(3,-2), x7(-3,1), x8(2,-1), x9(0,-2), x10(0,3);
	cout<<x1<<", "<<x2<<", "<<x3<<", "<<x4<<", "<<x5<<", "<<x6<<", "<<x7<<", "<<x8<<", "
	<<x9<<", " << x10<<endl << endl;
	
	
	
	
	
//---------------------------------------------------------------------	
	cout << "===================================================\n\n";
	cout << "Program for Computing Complex Numbers\n" ;
	
	
	int a,b,c,d;
	
	cout << "Enter Real  integer: ";
	cin  >> a;
	cout << "Enter Imag. integer: ";
	cin  >> b;
	Gaussian X1(a,b);
	
	cout << "Enter Real  integer: ";
	cin  >> c;
	cout << "Enter Imag. integer: ";
	cin  >> d;
    Gaussian X2(c,d);
    cout << endl;   
    
    //X2 = X1;
    
    cout << "Your First  Complex Number Is: " << "(" << X1 << ")\n";
    cout << "Your Second Complex Number Is: " << "(" << X2 << ")\n";
	
//--------------------------------------------------------------------------------------------------------	
	Gaussian X3 = X1 * X2;
	cout << "\nMultiplication of complex numbers: " << "(" << X1 << ") * (" << X2 << ") = " << X3 << endl;
	
	X3 = X1 + X2;
	cout << "\nAddition of complex numbers:       " << "(" << X1 << ") + (" << X2 << ") = " << X3 << endl;
	
	X3 = X1 - X2;   
	cout << "\nSubtraction of complex numbers:    " << "(" << X1 << ") - (" << X2 << ") = " << X3 << endl;
	
	Gaussian x(1,2);
	
	
	cout << "\n\nThe norm for ((1)^2 + (2)^2) = " << x.norm() << endl;	
	
	
	Gaussian m(2,4),n(4,8);		//false
	
	bool bb = (m|n);		
    cout << bb;	   				//0, therefore False
	
	return 0;
}
