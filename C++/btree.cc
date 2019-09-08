#include <iostream>
#include <string>
using namespace std;
struct Bnode {
     string  val;
     Bnode *pLeft;
     Bnode *pRight;
     Bnode(string s):val(s),pLeft(nullptr),pRight(nullptr){}
};
class Btree {
public:
     //Btree() {root = nullptr; }
     Btree():root(nullptr){}
	 void insert(string s){root = insert_at_sub(s, root);}
     //~Btree(){delete_sub(root);}
     void print() {print_sub(root);}
     string get_first(){return get_first_at_sub(root);}
     string get_last(){return get_last_at_sub(root);}
     
	 bool find(string s){
       Bnode *p = root;
       while(p){
         if(s == p-> val) return true;
         else if(s < p->val ) p=p->pLeft;
         else p=p->pRight;
       }
       return false;
     }
private:
    void delete_sub(Bnode *p);
    Bnode *root = nullptr;
    Bnode *insert_at_sub(string s, Bnode *p);
    bool find_at_sub(string s, Bnode *p);
    void print_sub(Bnode *p);
    string get_first_at_sub(Bnode *p);
    string get_last_at_sub (Bnode *p);
     
};
void Btree::delete_sub(Bnode* p){
    if(p){
      delete_sub(p->pLeft);
      delete_sub(p->pRight);
      delete p;
    }
}
void Btree::print_sub(Bnode* p) {
    //if (p==nullptr) do nothing!
    if(p){
        print_sub(p->pLeft);
        cout << p->val << " ";
        print_sub(p->pRight);
    	cout << endl;
		cout << get_first_at_sub(p);
	
	}
}
Bnode *Btree::insert_at_sub(string s, Bnode *p) {
    if (!p) {				 //if p == 0			
	    return new Bnode(s); //termination!
    } else if (s <= p->val) {
        p->pLeft  = insert_at_sub(s, p->pLeft);
    } else if (s > p->val) {
        p->pRight = insert_at_sub(s, p->pRight);
    }
    return p;//it is neccessary for recursion.
}
string Btree::get_first_at_sub(Bnode* p){
  if(p){
    if(p->pLeft==nullptr) return p->val;
    else return get_first_at_sub(p->pLeft);
  }
  return "";
}
string Btree::get_last_at_sub(Bnode* p){
  if(p){
    if(p->pRight==nullptr) return p->val;
    else return get_last_at_sub(p->pRight);
  }
  return "";
}
bool find_at_sub(string s, Bnode*p){
  if(!p){
    return false;
  }
  else if( s<p->val) return find_at_sub(s,p->pLeft);
  else if( s==(p->val) ) return true;
  else return find_at_sub(s,p->pRight);
}
int main()
{
    Btree my_tree;
    string sPrompt = "Enter a name (ENTER when done): ";
    string sInput = "";
    while (true ) {
        cout << sPrompt;
        getline(cin, sInput);// get a full line.
        if (sInput.size() == 0) {// Stop if it is empry.
            break;
        }
        my_tree.insert(sInput);
     }
     cout << "Here are the names, in order." << endl;
     my_tree.print();
     cout<<my_tree.get_last()<<endl;
     
     string f="";
     cin>>f;
     if(my_tree.find(f)) cout<<"found!";
     else cout<<"not found!";
     //cout<<endl<<my_tree.get_size()<<endl;
     
}
