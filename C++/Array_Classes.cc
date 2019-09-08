#include<iostream>
#include <algorithm>
using namespace std;
typedef unsigned int uint;		//user-defined datatype for using positive integers, shortcut to avoid writing 
								//unsigned int constantly, excludes negative integersand include positive integers
class MyArray{
  private:
    uint sz;
    int *data;
  public:
    MyArray():sz(0),data(nullptr){}		//default constuctor, is the nullptr the offset of an array
    
	MyArray(int * p, uint n){			//what type of constructor is this?
      sz=n;
      if(sz){							//if sz is not equal to zero
        data=new int[sz];
        std::copy(p,p + sz,data);
      }
      else data = nullptr;
    }
    MyArray(const MyArray &other):MyArray(other.data,other.sz){}
    ~MyArray(){delete[] data;}
    MyArray& operator=(const MyArray &other);
    
	uint size(){return sz;}

	int &operator[](uint i)
	{
      return data[i];
    }
    
};
MyArray& MyArray::operator=(const MyArray &other){				//Assignment operator
  if(this!=&other){
    int * tmp=new int[other.sz];
    std::copy(other.data,other.data+other.sz,tmp);
    
	delete[] data;
    data=tmp;
    sz=other.sz;
  }
  return *this;
}

int main(){
	
	
	
	
	return 0;
}
