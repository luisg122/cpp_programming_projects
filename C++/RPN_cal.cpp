#include <iostream>
#include <vector>
#include <string>
#include <stack>
#include <algorithm>
#include <functional>
#include <cmath>
#define PI  3.14159265
#define e   2.718281828
using namespace std;
double   RPN(vector <string> tokens);
void   Shunting_Yard(vector<string> tokens);

vector<string> split(const string &str,function<bool(char)> delimiter=[](char c)->bool{return c==' '; } ,bool noempty=true){
    vector<string> result;
    auto prev = str.begin(); 
    auto next = str.begin();
    auto end  = str.end();
    do{
        next = find_if(prev, end, delimiter);
        if(!noempty || next != prev){
            result.push_back(string(prev,next)); // [prev,next)   
        }
        prev = next + 1;	// Move
    }
	while(next != end);
    return result;
}
//=====================================================================================
vector<string> Shuntingyard(vector<string> tokens){
    vector <string> output;//instead of queue, we use vector.
    stack  <string> yard;// stack for operations.
    for(auto &t: tokens){
        if(t == "+"){
          	while(!yard.empty()){
            	output.push_back(yard.top());
            	yard.pop();
          	}
          	yard.push(t);
        }
        else if(t == "*"){
        	if(yard.top() == "*"){
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
    	yard.pop();
	}
    return output;
}
//=====================================================================================
int main(){
	int choice = 0;
	string input_str;
	vector<string> tokens;
	
	cout << "!. RPN Calculator\n";
	cout << "2. Shunting Yard Calculator\n";
	cout << "3. Exit Program\n";
	cout << "Enter Your Choice of Calculator: ";
	do{
		cin >> choice;
	}
	while(choice < 0 || choice > 3);
	
	switch(choice){
		case 1: 		
				cout   << "Enter RPN string below:\n";
				cin.ignore(1000, '\n');		//clearing out the buffer
				while(true){
					getline(cin, input_str);
					if(input_str.size() == 0 ) break;
					else tokens.push_back(input_str);
				}
				cout << RPN(tokens);		
				break;
		case 2: cout   << "Enter Infix Expression below:\n";
				cin.ignore(1000, '\n');
				while(true){
					getline(cin, input_str);
					if(input_str.size() == 0) break;
					else tokens.push_back(input_str);
				}
				Shunting_Yard(tokens); 
				break;
		
		case 3: break;
	}
	
	
		
	return 0;
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
				if(t == "PI")	num_stack.push(PI);
				if(t == "e" )   num_stack.push(e);	
			}
			else num_stack.push(stod(t));  	
		}
//=======================================================================================
   	}
	return  num_stack.top();
}
void Shunting_Yard(vector<string> tokens){

	//vector<string> tokens = {"2","+","3","*","5","*","3","+","4" };
    //auto tokens = split(input_str);
	auto output = Shuntingyard(tokens);
    cout << "\nPostfix Expression: ";
	for(auto c: output) cout << c << " ";
	
	return;
}
