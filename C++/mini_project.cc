#include <vector>
#include <iostream>
#include <string>
#include <algorithm>
using namespace std;
using vstring=vector<string>;
using vchar=vector<char>;

void student_register(vstring & studentnames,vchar & studentrecords){
    string newname="";
    char inn = '\0';
    while (inn!='N') {
        cout<<"Type the name of new student: ";
        cin >> newname;
        cout << "Will you continue(Y/N): ";
        cin >> inn;
        studentnames.push_back (newname);
        studentrecords.push_back ('0');
    }
    return;
}
void student_mark(const vstring & studentnames,vchar & studentrecords) {
    string choice="";
        for(int i=0; i<studentnames.size();i++) {
            cout << "Choose P,A,L,E for " << studentnames[i] << ":";
            cin>>studentrecords[i];
            
        }
    return; //to kill scope 
    
}
void student_reset(vstring & studentnames,vchar & studentrecords){
    studentnames.resize(0);
    studentrecords.resize(0);
    cout<<"Reset completed"<<endl;
    return;
}
int counter(const vchar & studentrecords,char s) {
    int mycount = std::count (studentrecords.begin(), studentrecords.end(), s);
    return mycount;
}


void student_report(const vchar & studentrecords) {
    if (studentrecords.size() == 0) {cout << "No student. Nothing to report"<<endl; return;}
    
    cout << "The number of absence= " << counter (studentrecords, 'A') << endl;
    cout << "the number of lateness= " << counter (studentrecords, 'L') << endl;
    cout << "The number of present= " << counter (studentrecords, 'P') << endl;
    cout << "the number of excused= " << counter (studentrecords, 'E') << endl;
    return;
}

int main() {
    int choice=0;
    vector<string> studentnames={"Tim","Bob","Jane"};
    vector<char> studentrecords={'\0','\0','\0'};
    while(choice!=5){
        cout<<"Attendance app."<<endl;
        cout<<"Choose one of menus."<<endl;
        cout<<"1: Register new students."<<endl;
        cout<<"2: Mark attendance records."<<endl;
        cout<<"3: Reset the roster."<<endl;
        cout<<"4: Report the summary."<<endl;
        cout<<"5: Exit."<<endl;
        cout<<"Your Choice(1,2,3,4,5):";
        cin>>choice;
        if(choice==1) student_register(studentnames,studentrecords);
            else if(choice==2) student_mark(studentnames,studentrecords);
            else if(choice==3) student_reset(studentnames,studentrecords);
            else if(choice==4) student_report(studentrecords);
        }

cout<<"Thank you."<<endl;
}
