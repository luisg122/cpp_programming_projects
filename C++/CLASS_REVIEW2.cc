//SMALL PROJECT
#include<iostream>
#include<string>
#include<cstdlib>
#include<cstdio>
using namespace std;

class Point{
	
	private:
		int x,y;
	public:
		void set_x(int new_x);
		void set_y(int new_y);
		int  get_x();
		int  get_y();
};

void Point::set_x(int new_x){
	x = new_x;
	if(x < 0  )  x *= -1;
	if(x > 100)  x = 100; 
}
void Point::set_y(int new_y){
	y = new_y;
	if(y < 0)    y *= -1;
	if(y > 100)	 y = 100; 
}
int Point::get_x(){
	return x;
}
int Point::get_y(){
	return y;
}


int main(){
	
	int n = 0, a = 0, b = 0;
	cout << "How many Cartesian (x,y) points would you to create?: ";
	//getline(cin, n);		//function only works for objects of string type
	cin >> n;
	Point points_in_array[n];
	
	for(int i = 0; i < n; i++){
		cout << "\nInput x: ";
		cin  >> a; 
		points_in_array[i].set_x(a);
		cout << "\nInput y: ";
		cin  >> b;
		points_in_array[i].set_y(b);
		cout <<"------------------\n";
	}
	system("cls"); 
	//printing Cartesian points for n - distinct objects in array of type Point 
	for(int i = 0; i < n; i++){
		cout << "Point " << i + 1 << ": (" << points_in_array[i].get_x()
		<< ", " << points_in_array[i].get_y() << ")\n";
		cout <<"------------------\n";
	}
	
	system("PAUSE");
	//getchar();
	//cout << "EXITING PROGRAM ...";
	
	return 0;
	
}
