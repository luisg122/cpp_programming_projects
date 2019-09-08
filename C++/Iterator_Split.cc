//Functor(Function object)
#include <iostream>
#include <algorithm>// consider find_if.
#include <vector>
#include <string>
using namespace std;
class is_space{
public:
    bool operator()(char c) const{
        return (c ==' ');
    }
};
template<typename UPred = is_space>
vector<string> split(const string& str, UPred delimiter=is_space(),bool noempty=true){
  vector<string> tokens;
  auto prev=str.begin(),next=str.begin();
  while(next=find_if(prev,str.end(),delimiter),next!=str.end()){
    if(!noempty || next>prev) tokens.push_back(string(prev,next));
    prev=next+1;
  }
  if(!noempty || prev!=str.end())  tokens.push_back(string(prev,str.end()));
  return tokens;
}
int main(){
  string s="20    14    +   3   -";
  auto tokens = split(s);
  for(auto t:tokens) cout<<t<<endl;
}
