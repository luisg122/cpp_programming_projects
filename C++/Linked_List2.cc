#include<iostream>
#include<algorithm>
#include<utility>
using namespace std;
typedef long long int ll;
typedef unsigned int uint;

struct Node{
	Node *next;	//lists are sequential, therefore ONLY one pointer to a node is necessary
	ll value;

	Node(ll v):value(v), next(nullptr){}	//default constructor
	Node(ll v, Node *p):value(v),next(p){}	//initializer constructor
};

class MyList{

	private:
		 Node *head;	//aka ROOT NODE
	public:
		 MyList();
		~MyList();
		 Node *begin(){return head;}
 		 void push_back (ll i);
		 void pop_back  ();
		 void push_front(ll i);
		 void pop_front ();
		 void insert_after(Node *p, ll i);
		 uint size();
		 bool empty();
		 void print();
};

MyList::MyList():head(nullptr){}
MyList::~MyList(){
	Node *temp;
	while(head != nullptr) {
    	temp  = head;
        head  = head -> next;
        delete temp;
    }
}
void MyList::push_back(ll i){
	
    Node *tail = head;						//**pp = *p pointer to a pointer syntax
	if( head == nullptr){					//if node is empty
		head = new Node(i, nullptr);		//print new node and assign a value pointing to the next node 
		return;                             //break
	}
	while(  tail -> next != nullptr)		//once tail -> next does equal nullptr, loop breaks
	{tail = tail -> next;}
	
	tail -> next = new Node(i, nullptr);	//here is where i goes after creating and insert head
	return;
}
void MyList::pop_back (){
	Node *tail = head;
	while(tail -> next -> next != nullptr) tail = tail -> next;
	delete tail -> next; 
	tail -> next = nullptr;
}
void MyList::push_front(ll i){
	head = new Node(i, head);						//creates the new head, while pointing to the previous head of ucstom-made list
	return;
}
void MyList::pop_front(){
	if( head != nullptr ){
           Node *temp  = head;
           head = head -> next;
	   delete temp;
	   temp = nullptr;
	}
}
void MyList::insert_after(Node *p, ll i){		   
	p -> next = new Node(i, p -> next);		//after 5, create new node
}
uint MyList::size(){
	uint count = 0;
	Node *p = head;
	
	while(p != nullptr){
		count++;
		p = p -> next;
	}
	cout << "There are " << count << " nodes\n";
}
bool MyList::empty(){
	while( head != nullptr ) pop_front();
}
void MyList::print(){
	Node *n = head;
	
	while(n != nullptr){
		cout << n -> value << " -> ";
		n = n -> next;
	}
	if(n == nullptr) cout << "nullptr\n";
}

int main(){

	cout << "Project3 - Luis Gualpa\n";
	cout <<"=======================================\n";


	MyList List;

	for(ll i = 3; i >= 1; --i)	List.push_back(i);		//where 3 is the head
    List.print();
    //---------------------------------

	for(ll i = 5; i > 3; --i)   List.push_front(i);
    List.print();
	//--------------------------------
	Node *p = List.begin() -> next;						//points to 5 after 4 being the "head" of list
    List.insert_after(p,10);
    List.print();
	

	
	List.pop_back();
	List.print();
	List.pop_front();
	List.print();
	//---------------------------------
	List.size();
	List.empty();
	List.print();
	List.size();
	
	cout << "=======================================\n";


	return 0;
}
