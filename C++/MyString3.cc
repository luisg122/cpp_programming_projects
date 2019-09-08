#include<iostream>
#include<cstring >
using namespace std;
typedef unsigned int uint;

class MyString{

	private:
		 char *str;

	public:
		MyString(const char *s){
			if((s)){
				uint n = strlen(s);
				str = new char[n + 1];			//+1 for the null terminator of string
				strcpy(str,s);
			}
			else{
				str = new char[1]{0};	        //characters are set/INITIALIZED to ZERO
			}
		}
		MyString():str(new char[1]{0}){}		//delegating notation can include (),{}
		~MyString(){delete[] str;}

		const char *c_str(){return str;}

		MyString(const MyString &other){
			uint n = strlen(other.str);
			str = new char[n + 1];
			strcpy(str,other.str);
		}

		MyString &operator=(const MyString &other){
			if(strlen(other.str)){
				uint n = strlen(other.str);
				char *tem = new char[n + 1];
				strcpy(tem,other.str);
				delete[] str;
				str = tem;

			}
			else return *this;
		}


};

int main(){

	MyString s1("hello"),s2;
	s2 = s1;
	cout << s2.c_str() << endl;
	cout << s1.c_str() << endl;


	return 0;
}
