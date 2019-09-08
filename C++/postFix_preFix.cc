#include <iostream>

int main() {
  int i = 4;
  int j = i++;
  int k = ++j;
  std::cout << i;
  std::cout << j;
  std::cout << k;
  //std::cout << i << j << k << std::endl;
  
  /*  postfix == i++ value is incremented, but the value is the original i, unless a cout object is applied after post-fix incrementation
  //  prefix  == ++i value is incremented, and value is the new value i
  //  however,   for various loops,both notations  are interchangeable
  
  int j = 0;
  std::cout << ++j;    //prefix increment operator
  int i = 1;
  std::cout << i++ << std::endl;     //postfix increment operator
  std::cout << j << i;*/
}
