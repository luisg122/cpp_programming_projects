#include <iostream>
#include <fstream>
#include <string>
#include <vector>
using namespace std;
double avg(vector<double>v){
  double avg = 0.0;
  int size = 0.0;
  for(auto x: v){     //range for-loop 
    avg += x;
    size++;
  }
  return avg/size;
  //return avg/v.size();
  
}

int main(){
  cout << "File name:";
  string name;
  cin >> name;
  ifstream myfile {name}; //Read
  vector<double> data;
  if(myfile){
      for(double x;myfile>>x;){
          data.push_back(x);
      }
  }
  else cerr<<"Can't open "<<name;
  cout << avg(data);
  //for(auto x: data) cout<<x<<" ";
}
//create a file 'data.txt

/*#include <iostream>
#include <fstream>
#include <string>
#include <vector>
using namespace std;
int main(){
  //input from user
  vector<string> users;
  for(string user="";;){
    getline(cin, user);// We need to use a getline to handle an enter.
    if (user.length() == 0) break;
    else users.push_back(user);
  }
  //write
  ofstream myfile {"user.txt"}; //Read
  if(myfile){
      for(string x: users)
          myfile<<x<< endl;
  }
  else cerr<<"Can't open "<<"user";
}*/
