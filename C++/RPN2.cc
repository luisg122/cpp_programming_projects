#include <iostream>
#include <vector>
#include <string>
#include <stack>
#include <cmath>
#include <functional>
#include <algorithm>
#define  PI 3.14159265
#define  e  2.718281828
using namespace std;
vector<string> split(const string &str,function<bool(char)> delimiter=[](char c)->bool{return c== ' ';} ,bool noempty = true){
    vector<string> result;
    auto prev = str.begin();
    auto next = str.begin();
    auto end  = str.end();
    do{
        next = find_if(prev,end,delimiter);
        if(!noempty || next!=prev){
            result.push_back(string(prev,next));
        }
        prev = next + 1;
    }while(next!=end);
    return result;
}
vector<string> Shuntingyard(vector<string> tokens){
    vector<string> output;
    stack<string> yard;
    for(auto &t: tokens){
        if(t=="+"||t=="-"){
         	if(yard.empty()||yard.top()=="(") yard.push(t);
        	else{
        	  	while(true){
           			output.push_back(yard.top());
            		yard.pop();
            		if(yard.empty()||yard.top()=="(") break;
          		}
            	yard.push(t);
			}
        }

        else if(t=="*" || t=="/"){
        	if(yard.empty()||yard.top()=="(") yard.push(t);
        	else{
        	  	while(yard.top()=="*"||yard.top()=="/"||yard.top()=="^"){
           			output.push_back(yard.top());
            		yard.pop();
            		if(yard.empty()||yard.top()=="(") break;
          		}
            	yard.push(t);
			}
        }
        else if(t=="^"||t=="("||t=="sin"||t=="cos"||t=="tan"||t=="log10"||t=="ln"){
        	yard.push(t);
		}
		else if(t==")"){
			while(true){
				if(yard.top()=="("){
					yard.pop();
					if(yard.top()=="sin"||yard.top()=="cos"||yard.top()=="tan"||yard.top()=="log10"||yard.top()=="ln"){
						output.push_back(yard.top());
						yard.pop();
					}
					break;
				}
				output.push_back(yard.top());
				yard.pop();
			}
		}

        else{
          output.push_back(t);
        }
    }
    while(!yard.empty()){
        output.push_back(yard.top());
        yard.pop();
	}
    return output;
}
double RPN(vector<string> tokens){
   	stack <double> num_stack;
   	for(auto t: tokens){
		if(t == "+"|| t == "-" || t == "*" || t == "/" || t == "^"){
			double b = num_stack.top();	num_stack.pop();
			double a = num_stack.top();	num_stack.pop();

			if(t == "+")	   num_stack.push(double(a + b));
			if(t == "-")	   num_stack.push(double(a - b));
			if(t == "*")	   num_stack.push(double(a * b));
			if(t == "/")	   num_stack.push(double(a / b));
			if(t == "^")	   num_stack.push(double(pow(a, b)));
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
				if(t == "PI")	num_stack.push(PI);
				if(t == "e" )   num_stack.push(e);
			}
			else num_stack.push(stod(t));  	//stod == string to double converter
		}
//=======================================================================================
   	}
	return  num_stack.top();
}
string change_form(const string a){
	string t;
	/*for(int j = 0; j < a.size();j++){
		char a1 = a[j] + a[j++];
		int chi = (int)a1;
		if(chi < 0){
			t.push_back(a[j]);
			t.push_back(a[j++]);
		}
	}*/

	for(int i = 0;i< a.size(); i++){
		/*char a1 = a[i] + a[i++];
		int chi = (int)a1;		//typecasting conversion
		if(chi < 0){
			t.push_back(' ');
			t.push_back(a[i]);
			t.push_back(a[i++]);
			t.push_back(' ');
		}*/
		if(a[i]=='+'||a[i] == '*' ||a[i]=='/'||a[i]=='^'||a[i]=='('||a[i]==')'){
			t.push_back(' ');
			t.push_back(a[i]);
			t.push_back(' ');
		}
		else if(a[i] == '-'){
			if(a[i - 1] == '('){
				t.push_back('0');		// n - 8, still considered to be -8, only treated as a binary op.
			}
			t.push_back(' ');
			t.push_back(a[i]);
			t.push_back(' ');
		}
		else{
			t.push_back(a[i]);			//takes care of trig functions as well as operands
		}
	}
	return t;
}
int main(){
	cout << "Welcome, Please Input An Expression Below:\n\n";
	while(true){
		string draft,input;
		cout << ">>> ";
		getline(cin,draft);
		if(draft.size() == 0) break;
		input = change_form(draft);	                        //applies spaces between string
    	vector<string> tokens = split(input);               //takes care of splitting tokens from previously changed string, a function written from scratch, similar to strtok function in c
    	auto output = Shuntingyard(tokens);                 //writes it in queue notation, (takes infix notation and writes postfix notation) for RPN to process
    	cout << "ANSWER: " << RPN(output) << endl << endl;  //takes care of order of operations of posfix notation
	}
    return 0;
}
