#include<iostream>
using namespace std;

int main(){

	int i = 0;
    /*while ( i < 10)
    {
        cout << "lalala";
		++ i; //must add an increment, otherwise it would be an infinte loop, as i=0: i<10: ALWAYS TRUE THEREFORE PRINT "lala
    }
    */
    /*while ( i < 10){
		cout << i << endl;
		++i;
    }
		*/
	while (i++ < 10) // post-fix prints first and then adds by 1: checks first then adds
	//prefix increment: add first, then print: adds first then checks
	{
		 cout << i << endl; //increment adds 1 to the original elements on set, it does go in sequential like the last while loop
	}


return 0;
}
