#include <iostream>
using namespace std;
class Point2D{
    protected: 
        int x,y;
    public:
        Point2D():x{0},y{0}{}
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
  
  Point3D *pt1 = &pt;
  pt1 -> show();
  //*(pt1).show();
  
  return 0;
}
