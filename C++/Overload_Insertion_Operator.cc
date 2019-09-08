#include<iostream>
using namespace std;
struct Date{
	int y,m,d;
	Date():y(1900),m(1),d(1){}
	Date(int y1,int m1,int d1):y(y1),m(m1),d(d1){}

};
ostream &operator<< (ostream &os, Date current){
	os << current.m << "/" << current.d << "/" << current.y;
	return (os);
}

istream &operator>> (istream &is, Date current){
	is >> current.m >> current.d >>  current.y;
	return (is);
}

int main(){	//constructors are initializing structures
	Date day(2018, 4, 30);
	cout << day << endl;
	
	Date d;
	cin  >> d;
	cout << d;
	
	return 0;
}
