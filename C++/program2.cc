#include<iostream>
#include<cmath>
#include<string>
using namespace std; //must have a namespace for predefine routines when using headerfile 'isotream' using preprocessor directive
const double pi=3.141256;
double f(int n);
int main(){
    int n=0;
    cout << " Approximate computation of PI multiplied with a number squared" << endl;
    cout << endl;
    cout << endl;
    string s1= "Input a positive integer:";
    cout << s1;
    cin >> n;
    cout <<endl;
    string s2 = "Your computed answer is ";
    cout << s2 << f(n) << endl;
    cout << endl;
    return 0;

}
double f(int n){

    if(n!=0)return  double (f(n-1.0)+ pow(n,2.0))*pi*1.0; //to output an appoximate answer with decimals, you must use double data type with argument in decimal form 
    else if (n==1) return pi;



}
