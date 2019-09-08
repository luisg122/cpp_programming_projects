
#include <iostream>
#include <string>
using namespace std;
struct Bnode{
  string val;
  Bnode *pLeft;
  Bnode *pRight;
  Bnode(string v):val(v),pLeft(nullptr),pRight(nullptr){}
};
class Btree{
  private:
    Bnode *root;
    Bnode *insert_at_here(string v, Bnode *p);
	void  print_at_here(Bnode * p);
  public:
    Btree():root(nullptr){}
    void insert(string v){ root=insert_at_here(v,root);}
    void print(){print_at_here(root);}
};
Bnode *Btree::insert_at_here(string v, Bnode *p){
  if(p){
    if(v <= p->val) 	p -> pLeft  = insert_at_here(v,p->pLeft );
    else if(v > p->val) p -> pRight = insert_at_here(v,p->pRight);
    return p;
  }
  else return new Bnode(v);
}
void Btree::print_at_here(Bnode *p){
  if(p){								//if p != 0
    print_at_here(p -> pLeft);
    cout << p -> val << " ";
	print_at_here(p -> pRight);
  }
}
int main()
{
    Btree my_tree;
    string sPrompt = "Enter a name (ENTER when done): ";
    string sInput = "";
    while(true){
        cout << sPrompt;
        getline(cin, sInput);			// get a full line.
        if (sInput.size() == 0) break;
        my_tree.insert(sInput);
    }
    cout << "Here are the names, in order." << endl;
    my_tree.print();
}
