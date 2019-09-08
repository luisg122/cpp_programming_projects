//dot product
//heap memory

//indexing is important
//data type conversion is vital
//the computer naturally indexes from 0
#include<iostream>
#include<string>
using namespace std;
int dot(int *v1, int *v2, int *aa, int n);
void print(int *v1, int *v2, int *aa, int n);


int main(){
    int a=10,b=20,c=30,d=40,e=50,f=60;


    int v1[3]={a,b,c};
    int v2[3]={d,e,f};
    
    cout << "(";
    for(int i=0; i< 3;i++){
    	
		cout << v1[i] << " ";
		    
	}
    cout << ")";
    cout << " * ";
    
	cout << "(";
	for (int i = 0; i < 3; i++){
    	
		cout << v2[i] << " ";
	}
    cout << ")";
    cout << " = ";
	
	
	
	
	int aa[6] = {0};
	dot(v1,v2,aa,3); //n is equal to 3 where the loop is processed three times, three loops to multiply three elements of each vectors with corresponding positional elements
    
	print(v1,v2,aa,3);
	
	
	
	cout << endl;
	
	cout << v1;		//implicit referencing by simply writing variable of array, address of first cell = offset of array
	
	return 0;
}

int dot(int *v1, int *v2,int *aa, int n){ //uses pointer reference
    //int s=0; //i=-1; initializing and declaring variable 's'
    for(int i=0;i<n;++i){
    aa[i]= v1[i] * v2[i]; //multiplication of corresponding elements of each matrix
    }
   
}







void print(int *v1, int *v2,int *aa, int n){

	cout << "(";
	for(int i = 0; i < n; i++){
		
	
		cout << aa[i] << " "; 
		
	}
	cout << ")";

}
