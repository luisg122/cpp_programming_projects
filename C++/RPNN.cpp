#include <stack>
#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <functional>
using namespace std;
vector<string> split(const string &str,function<bool(char)> delimiter=[](char c)->bool{return c==' '; } ,bool noempty=true){
    vector<string> result;
    auto prev=str.begin(); 
    auto next=str.begin();
    auto end=str.end();
    do{
        next=find_if(prev,end,delimiter);
        if(!noempty || next!=prev){
            result.push_back(string(prev,next)); // [prev,next)   
        }
        prev=next+1;// Move
    }
	while(next != end);
    return result;
}
int main()
{
  stack<double>  num_stack;
  string input_str;
  cout << "Enter RPN string: ";
  getline(cin,input_str);
  auto tokens = split(input_str); 
  
  //num_stack.push_back(tokens);
  //if(tokens == ('+'||'-'||'*'||'/')) input_str.push_back(tokens)
  //if(input_str == '+ ' || '-'){
  //input_str = stod(tokens);
  for(auto t: tokens){					//stack is a really simple structure
	  if(t == "+" || t == "-"){
	  	//for(auto i = tokens.begin(); i != tokens.end(); i = next(i) ){
  		//num_stack.push(tokens);
  		//num_stack.push(t);		
  		double b = num_stack.top();
		num_stack.pop();
		double a = num_stack.top();		
	 	double c = 0.0;
		if(t == "+"){
	 		c = a + b; 
	 		num_stack.push(c);
		} 
		else{ 
			c = a - b; 
	  		num_stack.push(c);
		}
	  }
	  else{
	  	double c = stod(t);
	  	num_stack.push(c);
	  }
  	
  }

  cout << num_stack.top();
  return 0;
}
