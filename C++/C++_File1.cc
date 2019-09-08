#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;
double avg(vector <double> v){
    double a = 0;
    for(auto x: v) a+=x;
    return a/v.size();
}
int main(){
    string filename = "users.txt";		//ifstream == cin == extraction operator(>>) == input stream
    //your code
    vector<double> data;
    ifstream myfile{filename};			//reading from created File 
    if(myfile){
        double x;
        while(myfile>>x){
            data.push_back(x);
        }
    }
    cout << "( " ;
	for(auto x = data.begin(); x != data.end(); x++){	//x is an iterator 
  	    if(next(x) != data.end()) cout << *x << " + "; 
	    else cout << *x;
    }
    /*for(auto x: data){ 			//is x an iterator?
		if(next(x) != data.end()) cout << x << " + ";
		else cout << x;
	}*/
    cout << ")/ " << data.size() << " = "<< avg(data) << endl;
  
    return 0;
}
