#include <iostream>
using namespace std;
void sort(int *a,int n){
  int t = 0;
  for(int i = n; i > 1; --i){
    for(int j = 0; j + 1 < n; j++){
      if(a[j + 1] < a[j]){  //Increasing order, BUBBLESORT
                            //if (next < previous) SWAP, must initialize case to 0, increment for other case (NEXT)
                            //if (previous > next) SWAP, must initialize case to 1, decrement for other case (PREVIOUS)
        t = a[j + 1];
        a[j + 1] = a[j];
        a[j] = t;
      }
    }
  }
}
int main() {
  int a[5]={1,3,4,3,2};
  sort(a, 5);
  for(auto &x:a) cout<<x<<" ";
}
