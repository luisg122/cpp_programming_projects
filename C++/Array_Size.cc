#include <iostream>
#include <array>
using namespace std;
int main ()
{
  array<int,5> myints;
  cout << "size of myints: " << myints.size()  << endl;
  cout << "sizeof(myints): " << sizeof(myints) << endl;

  return 0;
}
