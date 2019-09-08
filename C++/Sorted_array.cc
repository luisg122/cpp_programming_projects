#include <iostream>
using namespace std;

int main()
{
   int numbers[10];
   int value, counter = 0;
   bool skipFlag = true;
// loops from 0 to 99 and read input
for (int i=0; i < 10; i++){
 	
	cout << "Enter number #" << (i + 1) << ":"; 
	cin >> value;
    skipFlag = false;
    cout << counter;
    for(int j = counter; j >= 0 ; j--)
    {
    // if value already found
    	if(j != 0 && numbers[j-1] == value)
   		{
       		skipFlag = true;
   			break;
  		}
    }
    // if already found skip this
    if(skipFlag == 0)
    {
    	for(int j = counter; j >= 0 ; j--)
        {
       		if(j != 0 && numbers[j-1] > value) // if the value is greater then numbers[j - 1], shift element next cell
       		{
       			numbers[j] = numbers[j-1] ;
       		}
       		else
       		{
          		 // place the value in sorted position
       			numbers[j] = value;
                counter++;
       			break;
       		}
       	}
    }
}
cout << "The number in sorted order and with all duplicates(if any) removed : ";
for(int i = 0 ; i < counter ; i++)
{
	cout << numbers[i] << " ";
}	
cout << endl;
return 0;
}
