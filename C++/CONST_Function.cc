#include<iostream>
using namespace std;
 
class Test {
    int value;
public:
    Test(int v):value(this->value = v){}	//remember that constructors are used to initialize!!!
	//Test(int v = 0) {this->value = v;}
    //the 'pointer si used to retrieve the object's x hidden by the local variable v
    
    // We get compiler error if we add a line like "value = 100;"
    // in this function.
    int getValue() const {return value;}  
};
 
int main() {
    Test t(20);
    cout<<t.getValue();
    return 0;
}
