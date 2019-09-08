#include<iostream>
using namespace std;
int  main(){
	int n = 0, k = 0;
	cin >> n;
	int i = 1;
	
	
	
	while(i < n){
		 i = i+ 1;
		 k = n;
		while(k >= i){
			if(i = k) cout << i;
			k = k -1;
		}
	}
	
	return 0;
}
