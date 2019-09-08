#include<iostream>
using namespace std;


struct Bnode {
     int  val;
     Bnode*  pLeft;
     Bnode*  pRight;
     Bnode(int s){val = s; pLeft = pRight = nullptr;}
};
class Btree {

private:
     Bnode *root;
     Bnode *insert_at_sub(int  s, Bnode* p);
     void   print_sub (Bnode *p);
     void   delete_sub(Bnode *p); 
  	 int 	sum(Bnode *p);
	 int    nSize = 0;
	 bool 	find_at_sub(int s, Bnode *p);
public:
     Btree() {root = nullptr;}
     void insert(int s){root = insert_at_sub(s, root);}
     void print() {
	 	print_sub(root);
	 	int s = sum(root);
    	cout << "The sum of all integer values in Binary Tree is: "
             << s << endl;					
	 }
	 int size(){return nSize;}
	 bool find(int s){
	 	Bnode *p = root;
	 	while(p != nullptr){
	 		if(s == p->val) return true;
	 		else if(s <= p->val) p = p->pLeft;
	 		else p = p->pRight;
	 	}
	 	return false;	 	
	 }
	 int get_first_at_sub(Bnode *p);
	 int get_last_at_sub (Bnode *p);
};


Bnode *Btree::insert_at_sub(int  s, Bnode *p){
  
  if(p == nullptr){
 	  ++nSize;
	  return new Bnode(s);
  }
  else{
    if(s <= p->val) p->pLeft = insert_at_sub(s, p->pLeft);
    else p->pRight = insert_at_sub(s, p->pRight);
  }
  return p;
  
}
void Btree::print_sub(Bnode* p) {   //in - order print  
    if (p != nullptr) {
        print_sub(p->pLeft);
        cout << p->val<< endl;
        print_sub(p->pRight);
    }

}
int Btree::sum(Bnode *p){	//respective Root Value
	int left_sum = 0, right_sum = 0, mySum = 0;
	if(!p){
		return 0;
	}
	if(p != nullptr) {
		left_sum  = sum(p->pLeft );
		right_sum = sum(p->pRight);
		mySum =  p->val + left_sum + right_sum; 
	}
	return mySum;
}
void Btree::delete_sub(Bnode *p){
  if(p != nullptr){
      delete_sub(p->pLeft);
      delete_sub(p->pRight);
      delete p;
    }
  
}
bool Btree::find_at_sub(int s, Bnode *p){
	if(p == nullptr) return false;
	else if(s <  p->val) return find_at_sub(s, p->pLeft );
	else if(s == p->val) return true;
	else return find_at_sub(s,p->pRight);	
}
int Btree::get_first_at_sub(Bnode* p){
  if(p){
    if(p->pLeft==nullptr) return p->val;
    else return get_first_at_sub(p->pLeft);
  }
  //return "";
}
int Btree::get_last_at_sub(Bnode* p){
  if(p){
    if(p->pRight==nullptr) return p->val;
    else return get_last_at_sub(p->pRight);
  }
  //return "";
}


int main(){
    Btree my_tree;
    string sPrompt = "Enter a number (ENTER when done): ";
    int a = 0;
    cout << sPrompt;
    while (cin >> a){	//until input does not match data type, if different, loop simply breaks
        cout << sPrompt;
        my_tree.insert(a);
     }
     cout << "Here are the numbers, in order:" << endl;
     my_tree.print();
	 cout << endl << "The binary tree has " << my_tree.size()
 		  << " nodes.\n"; 
 	
	int num;
 	cin >> num;
 	if(my_tree.find(num)) cout << "Found";
 	else cout << "Not Found";
 	
  return 0;
}
