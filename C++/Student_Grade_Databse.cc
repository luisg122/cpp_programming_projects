#include <iostream>
#include <string>
#include <algorithm>
using namespace std;
class Student{
    public:
    string firstName;
    string lastName;
    float gpa;
    Student(){}
    Student(string last, string first, double grade):firstName(first), lastName(last), gpa(grade){}
};
void sort(Student *arr, int n);
int main()
{
    const int ARR_SIZE = 50;

    Student arr[ARR_SIZE];

    int count = 0;

    string last, first;
    double gpa;

    cin >> last;
    while (cin) { // Stop if input is not valid. Ex. "hello bye a" is not valid since "a" is not a number.
        cin >> first;
        cin >> gpa;
        arr[count++] = Student(last, first, gpa);

        cin >> last;
    }
    
    sort(arr, count);
    for(int i = 0; i < count; i++){
       cout << arr[i].lastName << " " << arr[i].firstName << " " << arr[i].gpa << endl;
       //cout << arr[i].lastName + arr[i].firstName + arr[i].gpa << endl;
	}
	return 0;
}

void sort(Student *arr, int n){
	for ( int i = 0; i < n; i++)		//for each case
    {
        for(int j = 1; j < n; j++)		//previous and next
		{
            if (arr[j - 1].lastName > arr[j].lastName) swap(arr[j - 1], arr[j]);
        }
    }
}
