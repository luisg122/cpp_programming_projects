#include<iostream>
using namespace std;

int func(){
	
	int x = 0;
	x++;
	return x;
}

int func1(){
	
	static int x = 0;
	x++;
	return x;
	
}

int main(){
	
	for(int i = 0; i < 4; i++){
		
		cout << func() << " ";
	}
	
	cout << endl << endl;
	
	for(int i = 0; i < 4; i++){
		cout << func1() << " ";
	}
	
	
	return 0;
}
/*These variables are created on stack frame, 
and a new stack frame is created with each
 new function call. And once a function has 
 finished it’s execution, it’s corresponding 
 stack frame is removed, along with the variables 
 created with it (including int variables). 
 x is initialized to 0 each time func is called in the above example*/
 
 
 
/*These variables are not allocated on the stack.
 It is allocated in a different area, which is 
 destroyed only when the program itself has finished 
 execution and getting terminated. Hence static int 
 variables’s lifetime is much longer than a variable declared int.

Static variables are initialized only once i.e the first time 
the function containing static is called. In the above example, 
line 3 is executed only when func is called for the first time. 
In the following calls to func, line 3 is not executed. After the
 fourth call to func x value becomes equal to 4. */
