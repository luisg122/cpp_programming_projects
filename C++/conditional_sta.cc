//conditional statement / instruction
#include<iostream>

using namespace std;

int main(){

    int a,b;

  /*  cout << "Enter a: " ;

    cin >> a;

    cout << "Enter b: " ;

    cin >> b;

   if(a > b) cout << a << " > " << b << endl; //  a must be greater than b
    */

    // example of condition
    if(7 > 4) {cout << "something " << endl;} // brackets are placed to indicate that one statement will executed if condition is met

    cout << "test" << endl; // not ultimately affected by condition

    if (7 < 4 || 0 < 10) cout << "7>4 || 0 < 10" << endl;
    // OR -->> disjunction, false (0) ONLY if both expressions are false
    // OR -->> disjunction, if one expression is true then true (1)

    if (7 < 4 || 0 < 10 && (10 ==9)) cout << "7>4 || 0 < 10" << endl;
   //AND -->> conjunction, false(0) if one statement/expression is false
   //AND -->> conjunction , true(1) if BOTH expressions/ statements/ CONDITIONS are true

    a = 4;
    b = 10;

   if(a > b) cout << a << " > " << b << endl;

   else if (a < b) cout << a  << " < " << b << endl;

   else cout << "that instruction is executed ONLY if all of the conditions weren't met" << endl;




   return 0;





}
