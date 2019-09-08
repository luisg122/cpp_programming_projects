//bitwise operators are used to work on bits
//bits are the smallest units of info stored into our computers
//bits are represented by 0 and 1
#include<iostream>

using namespace std;

int main(){

    /*
        0
        1
        0101010 0101
        computer notation is similar to decimal notation
        example of decimal notation ==>> 126 = 1*10^2 + 2*10^1 +6*10^0 = 100 + 20 +6
        example of binary notation ==>> 1 0 1 0= 1*2^3 + 0*2^2 + 1*2^1 + 0*2^0 = 8 + 2 = 10

    */
     /*
        //bitwise operators work on bits, unlike relational operators which work on conditions
        Bitwise AND -> &
        Bitwise OR -> |
        Bitwise NOT -> ~ (tilde)
        Bitwise XOR -> ^ (caret) eXclusive OR // there must exist an alternative
        Bitwise left shift <<
        Bitwise right shift >>
     */

    cout << (10 & 2) << endl; //Bitwise AND

    /*
        both arguments must be true or else they're false, expression are related in columns
        1 0 1 0
        0 0 1 0
        -------
        0 0 1 0
        therefore the console will output 2
    */

    cout << (10 | 2) << endl; //bitwise OR

    /*
        it is false ONLY if both arguments are false or else true
        1 0 1 0
        0 0 1 0
        -------
        1 0 1 0
    */

    cout << (10 ^ 2) << endl; // Bitwise XOR ( eXclusive OR) if there are alternatives then it is true, if there are no alternatives, then false
    /*
        1 0 1 0 //alternative accounts for when no two elements in a column are the same and it relates to that position of the bit and defines its binary value
        0 0 1 0
        -------
        1 0 0 0
        XOR the must exist an alternative for it to be true
    */

    /*
        cout << (~10) << endl; // Bitwise NOT //apparently add a neg 1 to the already negated value in parenthesis

        00000000000000000000000 1 0 1 0
        111111111111111111111111 0 0 1 0
    */

    cout << (10 << 1) << endl; // Bitwise left shift
    /*
         1 0 1 0 becomes 1 0 1 0 0 ==>> 2^5 + 2^2 = 16 + 4 = 20

    */
    cout << (10 >> 1) << endl; // Bitwise right shift
    /*
        1 0 1 0 becomes 0 1 0 1 ==>> 2^2 + 2^0 = 4 + 1 = 5
    */

    return 0;
}
