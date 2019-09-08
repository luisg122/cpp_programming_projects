#include<iostream>
#include<algorithm>
#include<utility>
using namespace std;
typedef unsigned int uint;
class MyArray{
	private:
		uint sz;
		int *data;
	public:
		MyArray():sz(0),data(nullptr){}
		MyArray(int *p,uint n):sz(n),data(sz ? new int[sz]:nullptr){
			if(n)std::copy(p,p+n,data);
		}
		MyArray(const MyArray &other);
		~MyArray();
		MyArray &operator=(const MyArray &other);
		
		uint size(){return sz;}
		int &operator[](uint i);
		
		void print(){
			if(sz){
				for(uint i=0;i<sz;++i) cout << data[i] << " ";
			}
			cout << endl;
		}
};

MyArray::MyArray(const MyArray &other):MyArray(other.data,other.sz){}
MyArray::~MyArray(){
	delete[]data;
}
MyArray &MyArray::operator=(const MyArray &other){
	if(this!=&other){
		if(other.sz){
		int* tmp=new int [other.sz];
		std::copy(other.data,other.data + other.sz,tmp);
		delete[]data;
		data=tmp;
		sz=other.sz;
		}
	}
	else{
		delete[] data;
		data = nullptr;
		sz = 0;
	}
	return *this;
}
int &MyArray::operator[](uint i){
	return data[i];
}
int main(){
	int a[3]={1,2,3};
	MyArray ma(a,3),mb,md(ma);
	mb = ma;
	MyArray mc = mb;
	mb[1] = 7;
	mc[1] = 10;
	//md[2] = 12;
	
	ma.print();
	mb.print();
	mc.print();
	//md.print();
	
	return 0;
}
	
