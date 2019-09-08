#include <iostream>
#include <string>
using namespace std;
int co(string pre,int s,int e,int r){
    if(e-s+1<r) return 0;
    if(r==0) {cout<<pre<<endl;return 1;}
    int c=0;
    for(int i=s;i<=e;++i){ // you can optimize this using e-(i+1)+1>=r-1  (it means e-r+1>=i)
        c=c+co(pre+to_string(i),i+1,e,r-1);
    }
    return c;
}
int combi(int n,int r){
    return co("",1,n,r);
}
int main(){
    int n=0,r=0;
    cout<<"PROJECT 3- COMBINATION nCr - KWANG KIM"<<endl;
    while(n<=0 || n>9){
        cout<<"Type a number n between 1 and 9:";
        cin>>n;
    }
    cout<<"Type a number r between 1 and "<<n<<":";
    cin>>r;
    if(n<r){
        cout<<"n="<<n<<" is less than r="<<r<<". Stop."<<endl;
        return 0;
    }
    int c=combi(n,r);
    if(c<=0) cout<<"There is no possibility."<<endl;
    else if(c==1) cout<<"There is 1 possibility."<<endl;
    else cout<<"There are "<<c<<" possibilities."<<endl;
}
