#include <iostream>
#include <string>
#include <iomanip>
using namespace std;
struct Customer{
    string name,address,city,state,zip,telephone,date;
    double balance;  
};
void setup(Customer &c){ 
   cin.ignore(1000, '\n'); 
   cout << "Customer name: ";
   getline(cin, c.name);
   while (c.name.empty()){
      cout << "You must enter a name.\n";
      getline(cin, c.name);
   }
   cin.ignore(1000, '\n'); 
   cout << "Customer address: ";
   getline(cin, c.address);
   while (c.address.empty()){
      cout << "You must enter an address.\n";
      getline(cin, c.address);
   }
   cin.ignore(1000, '\n'); 
   cout << "Customer City: ";
   getline(cin, c.city);
   while (c.city.empty()){
      cout << "You must enter a city.\n";
      getline(cin, c.city);
   }
   cin.ignore(1000, '\n'); 
   cout << "Customer state: ";
   getline(cin, c.state);
   while (c.state.empty()){
      cout << "You must enter a state.\n";
      getline(cin, c.state);
   }
   cin.ignore(1000, '\n'); 
   cout << "Customer zip: ";
   getline(cin, c.zip);
   while (c.zip.empty()){
      cout << "You must enter a zip.\n";
      getline(cin, c.zip);
   }
   cin.ignore(1000, '\n'); 
   cout << "Customer telephone: ";
   getline(cin, c.telephone);
   while (c.telephone.empty()){
      cout << "You must enter a telephone.\n";
      getline(cin, c.telephone);
   }
   cin.ignore(1000, '\n'); 
   cout << "Customer balance: ";
   cin >> c.balance;
   
   cin.ignore(1000, '\n'); 
   cout << "Customer date of last payment: ";
   getline(cin, c.date);
   while (c.date.empty()){
      cout << "You must enter a date.\n";
      getline(cin, c.date);
   }
   
}
void print(Customer c){
    //cout << fixed << showpoint << setprecision(2);
	//your code
	cout << "Customer's Name: "                 << c.name << endl;
	cout << "Customer's Address: "              << c.address << endl;
	cout << "Customer's City: "                 << c.city << endl;
	cout << "Customer's State: "                << c.state << endl;
	cout << "Customer's Zip Number: "           << c.zip << endl;
	cout << "Customer's Telephone Number: "     << c.telephone << endl;
	cout << "Customer's Account Balance: " 	    << c.balance << endl;
	cout << "Customer's Date of Last Payment: " << c.date << endl;	

}
int main(){
    int choice=0;
    int num_of_customers=0;
    int id=0;
    Customer customer_db[20];
    do{
        cout << "1. Enter new account information" << endl;
        cout << "2. Change account information" << endl;
        cout << "3. Display all account information" << endl;
        cout << "4. Exit the program"<<endl<<endl;
        cout << "Enter your choice: ";
        do{
            cin >> choice;    
        }while(choice<0 || choice>4);
        switch(choice){
            case 1:
                cout<<endl;
                setup(customer_db[num_of_customers]);
                cout << "You have entered information for customer number " << num_of_customers << endl;
                num_of_customers++;
                break;
            //break;
            case 2:
                cout << "Customer number: ";
                cin >> id;
                if(id <=num_of_customers && id>=0){
                    print(customer_db[id]);
                    cout<<endl;
                    cout<<endl;
                    setup(customer_db[id]);
                }
                break;
            case 3:
                for(int i=0;i<num_of_customers;++i){
                    print(customer_db[i]);
                    cout<<endl;
                    cout<<"Press enter to continue...\n";
                    cin.get();
                }   
                break;
            default: break;
        }
    }while(choice!=4);
    return 0;
}
