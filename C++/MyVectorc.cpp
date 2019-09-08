#include<iostream>
#include<algorithm>
#include<utility>
//#include<vector>
using namespace std;
typedef unsigned int uint;		//unsigned int
class MyVector{
  private:
    uint sz;  						// current size sz<=cap
    uint cap; 						//size of capacity
    int  *data;
  public:
    MyVector();				 		// size 0 with nullptr therefore a default constructor
    MyVector(uint n);		 		// size n and cap=n. reserve heap memory with size n.
    MyVector(int *p,uint n); 		//copy from an array p with size n.
    MyVector(const MyVector &other);
    ~MyVector();
    void reserve(uint n); 			// reserve a heap memory with capacity n.
    void push_back(const int &val); //add val into the end of array
    MyVector &operator=(const MyVector &other);
    int &operator[](uint i); 		// return i-th term
    uint size();					//return sz
    uint capacity();				//return the size of capacity
    void print();
};
//------------------------------------------------------------------------------------
MyVector::MyVector():sz(0),data(nullptr){}				                  		//default constructor using scope (out-side class)
MyVector::MyVector(uint n):sz(n),cap(n){
	if(cap > sz)reserve(n);
}		
MyVector::MyVector(int *p, uint n):sz(n),cap(n),data(n ? new int[n]:nullptr){	//initializer constructor,
																				// DO NOT FORGET TO INITIALIZE ALL DATA MEMBERS from PRIVATE
	if(n)	std::copy(p,p+n,data);												//DEEP COPY
} 
MyVector::MyVector(const MyVector &other):MyVector(other.data, other.sz){}		//copy constructor delegating initializer constructor
MyVector::~MyVector(){delete[] data;}											//destructor

void MyVector::reserve(uint n){
	if(n > cap){
        int *tmp = new int[n];
        std::copy(data,data+sz,tmp);
        delete[] data;
        data = tmp;
        cap  = n;
    }
}
//------------------------------------------------------------------------------------
void MyVector::push_back(const int &val){		//adding val into the end of the array
	
	
    /*int *temp = new int[sz + 1];				//points to the last cell of array, where value will  be added to array 
    for (uint i = 0; i < sz; i++)
		{temp[i] = data[i];}					//pushes values at the end of array
    //std::copy(data, data + sz; temp);         //DEEP COPY FUNCTION, ACHEIVES THE SAME THING ^^^
	
	
	temp[sz] = val;								//temp is new int[sz+1]; so temp[sz] = last element
    delete[] data;  							//NO undefined behavior because pointer pointed to an arrya of objects
    											//returned by new <type>[]
    data = temp 								//AVOID a dangling pointer
    */
	 
	 reserve(sz + 1);
	 data[sz] = val;
	 sz += 1;							        
}
//------------------------------------------------------------------------------------
MyVector &MyVector::operator=(const MyVector &other){		//transfer values of array to another array 
	if(this != &other){										//'this pointer' is the address of object mb, and &other is object ma															//both arrays of data-type 'MyVectif(this != &other){	                     				//right-left DATA TRANSFER
		if(other.sz > cap){	    							//this pointer points to object instantiated in int main function
    	int *tmp = new int[other.sz];
    	std::copy(other.data,other.data + other.sz,tmp);    //DEEP COPY
    	delete[] data;
    	
		data = tmp;
    	cap  = sz = other.sz;
    	}
	}
    else{
        std::copy(other.data,other.data+other.sz,data); // other.sz == 0 -> skip. 
        sz = other.sz;
    }
  return *this;			//return the address of left object for (right ==> left data transfer)
}
//-------------------------------------------------------------------------------
int &MyVector::operator[](uint i){return data[i];}
uint MyVector::capacity() {return cap;}
uint MyVector::size(){return sz ;}
void MyVector::print(){
	for(uint i = 0; i < sz; i++){
		cout << data[i] << " ";
	}
	cout << endl;
}

int main(){
		
	cout << "Luis Gualpa - Project 2" << endl;
	cout << "=======================\n"; 
	
	int a[3]={1,2,3};
    MyVector ma(a,3), mb;
    mb = ma;                     //Using "Deep Copy" for assignment operator
    MyVector mc = mb;
    
	mb = mb;
    
    ma[0]=3;
    mb[1]=7;
	    
    mb.push_back(10);
    mb.push_back(11);
    	
	
	ma.print();
    mb.print();
    mc.print();
    
    cout << endl << endl;

	cout << ma.capacity() << endl;
	cout << mb.capacity() << endl;
	cout << mc.capacity() << endl;
			
	cout << "\n=======================\n";
	return 0;


}

//using a reference as a function parameter is DIFFERENT than using a reference as an argument 
