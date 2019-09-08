//create a factoring program and a derivative program in .cc
#include<iostream>
#include<cstdlib>
#include<cstdio>
#include<string>
#include<cmath>
using namespace std;
class Factor{
	private:
		int a, b;
	public:
		
		Factor(int nx,int ny):a(nx), b(ny){}
		Factor():Factor(0,0){}
		
		int gcf(int a, int b);
		
		int get_a(){return a;}
		int get_b(){return b;}
		
		
		friend ostream &operator<<(ostream &os,  Factor &x){	//how come I cannot use const?
			//overloading the insertion operator 
			if(x.gcf(x.a,x.b) == 1) os << "GCF(" << x.a << ", " << x.b << ") = " << true;
			if(x.gcf(x.a,x.b) >  1) os << "GCF(" << x.a << ", " << x.b << ") = " << x.gcf(x.a,x.b);
		}
		
		void print(int n1, int n2, char n);
};

int Factor::gcf(int a, int b){			//applying Euclid's Algorithm
	
	if(b == 0) return abs(a);
	return gcf(b, a % b );
} 

void Factor::print(int n1, int n2, char n){
	
	cout << "Program for finding the Greatest Common Factor (GCF) between two numbers\n\n\n";
	while(true){
		cout << "Input First  Number: ";
		cin  >> n1;
		cout << "Input Second Number: ";
		cin  >> n2;
	
	
		Factor f1(n1,n2);
		cout   << f1;
		cout   << "\n\n===================================================";
		
	
		cout << "\n\nWould You Like You Like To Continue Program ? (Y/N): ";
		cin  >> n;
		system("cls");
		if(!(n == 'Y' || n == 'y'))			//if user no longer wishes to continue program, exit program
		break;
	}
}

int main(){			//f2 = f1 that is why YOU MUST USE COOPY CONSTRUCTORS,IN THIS CASE, THERE IS NO NEED
	
	int n1,n2;
	char n;
	Factor f1(n1,n2);
    f1.print(n1,n2,n);
	
	return 0;
}
