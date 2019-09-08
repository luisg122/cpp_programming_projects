//memebers of a data structure declared with CLASS keyword are PRIVATE by default
//meaning data fields and methods CANNOT be accessed outside of the class
//you must use the PUBLIC keyword to access data fields and method outside of class

#include<iostream>
using namespace std;

class Point{				//should class identifiers generally have initial capital letter?
							//STANDARD BOILER-PLATE CLASS STRUCTURE 
						
							//ALWAYS FIND OUT WHAT DATA STRUCTURE YOU WANT TO WORK WITH
	public:
	int x = 0, y = 0;
};							//A CLASS MUST END WITH A SEMI-COLON AFTER CLOSING CURLY BRACKET

int main(){					//AFTER CLASS DECLARATION, YOU CAN NOW CREATE OBJECTS(instances)
	Point pt1, pt2, pt3;
	
	pt1.x = 0;				//assign values to instances using data members/data fields 
	pt1.y = 1;
	
	cout << pt1.x + pt1.y << endl;
//---------------------------------------------------------------------------------------------	
	pt2.x = 2;
	pt2.y = 3;
	
	cout << pt2.x + pt2.y << endl;
//---------------------------------------------------------------------------------------------	
	pt3.x = 4;
	pt3.y = 5;
	
	cout << pt3.x + pt3.y << endl;
//---------------------------------------------------------------------------------------------
	return 0;
}
