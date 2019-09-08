#include <algorithm>
#include <iostream>
#include <stack>
#include <string>
#include <utility>
#include <vector>
#include <cmath>
#include <regex>

using namespace std;
//Jason Isaac
void print_output_and_stack(vector<string>& output, stack<string> yard){
  cout << "CURRENT OUTPUT: ";
  for(string s : output) cout << s << " ";
  cout << endl;
  vector<string> keep;
  cout << "CURRENT STACK: ";
  while(!yard.empty()){
    keep.insert(keep.begin(), yard.top());
    yard.pop();
  }
  for(string& s : keep) cout << s << " ";
  cout << endl << endl;
}
//Jason Isaac
vector<string> split(const string& s){
  vector<string> result;
  regex functions("(sin)|(cos)|(tan)|(log)|(ln)|(pi)|.");
  sregex_token_iterator iter(s.begin(), s.end(), functions);
  sregex_token_iterator end;
  for(; iter!=end ; ++iter) result.push_back(*iter);
  return result;
}
//Andy Lou
bool is_operator(const string &s) {
  return s == "+" || s == "-" || s == "*" || s == "/" || s == "^";
}
//Andy Lou
int prec(const string &s) {
  if (s == "+")
    return 1;
  if (s == "-")
    return 1;
  if (s == "*")
    return 2;
  if (s == "/")
    return 2;
  if (s == "^")
    return 3;
  return 0;
}
//Andrew Claros
bool is_pi(const string & token){
  if(token=="pi") return true;
  return false;
}
//Andrew Claros
bool is_func(const string &s){
  return s == "sin" || s == "cos" || s == "tan" || s == "log" || s == "ln";
}
//Andy Lou
bool is_less_precedence(const string &new_s, const string t) {
  if (current == "^") {
    return prec(new_s) < prec(current);
  } else {
    return prec(new_s) <= prec(current);
  }
}
//Edison Fu
vector<string> Shuntingyard(vector<string> tokens) {
  vector<string> output;
  stack<string> yard;

  for (auto &token : tokens) {
    if(token == "(" || is_func(token)) yard.push(token);
    else if (is_operator(token)) {
      if (yard.empty()) yard.push(token);
      else if (is_less_precedence(token, yard.top()) || is_func(yard.top())) {
        output.push_back(yard.top());
        yard.pop();
        yard.push(token);
      }
      else {
        yard.push(token);
      }
    }
    else if(token == ")"){
      while(yard.top() !=  "("){
        output.push_back(yard.top());
        yard.pop();
      }
      yard.pop();
    }
    else {
      output.push_back(token);
    }
    print_output_and_stack(output, yard);
  }
  while (!yard.empty()) {
    output.push_back(yard.top());
    yard.pop();
  }
  return output;
}
//Andrew Claros
double perform_op(string op, double a, double b){
  if(op == "+") return a + b;
  else if(op == "-") return b - a;
  else if(op == "*") return a * b;
  else if(op == "/") return b / a;
  else if(op == "^") return pow(b, a);
  else return 0;
}
//Andrew Claros
double perform_func(string func, double a){
  if(func == "sin") return sin(a);
  else if(func == "cos") return cos(a);
  else if(func == "tan") return tan(a);
  else if(func == "log") return log10(a);
  else if(func == "ln") return log(a);
  else return 0;
}
//Andrew Claros
double rpn_calc(vector<string> & tokens){
  stack<double> num_stack;
  for(string& token : tokens){
    if(is_operator(token)){
      double a = num_stack.top();
      num_stack.pop();
      double b = num_stack.top();
      num_stack.pop();
      double ans = perform_op(token, a, b);
      num_stack.push(ans);
    }
    else if(is_func(token)){
      double a = num_stack.top();
      num_stack.pop();
      double ans = perform_func(token, a);
      num_stack.push(ans);
    }
    else if(is_pi(token))num_stack.push(atan(1)*4);
    else {
      num_stack.push(stod(token));
    }
  }
  return num_stack.top();
}


int main() {
  string input;
  while(true){
    cout << "Enter infix: ";
    getline(cin, input);
    if(input.size() > 0) break;
  }

  vector<string> tokens = split(input);
  vector<string> output = Shuntingyard(tokens);
  cout << endl << "Postfix: ";
  for (auto c : output) cout << c << " ";

  cout << endl;
  cout << rpn_calc(output) << endl;
}
