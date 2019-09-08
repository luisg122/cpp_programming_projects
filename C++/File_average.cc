#include <iostream>
#include <fstream>
#include <string>
#include <vector>
using namespace std;
double avg(vector <double> v){
  double sum = 0;
  for(auto x: v) sum += x;
  return sum / v.size();
}
int main(){
  string filename = "users.txt";
  //your code
  vector<double> data;
  ifstream myfile{filename};
  if(myfile){
    double x;
    while(myfile>>x){
      data.push_back(x);
    }
  }
  cout << avg(data) << endl;
  
  ofstream myfile2{"avg.txt"};		//W rite  onto file avg.txt
  if(myfile2){
    myfile2 << avg(data);
  }
  return 0;
}
