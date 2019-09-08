#include <iostream>
using namespace std;
class Shape {
    protected:
        int width, height;
    public:
        Shape(int w, int h):width(w),height(h){/*print();*/}
        virtual void print(){cout << "Shape w = " << width << ", h = " << height << endl;}
        virtual double get_area() = 0; //dummy pure virutal 
        //determine proper member function in subclass 
};
class Rectangle: public Shape {
    public:
        using Shape::Shape;
        double get_area(){ return width * height;}
        void print(){cout << "Rec w = " << width << ", h = " << height << endl;}
};
class Triangle: public Shape {
    public:
        using Shape::Shape;
        double get_area(){ return width * height/2.0; }
        void print(){cout << "Tri w = " << width << ", h = " << height << endl;}
};
int main(){
    Rectangle rec (4,5);
    Triangle  tri (4,5);
    Shape *pr = &rec;
    Shape *pt = &tri;
    pr->print();
    pt->print();
    cout << "Area(rec) = " << pr->get_area() << ", Area(tri) = " << pt->get_area();

	
	cout << endl;
	rec.print(); 
	tri.print();
	cout << "Area(rec) = " << rec.get_area() << ", Area(tri) = " << tri.get_area();
	return 0; 
}
