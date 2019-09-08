#include <iostream>
#include<cmath>
using namespace std;

int FirstFactorial(int num) { 
    int s = 1;
    for(int i = 1; i <= num; i++){
        
        s *= i;
    }
   
  return s; 
            
}

int main() { 
  
  int num;
  cin >> num;
  cout << FirstFactorial(num);
  
  
  return 0;
} 
