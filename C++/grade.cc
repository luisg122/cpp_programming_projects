#include<iostream>
using namespace std;

class Person{
    private:
        string name;
        int ID;
        string phone;
    public:
        string getName(){return name;}
        int getID(){return ID;}
        Person(string n_name,int n_id,string n_phone):name{n_name},id{n_id},phone{n_phone}{}
};

class Student:public Person{
	private:
		double  gpa;
	public:
		Student(char grade){
			
			if(gpa <= 100 || gpa >= 90)
				return grade  = 'A';
			if(gpa <= 90 || gpa >= 80)
				return grade  = 'B';
			if(gpa <= 80 || gpa >= 70)
				return grade  = 'C';
			else return grade = 'F'; 
		}		
	
	
	friend ostream &operator<<(ostream &os, const Student &x){
		using Person::Person;
		return os;	
	}
	
};
