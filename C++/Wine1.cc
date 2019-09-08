#include <iostream>
#include <cmath>
#include <vector>
#include <fstream>
#include <string>
#include <sstream>
using namespace std;
class Wine{
    private:
        string name="";
        int year=1900;
        double price=0;
    public:
        Wine():name{"None"},year{0},price{0}{}
        Wine(string na,int ye, double pr):name{na},year{ye},price{pr}{}
        string get_name()    const{return name;}
        int    get_year()  	 const{return year;}
        double get_price() 	 const{return price;}
        double get_avg(vector<Wine> cellar)     const;
};
double Wine::get_avg(vector<Wine> cellar) const{
	
	int s = 0;
	for(const Wine w: cellar) {
		if(w.get_year() >= 1999 && w.get_year() <= 2003) s += w.get_price();
	}
	return s;
}
//For name="DOM PERIGNON",year=1996, price=150, return 
//DOM PERIGNON, vintage 1996 ($150)
ostream & operator<<(ostream & os,const Wine & w){
  os<<w.get_name()<<", Vintage "<<w.get_year()<<", ($"<<w.get_price()<<")"; 
  
   
  return os;
}
//For input DOM PERIGNON,1996,150
//make a Wine object with name="DOM PERIGNON",year=1996, price=150
//is there a size limit in how much information can be read using ifstream?
istream & operator>>(istream & is, Wine & w){
  string name="",syear="",sprice="";
  getline(is,name, ',');
  getline(is,syear,',');
  getline(is,sprice);
  int year=0;
  double price=0;
  stringstream(syear) >> year;
  stringstream(sprice)>> price;
  w=Wine(name,year,price);
  return is;
}
// wine.txt contains 
//CHARLES DUFOUR,2011,168
ofstream& operator<<(ofstream & ofs,const Wine & w){
  ofs << w.get_name() << "," << w.get_year() << "," << w.get_price();
  return ofs;
}

int main() {
  ifstream ifs {"wine.txt"};
  vector<Wine> cellar;
  if(ifs){
  	for(Wine w; ifs >> w; cellar.push_back(w)){}
    for(Wine w:cellar) cout << w << endl;
	/*double s = 0.0;
	for(const Wine &w: cellar){
		//int i = (w.get_year() == 1999);
		//int n = (w.get_year() == 2003);
		if(w.get_year() == 1999 || w.get_year() == 2000 ||
		   w.get_year() == 2001 || w.get_year() == 2002 ||
		   w.get_year() == 2003) s += w.get_price();
	}
	cout << s << endl;
	cout << std::round(double(s/15)*100)/100;*/	
	
	ifs.close();  
	}
	Wine w; cout << w.get_avg(cellar); 
  /*ofstream ofs {"wine.txt",ios_base::app};
  if(ofs){
    Wine w;
    cout<<"Append a wine. (Ex. hello,1234,33.23):";
    cin>>w;
    ofs<<w<<endl;
  }*/
  return 0;
}


/*red,1998,33.33
DOM PERIGNON,1998,89.87
champange, 1998, 211.21*/
