#include <iostream>
using namespace std;

class Fibonacci{
	
	private:
	int num;
	
	
	public:
	Fibonacci():num(0){}
	Fibonacci(int n):num(n){generate(n);}
	void  generate(int n);
	void  gen(void);	
};
void  Fibonacci::generate(int n){
	cout << "Fibonacci Series: ";
    int t1 = 0, t2 = 1, nextTerm = 0;
	for (int i = 1; i <= n; ++i)
    {
        // Prints the first two terms.
        if(i == 1)
        {
            cout << " " << t1;
            continue;
        }
        if(i == 2)
        {
            cout << " " << t2 << " ";
            continue;
        }
        else{
			nextTerm = t1 + t2;
        	t1 = t2;
        	t2 = nextTerm;
        
        	cout << nextTerm << " ";
    	}
    }
}

void Fibonacci::gen(void){generate(num);}

ostream &operator << (ostream &os, Fibonacci &term){
	
	term.gen();
	return os;	
}
int main()
{
    
	int n;
	cout << "Enter the number of terms: ";
    cin >> n;
    //cout << "Fibonacci Series: " << fib.generate(n);
	
	//-------------------------------------------------
	Fibonacci fib(n);		//matching initialing constructor 
	cout << endl; 
	
	cout << fib;			//overlaoding the insertion operator
	cout << endl;
	
	fib.generate(n);		//accessing a class method by reference 
	cout << endl;
	//-------------------------------------------------
	return 0;
}
