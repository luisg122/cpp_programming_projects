#include<iostream>
#include<algorithm>
#include<utility>
using namespace std;
typedef unsigned int uint;
typedef long long ll;
struct Node{
    ll value;
    Node * next;
    Node(ll v):value{v},next{nullptr}{}
    Node(ll v, Node* p):value{v},next{p}{}
};
class MyList{ //singly linked list
    private:
        Node * head;
    public:
        MyList();
        ~MyList();
        Node * begin(){return head;} //return address of the first element!
        void push_back(ll i);//adds an element to the end 
        void pop_back(); //removes the last element 
        void push_front(ll i);// inserts an element to the beginning 
        void pop_front();// removes the first element
        void insert_after(Node *p, ll i);//insert i before *p.
        uint size();//Return the size of linked list.
        bool empty();//checks whether the container is empty.
        void print();//print the list.
};
MyList::MyList():head{nullptr}{}
MyList::~MyList(){
    Node * p=head;
    while(p){
        Node * q=p;
        p=p->next;
        delete q;
    }
}
void MyList::push_back(ll d){
    if(!head) head = new Node(d);
    else{
        Node * p=head;
        while(p -> next != NULL) p=p->next;
        // p->nullptr
        // p->  new Node(d)->nullptr
        p->next = new Node(d);
    }
}
void MyList::pop_back(){
     if(head){
        if(head->next){
            Node * p = head;
            while(p->next->next) p=p->next;
            // p->(p->next)->nullptr
            delete p->next;
            //p->nullptr
            p->next=nullptr;
        }
        else{// head->nullptr
            delete head;
            head=nullptr;
        }   
     }
     //else nothing to delete! 
}
void MyList::push_front(ll d){
    if(head) head=new Node(d,head);
    else head=new Node(d);
    // since head=nullptr, you can combine as
    // head=new Node(d,head);
}
void MyList::pop_front(){
    if(head){ //head->q
        Node * q=head->next;
        delete head;
        head=q;
    }
    //else nothing to delete!
}
void MyList::insert_after(Node *p, ll i){
    //p->(p->next) => p->  new Node(i)->(p->next)
    if(p) p->next = new Node(i,p->next);
}
uint MyList::size(){
    uint i=0;
    Node * p=head;
    while(p){
        p=p->next;
        ++i;
    }
    return i;
}
bool  MyList::empty(){
    return !head;
}
void  MyList::print(){
    Node * p=head;
    while(p){
        cout<<(p->value)<<" -> ";
        p=p->next;
    }
    cout<<"nullptr"<<endl;
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
}
