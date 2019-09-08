#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

int main()
{
    srand(time(NULL));        // replace randomize();
    						  // setting the seed
    int num = 0;
    
    num = rand() % 3 + 2;    //  replace random()
    
    char text[] = "ABCDEFGHIJK";
 
    for(int i = 1; i <= num; i++){
    	
        for(int j = num; j >= 0 ; j--)	cout << text[j];
        
		cout << endl;        
    }

	return 0;
}
