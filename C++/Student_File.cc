#include <algorithm>
#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include <sstream>
using namespace std; 
struct Student {
    string name;
    int id,test1,test2,test3,final;
    Student(){}
    Student(int nid, string nname,int ntest1,int ntest2,int ntest3,int nfinal)
    :id{nid},name{nname},test1{ntest1},test2{ntest2},test3{ntest3},final{nfinal}{}
    double avg() const;
};
// test1:18%,test2:23%,test3:27%,final:32%
double Student::avg() const{	//you do not want to change the object, try to use 'const' keyword as much as possible
   //code
   double a = test1*(.18) + test2*(.23) + test3*(.27) + final*(.32);
   return a;
   
}
//123,James Harden,90,96,95,88
//id=123,name=James Harden,test1=90,test2=96,test3=95,final=88
istream &operator>>(istream &is, Student &st){
		string sid, name,s1,s2,s3,sf;
		int id, g1,g2,g3,f;
		getline(is, sid,   ',');
		getline(is, name,  ',');
		getline(is, s1,    ',');
		getline(is, s2,    ',');
		getline(is, s3,    ',');
		getline(is, sf);	
		
		stringstream(sid) >> id;
		stringstream(s1 ) >> g1;
		stringstream(s2 ) >> g2;
		stringstream(s3 ) >> g3;
		stringstream(sf ) >>  f; 
		
		st = Student(id, name, g1, g2, g3 , f);
		return is;		
}
// id=123,name=James Harden,test1=90,test2=96,test3=95,final=88
// [123] James Harden, t1=90, t2=96, t3=95, final=88, avg=92.09 
ostream &operator<< (ostream &os, const Student &st){
	os << "ID: "       << st.id 
	   << ", Name: "   << st.name 
	   << ", test1 = " << st.test1
	   << ", test2 = " << st.test2 
	   << ", test3 = " << st.test3
	   << ", final = " << st.final
	   << ", avg = "   << st.avg();
	return os;
}
// id=123,name=James Harden,test1=90,test2=96,test3=95,final=88
// James Harden,90,96,95,88 
ofstream &operator<<(ofstream &ofs, const Student &st){
	
	ofs << st.id    << ", "
	    << st.name  << ", "
	    << st.test1 << ", "
	    << st.test2 << ", "
	    << st.test3 << ", "
	    << st.final << ", "
	    << st.avg() << endl;
	
	
	
	return ofs;
	
}
int main()
{
    auto greater=[](Student x,Student y){return x.avg() > y.avg();};	//lambda function/ anonymous function
    vector<Student> v;
    
	ifstream ifile{"student.txt"};				 //obtaining data from file    -- EXTRACTION
    if(ifile){									 //ifile == extraction of data from file
    											 //reads
        for(Student st; ifile >> st; v.push_back(st)){}
    }
    
	cout << "INPUT FROM FILE: " << endl;
	for (const Student &e : v) cout << e << endl;
    
	ofstream ofile {"report.txt"};	   			//obtaining data from console -- INSERTION
    
	if(ofile){									//ofile == insertion of data from console
												//writes
      for(const Student &e: v) ofile << e;	    //writing onto file
    }
    cout << endl << "SORTED BY AVERAGE IN DECREASING - ORDER: " << endl;
    std::sort(v.begin(), v.end(), greater);		//Sort in a decreasing order with avg.
	
	for(const Student &e: v) cout << e << endl;	//writing onto console

	return 0;
}

//we work with data gathered from files
//web developers work with data gathered from databases
