#include <iostream>
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
}
