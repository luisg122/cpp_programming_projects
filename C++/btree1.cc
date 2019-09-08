#include <iostream>
#include <string>
using namespace std;
struct Bnode {
     string  val;
     Bnode*  pLeft;
     Bnode*  pRight;
     Bnode(string s):val(s),pLeft(nullptr),pRight(nullptr){}
};
class Btree {
private:
     Bnode *root;
     void print_sub(Bnode *p);

public:
     Btree():root(nullptr){}
     void insert(string s);
     void print() {print_sub(root);}
};

void Btree::insert(string s){		//a relationship between PARENT node/CHILD node
  
  if(root == nullptr){
 	root  = new Bnode(s);
    return;
  }
  //pleft must less than root, or parent node, pright must be >= parent node, root node!!!
  Bnode *p = root;
  while(true){
    if(s < p -> val){
      if(p -> pLeft == nullptr){		//if no node, exists, simply CREATE A NEW ONE
        p  -> pLeft  = new Bnode(s);	
        return;							//doesn't return a value, but aborts a function of loop
      }
      else{
         p = p -> pLeft;				//if a node exists, POINT TO IT, it now becomes a parent node
      }
    }
    else{
      if(p -> pRight == nullptr){		
	    p -> pRight = new Bnode(s);	//NOT TAKEN, input value
        return;
      }
      else{
        p = p -> pRight;			//TAKEN, becomes the NEW PARENT NODE
      } 
    }
  }
}
void Btree::print_sub(Bnode* p) {
    //if (p==nullptr) do nothing!
    if (p) {
        print_sub(p->pLeft);
        cout << p->val<< endl;
        print_sub(p->pRight);
    }
}
int main(){
	
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

	return 0;
}
