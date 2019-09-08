#include <iostream>
#include <string>

using namespace std;

struct customer{

	string name, address, city, state, zip, date, telephone;
	int balance;
};
void Display(customer *user, int s){
	
	string sInput = "";
	while(true){
		for(int i = 0; i < s; i++){
			cout << "Customer's Name: "                << user[i].name << endl;
			cout << "Customer's Address: "             << user[i].address << endl;
			cout << "Customer's City: "                << user[i].city << endl;
			cout << "Customer's State: "               << user[i].state << endl;
			cout << "Customer's Zip Number: "          << user[i].zip << endl;
			cout << "Customer's Telephone Number: "    << user[i].telephone << endl;
			cout << "Customer's Account Balance: " 	   << user[i].balance << endl;
			cout << "Customer's Most Recent Payment: " << user[i].date << endl;		
		
			//cout << "---------------------------------------------------------\n";
		}
		cout << "Press enter to continue... " << endl;	
		getline(cin, sInput);
		if(sInput.size() == 0) break;
	}
}
int main(){
	//customer user[20];	//an array of 20 structure objects
						//for USER accounts [0 <-> n-1] 
	
	customer *user = new customer[20];
	int action = 0, size = 0, display = 0, i = 0;	
	string sInput = "";
	while(action != 4){
		cout << "------ Menu ------\n 1: Enter new account information\n 2: Change account information\n 3: Display all account information\n 4: Exit the program\n";
		cout << " Enter choice: ";
		cin  >> action;
		system("cls");
		switch(action){
			case 1:
				cout << "Enter Name: ";
				while(user[i].name.empty()){	//while(user[i].name.empty() is NOT EMPTY, break loop, else if it IS EMPTY, continue loop
					getline(cin, user[i].name);
				}
				//DO NOT USE fflush(stdin) undefined bahavior 
				cout << "Enter Address: ";
				while(user[i].address.empty()){
					getline(cin, user[i].address);
				}
				cout << "Enter city: ";
				while( user[i].city.empty()){
					getline(cin, user[i].city);
				}
				
				cout << "Enter State: ";
				while(user[i].state.empty()){
					getline(cin, user[i].state);
				}
				cout << "Enter Zip: ";
				while(user[i].zip.empty()){
					getline(cin, user[i].zip);
				}
				cout << "Enter Telephone: ";
				while(user[i].telephone.empty()){
					getline(cin, user[i].telephone);
				}
				cout << "Enter Account Balance: ";
				cin  >> user[i].balance;
				
				cout << "Enter Date of Last Payment: ";
				while(user[i].date.empty()){
					getline(cin, user[i].date);
				}
				i++;
				system("cls");
				break;
				
			case 2:
				int n;			//where n is for account numbers 
				cout << "Enter Number of Customer Account That You Would Like To Change(1 - 20):  ";
				cin  >> n;
				cout << "Enter Name: ";
				cin  >> user[n -1].name;
				fflush(stdin);
				cout << "Enter Address: ";
				cin  >> user[n - 1].address;
				fflush(stdin);
				cout << "Enter City: ";
				cin  >> user[n - 1].city;
				fflush(stdin);
				cout << "Enter State: ";
				cin  >> user[n - 1].state;
				fflush(stdin);
				cout << "Enter Telephone: ";
				cin  >> user[n -1].telephone;
				fflush(stdin);
				cout << "Enter Account Balance: ";
				cin  >> user[n - 1].balance;
				cout << "Enter Date of Last Payment: ";
				cin  >> user[n - 1].date;
				fflush(stdin);
				
				system("cls");
				break;
			case 3:
				Display(user, i);
				break;
			case 4:
				break;
		}
	}
	//while(action !=  4);
	delete[] user;
	return 0;
			
				
}
