#include <iostream>
#include <list>
#include <string>
using namespace std;
void print(list<string> LS){
  for (auto iter = LS.begin(); iter != LS.end(); iter++) {
      cout << *iter << endl;
  }  
}

int main()
{
    string s;
    list<string> LS;
    while (true) {
          cout << "Enter string (ENTER to exit): ";
          getline(cin, s);
          if (s.size() == 0) {
               break;
          }
          auto it = LS.begin();
          while (it != LS.end() && *it < s) ++it;
          LS.insert(it, s);
          print(LS);
          //LS.push_back(s);
    }
    //LS.sort();      // Sort, and then print elements.

    return 0;
}
