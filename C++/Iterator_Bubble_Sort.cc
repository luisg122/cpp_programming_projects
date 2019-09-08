#include <algorithm>
#include <cmath>
#include <iostream>
#include <chrono>
#include <functional>
#include <vector>
#include <iterator>
using namespace std;
//using iterators
template<class Iter>        	//how do templates relate to classes?
void bubblesort(Iter first, Iter last){
    //cout << *first << endl;
    //cout << *last  << endl;		//the end iterator of a container is an address

	//++first;
	//cout << *first << endl;
	
	/*while(first != last){ 
        Iter jump  = first;
        for(Iter i = first, j = i++; i != last; i++,j++){ // (previous, next)
            if(*i < *j) { 		// Basically if (previous > next) SWAP Increasing Order
                jump = i;
                std::swap(*i,*j);
            }
        }
        last = jump;        	//last or end iterator goes out of range from structured containers, we have to reassign it a values
    }*/
     
    
    for (Iter i = first; i != last; i++){
	    for (Iter j = first; j < i; j++){
            if (*i < *j)	std::swap(*i, *j);  // or std::swap(*i, *j);
             									//there is such a thing as std::iter_swap(i,j);
		}
    }
	
}

int random(int a, int  b){

    return rand() % b + a;      //notation for generating random numbers in c++
                                // b == MAX, a == MIN, therefore generate random numbers ranging from a - b
}

void print(vector<int> a){

    for(int i = 0; i < a.size(); i++) cout << (i + 1) << ")" << a[i] << endl;

}

int main(){

    srand( time(NULL) );
    int n = 10;
    vector<int> t(n);
    for(int i = 0; i < n; ++i) t[i] = random(1,n);
    vector<int> v1(t);
    
    print(v1);
    cout << endl << endl;

    bubblesort(v1.begin(), v1.end());

    print(v1);

    return 0;
}
