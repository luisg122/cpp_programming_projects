#include <iostream>
#include <cstdlib> //preferable library in place of conio.h
#include <stdlib.h> // similar library to conio
#include <conio.h> //do not use this deprecated library, most of conio.h function work compatibly
using namespace std;
class student{
    private:
        string name;
        int id,test1,test2,test3,final;
    public:
        string get_name();
        int get_id();
        int get_test(int num);
        int get_final();
        void set(string name1,int ID,int t1,int t2,int t3,int f);
        double avg();
        char grade();
};
string student::get_name(){
    return name;
}
int student::get_id(){
    return id;
}
int student::get_test(int num){
    if(num==1) return test1;
    if(num==2) return test2;
    if(num==3) return test3;
    return 0;
}
int student::get_final(){
    return final;
}
void student::set(string name1,int ID, int t1,int t2,int t3,int f){
    //(*this).name=name;
    //this->name = name;				//the 'this' pointer has two syntax notations, to obtain address of object
	//this->id = id;					//points to the object for which the member function is called


	name = name1;
	id = ID;
	test1 = (t1>=0 ? t1 : 0); 		//why the condition notation
    test2 = (t2>=0 ? t2 : 0);
    test3 = (t3>=0 ? t3 : 0);
    final = (f >=0 ? f  : 0);
}
double student::avg(){
    double a=test1*0.15+test2*0.15+test3*0.25+final*0.45;
    return a;
}
char student::grade(){
    double av=avg();
    if(av>=90) return 'A';
    if(av>=80) return 'B';
    if(av>=70) return 'C';
    if(av>=60) return 'D';
    return 'F';
}
int main(){


	student x;
    string S_name;
    string str;
    int S_ID, t01,t02,t03, t_Final;

	while(true){


	cout << "First Name of Student: ";
    cin  >> S_name;
    cout << "Student ID Number: ";
    cin  >> S_ID;
    cout << "Test 1 Grade: ";
    cin  >> t01;
    cout << "Test 2 Grade: ";
    cin  >> t02;
    cout << "Test 3 Grade: ";
    cin  >> t03;
    cout << "Final Test Grade: " ;
    cin  >> t_Final;
    system("cls");



    x.set(S_name,S_ID,t01,t02,t03,t_Final);
    cout<<"Name : "<<x.get_name()<<endl;
    cout<<"ID : "<<x.get_id()<<endl;
    cout<<"Test 1 : "<<x.get_test(1)<<endl;
    cout<<"Test 2 : "<<x.get_test(2)<<endl;
    cout<<"Test 3 : "<<x.get_test(3)<<endl;
    cout<<"Final : "<<x.get_final()<<endl;
    cout<<"Average : "<<x.avg()<<endl;
    cout<<"Grade : "<<x.grade()<<endl;

    cout << "\nWould you like to continue grading? (Y or N)";
    cin >> str;
    system("cls");

    if(!(str[0] == 'Y' || str[0] == 'y'))
    break;

	}

	cout << "\n EXITING . . . \n";
	getchar();
    return 0;
}

