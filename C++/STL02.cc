#include <iostream>
#include <list>
#include <utility>
#include <vector>
using namespace std;
template<class I>
void print(I start,I end){
    for(auto it=start;it!=end;++it)
        cout<<*it<<" ";
    cout<<endl;
}
template<class I>
void bubble(I begin, I end){
  bool sw = true;
  while(sw){
    sw = false;
    for(auto i=begin;next(i)!=end;++i){
      if(*i > *next(i)){
        std::swap(*i,*next(i));
        sw = true;
      }
    }
  }
}

int main() {
  list<double> v={4,5,6,7,1,2,3};
  bubble(v.begin(),v.end());
  print(v.begin(),v.end());
  cout<<endl;
}
