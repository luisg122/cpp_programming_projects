// vector::reserve
#include <iostream>
#include <vector>
using namespace std;

int main ()
{
  vector<int> ::size_type sz;
  vector<int> foo;
  sz = foo.capacity();
  cout << "making foo grow:\n";
  for (int i=0; i<100; i++) {
    foo.push_back(i);
    if (sz != foo.capacity()) {
      sz = foo.capacity();
	  cout << "capacity changed: " << sz << '\n';
    }
  }

  vector<int> bar;
  sz = bar.capacity();
  bar.reserve(100);   // this is the only difference with foo above
  cout << "making bar grow:\n";
  for (int i=0; i<100; ++i) {
    bar.push_back(i);
    if (sz != bar.capacity()) {
      sz = bar.capacity();
      cout << "capacity changed: " << sz << '\n';
    }
  }
  return 0;
}
