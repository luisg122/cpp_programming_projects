//multiplying a value three times, or having a number raised to the third power
#include<iostream> //preprocessor directive with headerfiles/library inside tag
#include<cmath>
using namespace std;
int main(){

    int num = 0.0;

    //Prompt and input value for var. num
    cout << "Input an integer num and press ENTER: ";
    cin >> num;

    //compute and output updated value of num
    cout << "Value of number multiplied by itself 3X is: " << pow(num, 3) << endl; //using pow() function/ operator/ predefined function

    return 0;



}
