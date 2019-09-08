#include <iostream>
#include<cmath>
using namespace std;

int FirstFactorial(int num) { 
    if(num == 0) return 1;
    else{ return FirstFactorial(num -1)*num;}
}    
int main() { 
  
  int num;
  cin >> num;
  cout << FirstFactorial(num);
  
  
  return 0;
} 
