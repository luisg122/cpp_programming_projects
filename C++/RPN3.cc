#include <iostream>
#include <cmath>
#include <vector>
#include <string>
#include <stack>
using namespace std;
double rpn_comp(vector<string> rpn){
  unsigned int p=0;
  bool div_zero=false, log_zero=false, ln_zero=false;
  for(auto & x:rpn){
    if(x=="pi") x="3.14159265";
    else if(x=="e") x="2.718281828";
  }
  while(rpn.size()>1){
    if(rpn[p]=="+"){
      p-=2;
      rpn[p]=std::to_string(std::stod(rpn[p])+std::stod(rpn[p+1]));
      rpn.erase(rpn.begin()+p+1,rpn.begin()+p+3);
    }
    else if(rpn[p]=="-"){
      p-=2;
      rpn[p]=std::to_string(std::stod(rpn[p])-std::stod(rpn[p+1]));
      rpn.erase(rpn.begin()+p+1,rpn.begin()+p+3);
    }
    else if(rpn[p]=="*"){
      p-=2;
      rpn[p]=std::to_string(std::stod(rpn[p])*std::stod(rpn[p+1]));
      rpn.erase(rpn.begin()+p+1,rpn.begin()+p+3);
    }
    else if(rpn[p]=="/"){
      p-=2;
      if(std::stod(rpn[p+1])==0) div_zero=true;
      rpn[p]=std::to_string(std::stod(rpn[p])/std::stod(rpn[p+1]));
      rpn.erase(rpn.begin()+p+1,rpn.begin()+p+3);
    }
    else if(rpn[p]=="^"){
      p-=2;
      rpn[p]=std::to_string(pow(std::stod(rpn[p]),std::stod(rpn[p+1])));
      rpn.erase(rpn.begin()+p+1,rpn.begin()+p+3);
    }
    else if(rpn[p]=="sin"){
      --p;
      rpn[p]=std::to_string(sin(std::stod(rpn[p])));
      rpn.erase(rpn.begin()+p+1);
    }
    else if(rpn[p]=="cos"){
      --p;
      rpn[p]=std::to_string(cos(std::stod(rpn[p])));
      rpn.erase(rpn.begin()+p+1);
    }
    else if(rpn[p]=="tan"){
      --p;
      rpn[p]=std::to_string(tan(std::stod(rpn[p])));
      rpn.erase(rpn.begin()+p+1);
    }
    else if(rpn[p]=="log"){
      --p;
      if(std::stod(rpn[p])==0) log_zero=true;
      rpn[p]=std::to_string(log10(std::stod(rpn[p])));
      rpn.erase(rpn.begin()+p+1);
    }
    else if(rpn[p]=="ln"){
      --p;
      if(std::stod(rpn[p])==0) ln_zero=true;
      rpn[p]=std::to_string(log(std::stod(rpn[p])));
      rpn.erase(rpn.begin()+p+1);
    }
    else ++p;
  }
  if(div_zero) cout<<"Error! Division by zero.. ";
  if(log_zero) cout<<"Error! Log(0).. ";
  if(ln_zero) cout<<"Error! ln(0).. ";
  return std::stod(rpn[0]);
}
vector<string> Shuntingyard(vector<string> tokens){
  vector<string> output;
  stack<string> yard;
  for(auto & token: tokens){
    if(token=="+"||token=="-"||token=="*"||token=="/"||token=="^"||token=="("||token==")"||token=="sin"||token=="cos"||token=="tan"||token=="log"||token=="ln"){
      if(yard.empty()||token=="("||token=="^"||token=="sin"||token=="cos"||token=="tan"||token=="log"||token=="ln") yard.push(token);
      else if(token==")"){
        while(!yard.empty()&&yard.top()!="("){
          output.push_back(yard.top());
          yard.pop();
        }
        yard.pop();
        if(!yard.empty()&&(yard.top()=="sin"||yard.top()=="cos"||yard.top()=="tan"||yard.top()=="log"||yard.top()=="ln")){
          output.push_back(yard.top());
          yard.pop();
        }
      }
      else if(token=="*"||token=="/"){
        if(yard.top()=="^"){
          while(yard.top()=="^"){
            output.push_back(yard.top());
            yard.pop();
          }
        }
        else if(((yard.top()=="*"&&token=="/")||yard.top()=="/")&&yard.top()!="("){
          output.push_back(yard.top());
          yard.pop();
        }
        yard.push(token);
      }
      else{
        while(!yard.empty()&&!((token=="+"&&yard.top()=="+")||yard.top()=="(")){
          output.push_back(yard.top());
          yard.pop();
        }
        yard.push(token);
      }
    }
    else output.push_back(token);
  }
  while(!yard.empty()){
    output.push_back(yard.top());
    yard.pop();
  }
  return output;
}
vector<string> Tokenize(string s){
  vector<string> tokens;
  unsigned int p=1;
  while(s.size()){
    if(s[0]=='+'||s[0]=='-'||s[0]=='*'||s[0]=='/'||s[0]=='^'||s[0]=='('||s[0]==')'||s[0]=='e'){
      tokens.push_back(s.substr(0,1));
      s.erase(0,1);
    }
    else if(s.substr(0,2)=="ln"||s.substr(0,2)=="pi"){
      tokens.push_back(s.substr(0,2));
      s.erase(0,2);
    }
    else if(s.substr(0,3)=="sin"||s.substr(0,3)=="cos"||s.substr(0,3)=="tan"||s.substr(0,3)=="log"){
      tokens.push_back(s.substr(0,3));
      s.erase(0,3);
    }
    else{
      while((s[p]=='1'||s[p]=='2'||s[p]=='3'||s[p]=='4'||s[p]=='5'||s[p]=='6'||s[p]=='7'||s[p]=='8'||s[p]=='9'||s[p]=='0'||s[p]=='.')&&s.size()>p)++p;
      tokens.push_back(s.substr(0,p));
      s.erase(0,p);
      p=1;
    }
  }
  return tokens;
}
//  Checks for any syntax error and adds "*" and ")" if needed.
string user_in(){
  string s;
  unsigned int p=0,op=0,cp=0;// p for scanning the string. op and cp for counting number of parenthesis.
  bool dec=false;// Records whether or not a number contains a decimal point.
  cout<<"Input : ";
  cin>>s;
  while(p<s.size()){
    //  Check for numbers.
    if(s[p]=='1'||s[p]=='2'||s[p]=='3'||s[p]=='4'||s[p]=='5'||s[p]=='6'||s[p]=='7'||s[p]=='8'||s[p]=='9'||s[p]=='0'){
      ++p;
      //  Adds "*" after numbers if needed. Ex: 3pi=3*pi, 2sin(pi)=2*sin(pi)
      if(s[p]=='e'||s[p]=='('||s.substr(p,2)=="ln"||s.substr(p,2)=="pi"||s.substr(p,3)=="sin"||s.substr(p,3)=="cos"||s.substr(p,3)=="tan"||s.substr(p,3)=="log") s.insert(p,"*");
    }
    //  Check for e.
    else if(s[p]=='e'){
      //  Adds "*" after e if needed. Ex: elog(10)=e*log(10)
      if(p+1<s.size()&&s[p+1]!='+'&&s[p+1]!='-'&&s[p+1]!='*'&&s[p+1]!='/'&&s[p+1]!='^'&&s[p+1]!=')') s.insert(p+1,"*");
      if(dec) dec=false;
      ++p;
    }
    //  Check for parenthesis. Error if followed by "*", "/", "^", or ")". Ex: (*5+2) = Error! ,  5+() = Error!
    else if((p+1<s.size()&&s[p]=='('&&s[p+1]!='*'&&s[p+1]!='/'&&s[p+1]!='^'&&s[p+1]!=')')||s[p]==')'){
      if(s[p]=='('){
        //  Inserts 0 after "(" if needed. Ex: (-2)/(+5)=(0-2)/(0+5)
        if(s[p+1]=='+'||s[p+1]=='-') s.insert(p+1,"0");
        ++op;
      }
      else{
        //  Adds "*" after ")" if needed. Ex: (1+2)(5-3)=(1+2)*(5-3)
        if(p+1<s.size()&&s[p+1]!='+'&&s[p+1]!='-'&&s[p+1]!='*'&&s[p+1]!='/'&&s[p+1]!='^'&&s[p+1]!=')') s.insert(p+1,"*");
        ++cp;
      }
      if(dec) dec=false;
      ++p;
    }
    //  Check for decimal point. Error if double decimal. Ex: 3.1415.92654 = Error!, 3.141592654 = Ok!
    else if(s[p]=='.'&&!dec){
      //  Inserts 0 before decimal point if needed. (Not necessary but looks better) Ex: (.5)=(0.5)
      if(p==0||(s[p-1]!='1'&&s[p-1]!='2'&&s[p-1]!='3'&&s[p-1]!='4'&&s[p-1]!='5'&&s[p-1]!='6'&&s[p-1]!='7'&&s[p-1]!='8'&&s[p-1]!='9'&&s[p-1]!='0')) s.insert(p++,"0");
      //  Inserts 0 after decimal point of needed. Ex: (5.)=(5.0)
      if(p+1>=s.size()||(s[p+1]!='1'&&s[p+1]!='2'&&s[p+1]!='3'&&s[p+1]!='4'&&s[p+1]!='5'&&s[p+1]!='6'&&s[p+1]!='7'&&s[p+1]!='8'&&s[p+1]!='9'&&s[p+1]!='0')) s.insert(p+1,"0");
      ++p;
      dec=true;
    }
    //  Check for operations. Error if not followed by a number. Ex: 5-2+ = Error!
    //  Error if there is nothing before "*", "/", or "^". Ex: ^5+2 = Error!
    //  Error if followed by another operation. Ex: 5++2 = Error!
    else if(((s[p]=='+'||s[p]=='-')||((s[p]=='*'||s[p]=='/'||s[p]=='^')&&p!=0))&&(p+1<s.size()&&s[p+1]!='+'&&s[p+1]!='-'&&s[p+1]!='*'&&s[p+1]!='/'&&s[p+1]!='^'&&s[p+1]!=')')){
      //  Inserts 0 at beginning if needed. Ex: -5+10=0-5+10
      if((s[p]=='+'||s[p]=='-')&&p==0) s.insert(p,"0");
      if(dec) dec=false;
      ++p;
    }
    //  Check for ln function.
    else if(s.substr(p,3)=="ln(") p+=2;
    //  Check for pi.
    else if(s.substr(p,2)=="pi"){
      //  Adds "*" after pi if needed. Ex: pi(1+2)=pi*(1+2)
      if(p+2<s.size()&&s[p+2]!='+'&&s[p+2]!='-'&&s[p+2]!='*'&&s[p+2]!='/'&&s[p+2]!='^'&&s[p+2]!=')') s.insert(p+2,"*");
      if(dec) dec=false;
      p+=2;
    }
    //  Check for sin, cos, tan and log functions.
    else if(s.substr(p,4)=="sin("||s.substr(p,4)=="cos("||s.substr(p,4)=="tan("||s.substr(p,4)=="log(") p+=3;
    //  Gives error and restarts loop if all checks failed.
    else{
      cout<<"Error!"<<endl<<"Input : ";
        cin>>s;
        dec=false;
        p=0,op=0,cp=0;
    }
    //  Check number of parenthesis and corrects if possible.
    if(p>=s.size()){
      //  Gives error and restarts loop if too many ")". Ex: 5+2)-3) = Error!
      if(op<cp){
        cout<<"Error!"<<endl<<"Input : ";
        cin>>s;
        dec=false;
        p=0,op=0,cp=0;
      }
      //  Adds ")" to the end if not enough. Ex: sin(pi=sin(pi)
      else while(op>cp){
        s.push_back(')');
        ++cp;
        ++p;
      }
    }
  }
  return s;
}
void test(string equation){
  bool sample=true;
  if(equation==""){
    equation=user_in();
    sample=false;
  }
  vector<string> tokens=Tokenize(equation);
  cout<<"Equation : ";
  for(auto & token:tokens) cout<<token;
  cout<<endl;
  cout<<"RPN Expression : ";
  vector<string> rpn=Shuntingyard(tokens);
  for(auto token:rpn) cout<<token<<" ";
  cout<<endl<<"Answer : "<<rpn_comp(rpn)<<endl<<endl;
}
int main() {
  cout<<"CS-203 Team Project - Stephen Kuang, Timmy Georgiou, Robert Costagliola, Eduardo Escamilla"<<endl<<endl;
  string sample="(15/(7-(1+1)))^2-(log(100)+ln(e)+1-(sin(pi)*tan(pi-2)*cos(2+3)))",user="";
  test(sample);// Answer : 5
  sample="(5+3*(0.5*4)^3)*log(5^3*8)+(ln(e)+cos(pi)^2*2)";
  test(sample);//
  
}
