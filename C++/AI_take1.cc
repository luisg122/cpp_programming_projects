#include <iostream>
#include <cstring>
 
using namespace std;
 
int main()
{
char str[50];//user input
here:cin>>str;
if(strcasecmp ("hello",str)==0){//if both are same{
cout<<"Hello, what's your name"<<endl;
goto here;
}
else if(! strcasecmp ("hi",str)){
cout<<"hey there what's your name"<<endl;
goto here;
}
else if(! strcasecmp ("How are you?",str)){
cout<<"A machine is good as long as you keep it prevented from virus :-) "<<endl;
goto here;
}
else if(!strcasecmp("I am good.",str)){
cout<<"glad to hear that"<<endl;
goto here;
}
else{
cout<<"I couldn't understand what you said, sorry I am under development"<<endl;
goto here;
}
//the program will keep running as long as input is given
return 0;
}
