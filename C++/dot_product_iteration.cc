//dot product
//heap memory

//indexing is important
//data type conversion is vital
//the computer naturally indexes from 0
#include<iostream>
#include<string>
using namespace std;
int dot(int *v1, int *v2, int n){ //uses pointer reference
    int s=0; //i=-1; initializing and declaring variable 's'
    for(int i=0;i<n;++i){
    s += v1[i] * v2[i]; //multiplication of corresponding elements of each matrix
    }
    return s; //classic boiler plate iteration
}

int main(){
    int a=0,b=0,c=0,d=0,e=0,f=0;


    int v1[3]={&a,&b,&c};
    int v2[3]={&d,&e,&f};
    cout << dot(v1,v2,3); //n is equal to 3 where the loop is processed three times, three loops to multiply three elements of each vectors with corresponding positional elements
    cout << endl;

    //cout << *v1   << endl;	  	//example of pointer dereferencing
    //cout << v1[0] << endl;		//example of pointer index/dereferencing, "stepping trough an array, pointing to particular cell memeory address and grabbing its content(i.e., dereferncing),x
    							//first cell of array is the initialized to zero

    //cout << v1[1] << endl;
    //cout << v1[2] << endl;


    return 0;
}

