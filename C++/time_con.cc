//program processing an input of seconds and formatting in terms of hour, minute, and seconds

#include<iostream>
using namespace std;
int main(){

	int hour, mint,seco,temp,seconds;

	cout << "insert amount of seconds:";
	cin >> seconds;

	seco = seconds%60;
	temp = seconds/60;      //temp for temporary variable value?

	mint = temp%60;         //apparently 3 mod 60 == 3, (less number) % (greater number) == (less number)
	hour = temp/60;         //variable value of type 'int' meaning it's does integer division


	cout << "Hour = " << hour << " Minute = " << mint << " Second = " << seco << endl;

	return 0;
}
