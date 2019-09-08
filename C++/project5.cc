//
//  main.cpp
//  p5-2
//
//  Created by KWANG KIM on 4/18/17.
//  Copyright © 2017 qcc.cs. All rights reserved.
//
#include <iostream>
#include <cstdlib>
#include <ctime>
#include <cmath>

using namespace std;
int randatob(int a,int b){ //function generates random values
    return rand()%(b-a+1)+a; // algorithm for generatinig random number values
}

int * rand_gen(int a,int b,int n){
    int * num=new int[n]; //memory allocation
    for(int i=0;i<n;++i){
        num[i]=randatob(a,b); //radomly gnerates number values for variables 'a' and 'b'
    }
    return num;
}
int * freq_table(int* array, int n){ //0<=x<100
    int begin=0,end=0;
    int * c=new int[10]();//initialzire as zero.
    for(int i=0;i<10;++i){
        begin=i*10;
        end=begin+10;
        for(int j=0;j<n;++j){
            // Credit:[Xin Li] you can replace if statement with
            // ++c[ array[j]/10 ];
            // then you can remove for loop of index i.
            if(begin<=array[j] && array[j]<end){
                ++c[i];
                break;
            }
        }
    }
    return c;
}
// freq is int type array with size 10.
double avg(int* array,int n){
    int s=0;
    for(int i=0;i<n;++i)
        s=s+array[i];
    return double(s)/n;
}
void show_table(int *freq){
    for(int i=0;i<10;++i){
        cout<<i*10<<"<=x<"<<(i + 1)*10<<":"<<freq[i]<<endl;
    }
}
int main(){
    srand(time(NULL)); //is there a difference between NULL and 0
    //srand((0)); //why can 'time' not be used in function
	int n=0;
    // Do not forget your name!
    cout<<"PROJECT 5- Luis Gualpa"<<endl;
    cout<<"Type the number of random numbers between 0 and 99:"<<endl;
    cin>>n;
    int * num=rand_gen(0,99,n);
    int * ft=freq_table(num,n);
    show_table(ft);
    cout<<"Average is "<<avg(num,n)<<endl;
    delete[] num;
    delete[] ft;
}
