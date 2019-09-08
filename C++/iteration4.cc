t//iteration for alternating sum program
#include<iostream>
using namespace std;
int alt_sum(int n){
	int sum=0;
	for(int i=1; i<=n;++i){
		sum = sum + alt_sum(n-1)-alt_sum(n+1);
	}
	return sum;

}
int main(){
	int n=0;
	cout << "Type a positive integer:\n"; // "\n" notation means new line
	cin >> n;
	cout << alt_sum(n);




	return 0;
}





