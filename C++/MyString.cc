#include <cstring>
#include <iostream>
using namespace std;
typedef unsigned int uint;
class MyString {
private:
	char *str;

public:
	MyString(const char *s) {                               
		if (s) {
			uint n = strlen(s);
			str = new char[n + 1];
			strcpy(str, s);
		} else {
			str = new char[1]{0}; 							// assign the zero.
		}
	}
	MyString():str(new char[1]{0}){}                        //default constructor
	~MyString() {                                            //deconstructor
		delete[] str;
	}
  const char *c_str() {
		return str;
	}
	MyString(MyString const &other) {                            //copy constructor
		uint n = strlen(other.str);
		str = new char[n + 1];
		strcpy(str, other.str);
	}
	MyString &operator=(MyString const &other) {                //assignment operator
		if (strlen(other.str)) {
			uint n = strlen(other.str);
			char *tem = new char[n + 1];
			strcpy(tem, other.str);
			delete[] str;
			str = tem;
		}
		else return *this;
	}
};
int main() {
	MyString s1("hello"), s2, s3;
	s2=s1;
	// s1.c_str()[0]='a';
	cout << s2.c_str() << endl;
	const void *p1 = s1.c_str();
	const void *p2 = s1.c_str();
	cout << p1 << endl;
	cout << p2 << endl;
} 
