#include<iostream>
#include <cstring>
using namespace std;
typedef unsigned int uint;

class MyString{
	
	private:
		char *str;			//difference between char s[], and char *s?
	public:
		MyString(const char *s){
			if(s){							//if s != 0;
				uint n = strlen(s);
				str = new char[n + 1];		//why n + 1, is that for a null-terminated string?
				strcpy(str,s);
			}
			else{
				str =  new char[1]{0};		//why the zero?
			}
		}
		
		MyString():str(new char[1]{0}){}
		~MyString(){delete[] str;}
		const char *c_str(){return str;}
		
		MyString(const MyString &other){
			uint n = strlen(other.str);
			str = new char[n + 1];
			strcpy(str, other.str);
		}
		
		MyString &operator=(const MyString &other){
				if(strlen(other.str)){			//of (str.len(other.str)) not equal to zero
				uint n    = strlen(other.str);
				char *tem = new char[n + 1];
				strcpy(tem,other.str);
				delete[] str;
				str = tem;			
			}
			else return *this;
			
		}
};

int main(){
	
	MyString s1("hello");
	MyString s2 = s1;
	cout << s2.c_str() << endl;
	
	const void *p1 = s1.c_str();
	const void *p2 = s2.c_str();
	
	cout << p1 << endl;
	cout << p2 << endl;
	
	
	return 0;	
}

