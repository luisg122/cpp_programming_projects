//INSERT-SORTING method
#include <iostream>
#include <list>
#include <string>
//#include<utility>
using namespace std;

int main()
{
    string prompt = "Enter an integer value(ENTER to exit):";
    int s = 0;
    list<int> LS;
    cout << prompt;
    while (cin >> s) {
        cout << prompt;
        //getline(cin, s);
        //if (s.size() == 0) {
         //   break;
        auto  it  = LS.begin();
		while(it != LS.end()){
      		if(*it > s) break;
      		it++;
		}
    	LS.insert(it,s);
	}
    for(auto iter = LS.begin(); iter != LS.end(); iter++) {
       	cout << *iter << endl;
	}

	return 0;
}
/*#include <iostream>
#include <list>
#include <string>
using namespace std;

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
          auto it=LS.begin();
          while(it!=LS.end()){
            if(*it > s) break;
            ++it;
          }
          LS.insert(it,s);
    }
    for (auto iter = LS.begin(); iter != LS.end(); iter++) {
        cout << *iter << endl;

    }
    return 0;
}*/
