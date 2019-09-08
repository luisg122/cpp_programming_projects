#include<iostream>
#include<cmath>
using namespace std;
typedef unsigned int uint;
//typedef unsigned char uchar;
typedef unsigned long long ull;
class Prime{
  private:
    uint max_size;
    char * sieve; 				// if sieve[i] = 1, i is prime. If sieve[i] = 0, i is not prime.
    void init();				//setup the sieve.
    bool ptest(uint n);			//Check whether n is prime or not without the sieve.
  public:
    Prime(uint n):sieve{new char[n+1]()},max_size{n}{init();}// 0,1,....,new
    bool is_prime(uint n)		// Return true if n is prime using sieve table.
    {
      return sieve[n];
    }
    uint count(uint start,uint end);// # of primes p with star<=p<=end.
    ~Prime(){
      delete[] sieve;
    }
};
//code


bool Prime::ptest(uint n){
  if(n <= 1) return false;
  int sq = sqrt(n);
  for(uint i = 2;i <= sq;++i){
    if(n % i== 0) return false;
  }
  return true;
}


void Prime::init(){
  for(uint i=2;i<=max_size;++i){
    if(ptest(i)) sieve[i]=1;
  }
}


uint Prime::count(uint start,uint end){
  // start<=end<=max_size
  uint c=0;
  for(uint i=start;i<=end;++i){
    if(sieve[i]==1) ++c;
  }
  return c;
}


int main(){
  Prime P(1000000);//10^6
  cout<<P.is_prime(13)<<endl;
  cout<<P.count(1,1000000)<< " Prime Numbers exist between 1 - 1 million" << endl;


  return 0;
}

