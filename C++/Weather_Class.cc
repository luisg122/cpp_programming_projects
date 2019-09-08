#include<iostream>
#include<fstream>

using namespace std;
struct Weather{
	int hour;
	double temp;
	Weather(int nh, double nt):hour(nh), temp(nt){}

};
ostream &operator<< (ostream &os, const Weather &w){
	os << "(" << w.hour << "," << w.temp  << ")";
	return (os);
}

istream& operator>>(istream & is, Weather & w){
    int h;
    double t;
    char c1,c2,c3;
    is>>c1>>h>>c2>>t>>c3;
    if(c1!='('|| c2!=','|| c3!=')'){
     is.clear(ios_base::failbit);
     return is;
    }
    w.hour=h;
    w.temp=t;
    return is;
}

int main(){	//constructors are initializing structures
	Weather w(2,3);
	cout << w << endl;
	ofstream file{"t1.txt"};
	cin >> w;
	cout << w;
	file << w;
	return 0;
}
/*
	#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <cctype>
#include<limits>
using namespace std;
/*void skip_to_int(){
    if(cin.fail()){
        cin.clear();
    

    }
    else throw runtime_error("nothing");
}
int get_int(){
  int n = 0;
  while(!(cin >> n)){
    cout << "Not an integer" << endl;
    skip_to_int();
  }
  return n;
}
int main(){
  int n=get_int();
}*/
//clean up your buffer
/*
int main(){
  int n = 1;
  while(true){
    cin >> n;
    cout << "n = " << n;
    cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
  }
  return 0;
}
*/
