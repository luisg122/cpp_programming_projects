#include<iostream>
#include <algorithm>
using namespace std;
typedef unsigned int uint;
class MyArray{
  private:
    uint sz;
    int *data;
 	void swap(int &a, int &b);	//having reference parameters, passing EXACT COPIES
  public:
    									
    
	MyArray(int *p, uint n):sz(n), data(sz ? new int[n]: nullptr){ //in-class initializer constructor
        if(sz)  std::copy(p, p + n, data);}
    
	
	MyArray():sz(0),data(nullptr){}									////default constructor
	
	MyArray(const MyArray &other):MyArray(other.data,other.sz){}	//copy constructor delegating what exactly?
    
	~MyArray(){delete[] data;}										//deconstructor

    /*MyArray(int * p, uint n){
      sz=n;
      if(sz){
        data=new int[sz];
        std::copy(p,p+sz,data);
      }
      else data=nullptr;
    }*/





    MyArray &operator=( const MyArray &other);
    
	uint size(){return sz;}
    
	int &operator[](uint i){
      return data[i];}
    
	void print(){
        for(uint i = 0; i < sz; i++){ 
            cout << data[i] << "\t";}
            cout << endl;
    }
    
	void sort();
};

MyArray &MyArray::operator=(const MyArray &other){
  if(this != &other){  
  	//cout << this << endl;			//addresses are NOT the same;therefore, it avoids duplications
  	//cout << &other << endl;		//just want to transfer data (from previous data), NOT creat NEW DATA
  	
	if(other.sz){
    	int *tmp = new int[other.sz];
    	std::copy(other.data,other.data + other.sz,tmp);
    	delete[] data;
    	data = tmp;
    	sz   = other.sz;
    }
  else{
  	delete[]data;
  	data = nullptr;
  	sz = 0;
  	}	
  
  }
  return *this;
}

void MyArray::swap(int &a,int &b){	//passing by reference, "PASSING EXACT COPIES " Hence, 'ALIAS'
	int t = a;
	a = b;							//references cannot be reassigned
	b = t;							//pointers CAN be reassigned
									    //GENERALLY, THEY BOTH ACHEIVE THE SAME THING
									    //HOWEVER, PASSING BY REFERENCE IS CONSIDERED 'SAFE'
}
void MyArray::sort(){
	
	
	for(uint i = 0; i < sz ; i++){
		for(uint j = 1; j < sz; j++){
			if(data[j - 1] > data[j])
			{
				swap(data[j - 1],  data[j]);
			}
		}
	}
	print();
}

int main(){
		
	int a[3] = {1,2,3};
	MyArray ma(a,3),md(ma);
	MyArray mb(a,3);
	//MyArray mg[7];	//not to be confused with the bracket operator declared/defined
						//for class MyArray, the bracket is simply indicating to CREATE
						//7 objects of with the user-defined type MyArray(QUITE CONFUSING)
						
	mb = ma;			//(this!=&other), where this contains address of ma, and &other, the 
						//address of ma
	
	//mc = ma;			//(this!=&other) DOES NOT APPLY, because BOTH object contain
						//the same address!!, therefore (this == &other)
    
	//mb = ma;
	MyArray mc = mb;
	mb[1] = 7;
	mc[1] = 10;
	
	
	cout <<   "ARRAY A: ";
	ma.print();
	cout << "\nARRAY B: ";
	mb.print();
	cout << "\nARRAY C: ";
	mc.print();
	cout << "\n\nSORTING ARRAY A: ";
	ma.sort();
	cout << "\nSORTING ARRAY B: ";
	mb.sort();
	cout << "\nSORTING ARRAY C: ";
	mc.sort();
	return 0;
}
