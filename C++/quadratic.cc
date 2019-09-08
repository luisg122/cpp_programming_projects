#include <iostream>
#include <cmath>
using namespace std;
int main() {
    int a=0,b=0,c=0;
    cout<<"PROJECT2 - KWANG KIM"<<endl;
    cout<<"ax^2+bx+c=0 Calculator!"<<endl;
    cout<<"Type an integer coefficient a:";
    cin>>a;
    cout<<"Type an integer coefficient b:";
    cin>>b;
    cout<<"Type an integer coefficient c:";
    cin>>c;
    if(a==0){
        if(b==0){
            if(c==0) cout<<"all complex number x."<<endl;
            else cout<<"No solution."<<endl;
        }
        else{
            cout<<"x="<<static_cast<double>(-c)/b<<endl;
        }
    }
    else{
        double d=b*b-4*a*c;
        double part1=-static_cast<double>(b)/(2*a);
        if(d>0){
            double part2=sqrt(d)/(2*a);
            double x1=part1+part2;
            double x2=part1-part2;
            cout<<"x_1="<<x1<<", x_2="<<x2<<endl;
        }
        else if(d==0){
            double x=part1;
            cout<<"x="<<x<<endl;
        }
        else{
            double re=part1;
            double im=sqrt(-d)/abs(2*a);//>=0
            if(re!=0){
                if(im==1) cout<<"x_1="<<re<<"+i, x_2="<<re<<"-i"<<endl;
                else cout<<"x_1="<<re<<"+"<<im<<"i, x_2="<<re<<"-"<<im<<"i"<<endl;
            }
            else{
                if(im==1 ) cout<<"x_1=i, x_2=-i"<<endl;
                else cout<<"x_1="<<im<<"i, x_2=-"<<im<<"i"<<endl;
            }
        }
    }
    return 0;
}
