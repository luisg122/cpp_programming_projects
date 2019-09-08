#include<iostream>
#include<cstring>
#include<algorithm>
#include<utility>
typedef unsigned int uint;
using namespace std;

class MyString{
	
	private:
		char *str;
	public:
		MyString(const char *s){
			if(s){
				uint n = strlen(s);
				str = new char[n + 1];
				strcpy(str,s);
					
			}
			else{
				str = new char[1]{0};
				
			}			
		}
		
		MyString():str(new char[1]{0}){}
		~MyString(){delete[] str;}
		MyString(const MyString &other){
			
			uint n = strlen(other.str);
			str    = new char[n + 1];
			strcpy(str, other.str);
		}
		
		const char *c_str(){return str;}
		MyString &operator=(const MyString &other);
};

MyString &MyString::operator=(const MyString &other){
	if(strlen(other.str)){
		
		uint n = strlen(other.str);
		char *tem    = new char[n + 1];
		strcpy(tem,other.str);
		delete[] str;
		str = tem;
	}
	else return *this;
}
