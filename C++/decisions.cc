//Program to determine if number is wither odd or even
#include<iostream>
using namespace std;

int main(){

    int n = 0, remainder = 0;

    //prompt and and input values for variables n, remainder

    cout << "Enter a number and press ENTER: ";
    cin >> n;

    //Get remainder after dividing by 2

    remainder = n % 2; //using modulus function to determine if number from end-user input is either odd or even

    if(remainder == 0) cout << "The number is EVEN" << endl;

    else cout << "The number is ODD" << endl;

    return 0;










}
