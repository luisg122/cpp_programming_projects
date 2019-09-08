#include<iostream>
using namespace std;

int main()
{

    double ctemp = 0.0, ftemp = 0.0; //ctemp --> Celsius and ftemp--> Fahrenheit

    cout << "Input a Celsius temp and press ENTER: ";
    cin >> ctemp;
    ftemp = (ctemp * 1.8) + 32.0;
    cout << "Fahrenheit temp is: " << ftemp << endl;
    if(ctemp == 0){
        cout << "This is known as the 'Melting Point' " <<  endl;
    }
    else if (ctemp == 100){

        cout << "This is known as the 'Boiling Point'" << endl;
    }
    return 0;
}
