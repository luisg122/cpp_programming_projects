//A CLASS OR DATA DECLATION ALWAYS ENDS WITH A SEMI-COLON
//the general term class and the keyword CLASS are NOT co-extensive
//it's possible to have a class that is not created with with the keyword CLASS 
//the purpose of a class is usually to add FUNCTION members
//A CLASS IS A COMBINATION of closely related FUNCTIONS and data structures
#include<iostream>
using namespace std;

class Point {
	
	private:
		int x, y;
	public:
		void set(int new_x, int new_y);
		int get_x();
		int get_y();
	
};
//member functions don't work by magic, they have to be defined somewhere
//you can place the function definition anywhere, as long as the class has been declared
//must use SCOPE OPERATOR '::' to notify the compiler that the functions definitions
//apply to the CLASS in scope

void Point::set(int new_x, int new_y){	//understand WHERE to apply you cond. statements

	x = new_x;
	y = new_y;
	if(x < 0)	x *= -1;
	if(y < 0) 	y *= -1;
}
int Point::get_x(){
	
	return x;
}
int Point::get_y(){
	
	return y;
}

int main(){
	
	Point pt1;
	pt1.set(10,-20);
	
	cout << "Point 1 is: (" << pt1.get_x() << ", " 
	<< pt1.get_y() << ")" << endl;
//-------------------------------------------------------------	
	Point pt2;
	pt2.set(-50,-25);
	cout << "Point 2 is: (" << pt2.get_x() << ", "
	<< pt2.get_y() << ")" << endl;
//--------------------------------------------------------------
	Point pt3;
	pt3.set(-49,88);
	cout << "Point 3 is: (" << pt3.get_x() << ", "
	<< pt3.get_y() << ")" << endl;
	
	
	return 0;
}
