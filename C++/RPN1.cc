// We assumes tokens are well defined.
#include <iostream>
#include <vector>
#include <string>
#include <stack>
#include <cmath>
#include <functional>
#include <algorithm>
using namespace std;
vector<string> split(const string& str,function<bool(char)> delimiter=[](char c)->bool{return c==' '; } ,bool noempty=true){
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
    }while(next!=end);
    return result;
}
double RPN(vector<string> tokens){
   	stack <double> num_stack;
   	//auto tokens = split(input_str);
   	for(auto t: tokens){					//stack is a really simple structure
		if(t == "+"|| t == "-" || t == "*" || t == "/" || t == "^"){
			double b = num_stack.top();	num_stack.pop();
			double a = num_stack.top();	num_stack.pop();		
				
			if(t == "+")	num_stack.push(double(a + b));
			if(t == "-")	num_stack.push(double(a - b));
			if(t == "*")	num_stack.push(double(a * b));
			if(t == "/")	num_stack.push(double(a / b));
			if(t == "^")	num_stack.push(double(pow(a, b)));
		}	

//=======================================================================================
		else if(t == "sin" || t == "cos" || t == "tan" || t == "log10" || t == "ln"){
			double c = num_stack.top(); num_stack.pop();
		
			if(t ==   "sin")   num_stack.push(sin(c));
   			if(t ==   "cos")   num_stack.push(cos(c));
   			if(t ==   "tan")   num_stack.push(tan(c));
   			if(t == "log10")   num_stack.push(log10(c));
       		if(t ==    "ln")   num_stack.push(log(c));
		}	

//=======================================================================================
		else{ 
			if(t == "PI" || t == "e"){
				if(t == "PI")	num_stack.push(3.14);
				if(t == "e" )   num_stack.push(2.718);	
			}
			else num_stack.push(stod(t));  	
		}
//=======================================================================================
   	}
	return  num_stack.top();
}
int main(){
	cout<<"please input(space between each turn)"<<endl;
	string input;
	getline(cin,input);
    vector<string> tokens=split(input);
    //vector<string> tokens={"2","+","3"};
    //auto output = Shuntingyard(tokens);
    cout<<RPN(tokens);
}
