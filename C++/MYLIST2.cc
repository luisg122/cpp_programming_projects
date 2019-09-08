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
		 //Node *tail; 	//points to the last node of list
	public:
		 MyList();
		~MyList();
		 Node *begin(){return head;}
 		 void push_back (ll i);
		 void pop_back  (ll i);
		 void push_front(ll i);
		 void pop_front (ll i);
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
	Node *new_node = new Node(i, nullptr);
	Node *tail = head;
	if(head == nullptr){
		head = new_node;
		return;
	}
	while(tail -> next != nullptr) //retains/maintains the nodes of list
		 {tail = tail -> next;}	   
	
	tail -> next = new_node;	   //once the last node of list is obtained, create new node
								   //"pushing back" a value/node
	return;
}
void MyList::pop_back (ll i){
	if(head != nullptr){
		if(head -> next != nullptr){
			Node *tail = head;
			while(tail -> next -> next != nullptr){tail = tail -> next;}
			delete tail -> next; 
			tail -> next = nullptr;
			
		}
		else{
			delete head;
			head = nullptr;
		}
	}
}
void MyList::push_front(ll i){
	Node *new_node = new Node(i, head);
	head = new_node;
	
	return;
}
void MyList::pop_front(ll i){
	if( head != nullptr ){
        Node *temp  = head;
        head = head -> next;
		delete temp;
	}
}
void MyList::insert_after(Node *p, ll i){
	Node *new_node = new Node(i, p -> next);
	p -> next = new_node;
}
uint MyList::size(){
	uint count = 0;
	Node *p = head;
	
	while(p != nullptr){
		count++;			//counting number of loops therefore counting number of nodes
		p = p -> next;
	}
	cout << "There are " << count << " nodes\n";
}
bool MyList::empty(){
	while( head != nullptr ) pop_front(head -> value);
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

	for(ll i = 3; i > 0; --i)	List.push_back(i);		//where 3 is the head
    List.print();
    //---------------------------------

	for(ll i = 5; i > 3; --i)   List.push_front(i);
    List.print();
	//---------------------------------

 	Node *p = List.begin() -> next;
    List.insert_after(p,10);
    List.print();
	
	/*List.pop_back(1);
	List.print();
	List.pop_back(2);
	List.print();
	List.pop_front(4);
	List.print();
	//---------------------------------
	List.size();
	List.empty();
	List.print();
	List.size();*/
	
	cout << "\n=======================================\n";


	return 0;
}
