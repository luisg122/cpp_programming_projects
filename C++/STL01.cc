#include <iostream>
#include <list>
using namespace std;
int main() {
  list<int> li;
  li.push_back(1);
  li.push_back(2);
  li.push_back(3);
  li.push_back(4 /*+ 4*/);
  li.push_front(0);
  for(auto x:li){ //For each in c++11,c++14
      cout<<x<<endl;
  }
}
