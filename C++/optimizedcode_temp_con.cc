//optimized code of temp_conversion.cc
#include<iostream>
using namespace std;

int main(){

    double ctemp; //Celsius Temperature

    //prompt and input value of ctemp
    cout << "Input Celsius temp and press ENTER: ";
    cin >> ctemp;

    //Convert ctemp and output results

    cout << "Fahr. temp is: " << (ctemp * 1.8)+ 32.0 << endl;

    return 0;





}
