#include<iostream>
#include<algorithm>
#include<utility>
using namespace std;
typedef unsigned int uint;
typedef long long int ll;

struct Node{
	
	Node *next;
	ll value;
	
	Node(ll v):value(v), next(nullptr){}
	Node(ll v, Node *p):value(v), next(p){}
};

class MyList{
	private:
		Node *head;
	public:
		MyList();
		~MyList();
		Node *begin(){return head;}
		void push_back (ll i);
		void push_front(ll i);
		void pop_back ();
		void pop_front();
		void insert_after(Node *p, ll i);
		uint size();
		bool empty();
		void print();
};
MyList::MyList():head(nullptr){}
MyList::~MyList(){	//save and move
	Node *p = head;
	while(p != nullptr){
		Node *q = p;
		p = p->next;
		delete q;
	}
}
void MyList::push_back(ll i){
	if(head == nullptr) head = new Node(i);
	else{
		Node *tail = head;
		while(tail->next != nullptr) tail = tail->next;
		
		tail->next = new Node(i);
	}
}
void MyList::pop_back(){
	if(head != nullptr){
		if(head->next != nullptr){
			
			Node *tail = head;
			while(tail->next->next != nullptr)tail = tail->next;
			delete tail-> next;
			tail-> next = nullptr; 
		}
		else{ //head -> nullptr
			delete head;
			head = nullptr;
		}
	}
	
}
void MyList::push_front(ll i){
	if(head != nullptr) head = new Node(i, head);
	else head = new Node(i);
		
}
void MyList::pop_front(){
	if(head != nullptr){
		Node *temp = head->next;
		delete head;
		head = temp;
	}	
}

void MyList::insert_after(Node *p, ll i){
	if(p != nullptr) p->next = new Node(i, p->next);
	
}	
uint MyList::size(){
	uint count;
	Node *p = head;
	while(p != nullptr){
		p = p->next;
		++count;
	}
	return count;
}
bool MyList::empty(){
	return !head;
}
void MyList::print(){
	Node *p = head;
	while(p != nullptr){
		cout << p->value << " -> ";
		p = p->next;
	}
	cout << "nullptr\n";
}

int main(){
    MyList l;
    l.push_back(3);
    for(ll i=3;i>0;--i) l.push_back(i);
    l.print(); 
    l.push_front(0);  
    l.print();     
    Node *p =l.begin()->next;
    l.insert_after(p,10);
    l.print();
    l.pop_back();
    l.print();
    l.pop_front();
    l.print();
    cout<<l.size()<<endl;
    if(l.empty()) cout<<"Empty!"<<endl;
    else  cout<<"Not Empty!"<<endl;
    while(!l.empty()){
        l.pop_back();
        l.print();
    }
    //empty but try to delete.
    l.pop_back();
    l.pop_front();
    for(ll i=5;i>1;--i) l.push_front(i);
    l.print();
    while(!l.empty()){
        l.pop_front();
        l.print();
    }

	return 0;
}
