#include <iostream>
#include <string>
#include <sstream>
using namespace std;
class Wine{
    private:
        string name = "";
        int year = 1900;
        double price=0;
    public:
        Wine(string na,int ye, double pr):name{na},year{ye},price{pr}{}
        string get_name(){return name;}
        int get_year(){return year;}
        double get_price(){return price;}
};

istream& operator>>(istream &is, Wine &x){
  string s = "";
  getline(is,s);          //getline(cin, s);  cin == is
  
  size_t d1 = s.find_first_of(",", 0);
  string name = s.substr(0, d1);
  cout << name;
  
  return is;
}
ostream& operator<<(ostream &os, Wine &x){
    os << "(" << x.get_name() << ", Vintage " <<  x.get_year() << ", $" << x.get_price() << ")";
    return os;            //cout == os
}
int main(){
  Wine w("apple", 1996, 1000.1);
  cout << w << endl;
  cin >> w;
  
  return 0;
}

