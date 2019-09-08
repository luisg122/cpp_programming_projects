//Inheritance, subclass 
//general idea to a more specific idea
//subclass inherits properties from another class
//why is the usage of the keyword 'friend' dangerous 
#include<iostream>
using namespace std;

class Shape{
    //private:
      protected:	//only subclasses can USE properities  
		int width;
        int height;
    public:
        //void set(int w,int h){width=w;height=h;}
		Shape(int w,int h){width=w;height=h;}		//constructor 
};
class Rectangle : public Shape{	//subclasses cannot inherit private properties
    public:
        using Shape::Shape;		//why the USING keyword?
        //Rectangle(int w, int h)
        
        
		int getArea(){return width*height;}
};
int main(){
	
	Rectangle rec(2,3);		//to find the area of the rectangle 
	//rec.set(5,6);
	cout << rec.getArea();
	return 0;
}
//Subclass CANNOT initialize value for the Parent Class
//inadequate constructor
//use delegation to fix for inadequate constructor 

/*#include <iostream>
using namespace std;
class Point2D{
    protected: 
        int x,y;
    public:
        Point2D()/:x{0},y{0}{}
        Point2D(int nx,int ny):x{nx},y{ny}{}
};
class Point3D:public Point2D{
    protected:
        int z;
    public:
    using Point2D::Point2D;//How about z?
    Point3D():Point2D(),z{0}{};
    Point3D(int nx, int ny, int nz):Point2D(nx, ny), z{nz}{}
    void show(){
      cout<<"x="<<x<<", y="<<y<<", z="<<z<<endl;
    }
};
int main(){
  Point3D pt(3,2,4);
  pt.show();
}*/




/*#include <iostream>
using namespace std;
class Vehicle {
    protected:
        string license ;
        int year ;
    public:
        Vehicle ( const string & myLicense , const int myYear ): license{myLicense}, year { myYear } {}
        const string & get_lisence () const { return license ;}
        const int get_year () const { return year ;}
        virtual const string get_desc() = 0;
        virtual const string  get_style() = 0;
};
class Car: public Vehicle{
  private:
    string style;
  public:
    using Vehicle::Vehicle;
    Car(string l, int y, string s):Vehicle(l, y), style{s}{}

    
    const string get_style(){return style;}
    const string get_desc(){
      return to_string( year ) + " " + style + ": " + license;
    }
};
int main(){
    Car ford{"QCC123",2018,"sedan"};
    Vehicle * vp= & ford;
    cout<<vp->get_desc()<<endl;
    return 0;
    //need a default constructor, when value of user-defined type 
    //is not initialized
}*/
