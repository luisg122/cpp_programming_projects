//CONVERT DECIMAL TO BINARY
#include <iostream>
#include <cstring>
#include <cmath>
#include <cstdlib>
#include <string>
 
double dec2Bin(int value, char binaryString[])
{
    int x = 1;
    std::string hold = "";
    while(x <= value){
        x *= 2;
    }
    x /= 2;
 
    while(x >= 1){
        //cout << x << " ";
        if(value > x){
            hold += "1";
            value -= x;
        }
        else if(value < x){
            hold += "0";
        }
        else if(value == x){
            hold += "1";
            value = 0;
            //return hold;
        }
        x /= 2;
 
        //cout << hold << endl;
    }
    return atoi(hold.c_str());
 
}
int main()
{
    char binstr[100];
    int num = 0;
    std::cout << "Enter a decimal string: ";
    std::cin >> num;
    std::cout << "its "<<dec2Bin(num, binstr) << std::endl;
 
}
