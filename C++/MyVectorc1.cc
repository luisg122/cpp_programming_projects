#include<iostream>
#include<algorithm>
#include<utility>
using namespace std;
typedef unsigned int uint;
class MyVector{
  private:
    uint sz;  // current size sz<=msz
    uint cap; // size of capacity
    int * data;
  public:
    MyVector():sz(0),cap(0),data(nullptr){}
    MyVector(int *p,uint n):sz(n),cap(n),data( sz ? new int[n]:nullptr){
      if(n) {
          std::copy(p,p+n,data);
      }
    }
    MyVector(const MyVector &other);
    ~MyVector();
    void reserve(uint n){
        if(n > cap){
            int *tmp = new int[n];
            std::copy(data,data+sz,tmp);
            delete[] data;
            data=tmp;
            cap=n;
        }
    }
    void push_back(const int & val){
        reserve(sz+1);//more memory to add.
        data[sz]=val;
        sz=sz+1;
    }
    MyVector & operator=(const MyVector &other);
    int& operator[](uint i);
    uint size(){return sz;}//return sz
    uint capacity(){return cap;}// return the size of capacity
    void print(){
      if(sz){
        for(uint i = 0; i < sz; ++i) cout<<data[i]<<" ";
            cout << endl;
      }
    }
};
MyVector::MyVector(const MyVector& other):MyVector(other.data,other.sz){}
MyVector::~MyVector(){
    delete[] data;
}
MyVector& MyVector::operator=(const MyVector & other){
    if(this!=&other){
        if(other.sz > cap){
            int *tmp = new int[other.sz];
            std::copy(other.data,other.data+other.sz,tmp);
            delete[] data;
            data=tmp;
            cap=sz=other.sz;
        }
        else{
            std::copy(other.data,other.data+other.sz,data); // other.sz == 0 -> skip. 
            sz=other.sz;
        }
    }
    return *this;
}
int& MyVector::operator[](uint i){
    return data[i];
}
int main(){
    int a[3]={1,2,3};
    int b[4]={6,7,8,9};
    MyVector ma(a,3), mb,md(a,4);
    mb=ma;//assignment
    MyVector mc=mb;
    mb=mb;
    md=ma;
    ma[0]=3;
    mb[1]=7;
    mb.push_back(10);
    mb.push_back(11);
    ma.print();
    mb.print();
    mc.print();
    cout << endl << endl << endl;
	
	cout << ma.capacity() << endl;
    cout << mb.capacity() << endl;
	cout << mc.capacity() << endl;
    cout << md.capacity() << endl;

    
    
    return 0;
}
