// We assumes tokens are well defined.
#include <iostream>
#include <vector>
#include <string>
#include <stack>
using namespace std;
vector<string> Shuntingyard(vector<string> tokens){
    vector<string> output;//instead of queue, we use vector.
    stack<string> yard;// stack for operations.
    for(auto & t: tokens){
        if(t=="+"){
          while(!yard.empty()){
            output.push_back(yard.top());
            yard.pop();
          }
          yard.push(t);
        }
        else if(t=="*"){
          if(yard.top()=="*"){
            output.push_back(yard.top());
            yard.pop();
          }
            yard.push(t);
        }
        else{
          output.push_back(t);
        }
    }
    while(!yard.empty()){
    output.push_back(yard.top());
    yard.pop();}
    return output;
}
int main(){
    vector<string> tokens={"2","+","3","*","5","*","3","+","4" };
    auto output=Shuntingyard(tokens);
    //cout << "Postfix "
    for(auto c:output) cout << c << " ";
}
