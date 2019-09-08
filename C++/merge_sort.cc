#include <iostream>
#include <vector>
using namespace std;
void print(const vector<int> &v,int f,int l){
    for(int i=f;i<l;++i) cout<<v[i]<<" ";
    cout<<endl;
}
void print(const vector<int> &v){
    print(v,0,v.size());
}
void merge(vector<int>& v,int f,int m,int l){
    //if(v[m-1]<=v[m]) return;// already sorted
    vector<int> L(v.begin()+f,v.begin()+m), R(v.begin()+m,v.begin()+l);//duplicate.
    //code
    int i=0,j=0,k=f;
    int ei=m-f,ej=l-m,ek=l;
    while(k<l){
      if(i>=m-f){
        copy(R.begin()+j,R.end(),v.begin()+k);
        //k=l;
        break;
      }
      else if(j>=l-m){
        copy(L.begin()+i,L.end(),v.begin()+k);
        //k=l;
        break;
      }
      if(L[i]<R[j]) v[k++]=L[i++];
      else v[k++]=R[j++];
    }
}
int main() {
  vector<int> v={1,2,3,9,2,4,7};
  merge(v,0,4,7);
  print(v);
}
