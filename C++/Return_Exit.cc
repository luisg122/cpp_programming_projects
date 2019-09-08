//  && (AND) both values must be true  to be true,  otherwise false
//  || (OR)  both values must be false to be false, otherwise true


#include<iostream>
#include<string>

using namespace std;

struct leave{
	
	
	leave(){
		
		cout << "You have created an object!\n";
		
	}
	
	~leave(){
		
		cout << "You have destroyed an object\n";
	}
	
};

int main(){
	
	leave l;
	string choice = "";
	
	do{
		cout << "exit or return? : ";
		cin  >> choice;
		
		
	}
	//while(choice.compare("exit") && choice.compare("return"));
	while(choice != "exit" && choice != "return");	// if user-input is NOT "enter and return"
	
	if(choice == "return"){
		cout << "You've entered " << choice << endl;	// return keyword destroys an object before exiting program
		return (0);  //exits main program, and returns value to system os 
	}
	else{
		cout << "You've entered " << choice << endl;	// exit  keyword does not destory an object, it exits main program before thast
		exit(0);	//exits main program and returns value to system os
	}
	
}
