
#include<algorithm>
#include<cmath>
#include<iostream>
#include<chrono>
#include<functional>
#include<vector>
using namespace std;
template<class Iter>
void bubblesort(Iter first, Iter last){
    while(first!=last){
        Iter jump=first;
        for(Iter j=first, i=j++;j!=last;i=j++){
            if(*j<*i) { // Basically, i < j=i+1
                jump=j;
                std::swap(*j,*i);
            }
        }
        last=jump;
    }
}
template<class Iter>
void mergesort(Iter first, Iter last){
    if (last - first > 1) {
        Iter middle = first + (last - first) / 2;
        mergesort(first, middle); // [first, middle)
        mergesort(middle, last);  // [middle, last)
        inplace_merge(first, middle, last);
    }
}
template<class Iter>
void quicksort(Iter first,Iter last) {//[first,last)
      int size=(last-first);
      if(size<=0) return;
      auto pivot =*(first+size/2);
      auto i=first;
      auto j=last-1;//last index.
      /* partition */
      while (i <= j) {
            while (*i < pivot)
                  ++i;
            while (*j > pivot)
                  --j;
            if (i <= j) {
                  auto tmp = *i;
                  *i= *j;
                  *j = tmp;
                  ++i;
                  --j;
            }
      }; 
      /* recursion */
      if (first < j)
            quicksort(first,j+1);
      if (i < last-1)
            quicksort(i, last);
}
int random(int a,int b){
    return rand() % b +  a;
}

int main(){
    srand( time(NULL) );
    int n=5000;
    vector<int> t(n);
    for(int i=0;i<n;++i) t[i]=random(1,n);
    vector<int> v1{t},v2{t},v3{t},v4{t};
  
    cout<<"the time of bubblesort is :";
    auto start1 = chrono::steady_clock::now();
    bubblesort(v1.begin(),v1.end());
    auto end1 = chrono::steady_clock::now();
    auto diff1=end1-start1;
    auto duration1= chrono::duration <double, milli> (diff1).count();
    cout<<duration1 << "ms" << endl;
 
    auto start2 = chrono::steady_clock::now();
    cout<<"the time of quicksort is :";
    quicksort(v2.begin(),v2.end());
    auto end2 = chrono::steady_clock::now();
    auto diff2=end2-start2;
    auto duration2= chrono::duration <double, milli> (diff2).count();
    cout<<duration2<< "ms" << endl;
  
    auto start3 = chrono::steady_clock::now();
    cout<<"the time of mergesort is :";
    mergesort(v3.begin(),v3.end());
    auto end3 = chrono::steady_clock::now();
    auto diff3=end3-start3;
    auto duration3= chrono::duration <double, milli> (diff3).count();
    cout<<duration3 << "ms" << endl;
    
    auto start4 = chrono::steady_clock::now();
    cout<<"the time of std::sort is :";
    std::sort(v4.begin(),v4.end());
    auto end4 = chrono::steady_clock::now();
    auto diff4=end4-start4;
    auto duration4= chrono::duration <double, milli> (diff4).count();
    cout<<duration4 << "ms" << endl;

}
