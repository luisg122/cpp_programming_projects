//i statement is true, console output = 1; and if statement is false, console output will be 0
//logical operators
#include<iostream>
using namespace std;
int main(){

/*
    AND conjunction &&
    7>5 && 5!=10 // conjunction is true only if both expressions are true
*/
    cout << ( 7 > 5 && 5!=10) << endl;



/*

OR disjunction || (alternative)
disjunction is false ONLY when both expressions are false
*/

    cout << ( 7 >5 || 5!=10 ) << endl;

/*
    !(exclamation mark)

    ! (0) the result will be 1 //the exclamation mark negates from neg to pos
    ! (1) the result will be 0 // the exclamation mark negates form pos to neg

*/
    cout << !(7 > 5 || 5!=10 ) << endl;



    return 0;
}
// << means the insertion operator (used with cout)
// >> means the extraction operator (used with cin)
