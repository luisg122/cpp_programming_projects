#include <iostream>
#include <cmath>
using namespace std;
// We assume n>=0
int prime_decomposition(int n){
    if(n<=0) return 0;
    if(n==1){
        cout<<1<<endl;
        return 0;
    }
    const int sq=sqrt(n);//const renders a variable with assigned value not to change
    for(int i=2;i<=sq;++i){
        if(n%i==0){
            cout<<i<<"*";
            return prime_decomposition(n/i)+1;
        }
    }
    //prime
    cout<<n<<endl;
    return 1;
}
int main(){
    int n=0;
    cout<<"PROJECT 3-Prime Decomposition - KWANG KIM"<<endl;
    while(n<=0){
        cout<<"Type a positive integer:";
        cin>>n;
    }
    cout<<n<<"=";
    int c=prime_decomposition(n); //Print
    if(c<=0) cout<<"There is no prime factor."<<endl;
    else if(c==1) cout<<"There is 1 prime factor."<<endl;
    else cout<<"There are "<<c<<" prime factors."<<endl;
}

55555
