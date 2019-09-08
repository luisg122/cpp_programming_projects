#include <iostream>
#include <string>
using namespace std;
struct Bnode{
  string val;
  //Bnode * pLeft=nullptr;
  //Bnode * pRight=nullptr;
  Bnode *pLeft ;
  Bnode *pRight; 
  
  Bnode(string v):val(v),pLeft(nullptr),pRight(nullptr){}			//in class initializer
};
class Btree{
  private:
    Bnode *root=nullptr;
    int nSize=0;
    void print_at_here(Bnode  * p);
    Bnode * insert_at_here(string v, Bnode *p);
    int size_of_subtree(Bnode *p);
    bool find_at_here(string v,Bnode *p);
  public:
	Btree():root(nullptr),nSize(0){}		//using a default constructor, the compiler provides one for you
	//Btree(){}
    void insert(string v){root =  insert_at_here(v,root);}
    void print(){print_at_here(root);}
    int size(){return  nSize;}
    int size2(){return size_of_subtree(root);}
    bool find(string v){return find_at_here(v,root);}
};
Bnode *Btree::insert_at_here(string v, Bnode *p){
  if(p){
    if(v<=p->val) p->pLeft=insert_at_here(v,p->pLeft);
    else p->pRight=insert_at_here(v,p->pRight);
    return p;
  }
  else {
    nSize++;				//counts the number of nodes in tree
    return new Bnode(v);
  }
}
bool Btree::find_at_here(string v,Bnode *p){
  if(p) return find_at_here(v,p->pLeft) || (v==p->val)  find_at_here(v,p->pRight);
  else  return false;
}
int Btree::size_of_subtree(Bnode *p){
  if(p) return size_of_subtree(p->pLeft)+ 1 + size_of_subtree(p->pRight);
  else return 0;
}
void Btree::print_at_here(Bnode *p){
  if(p){
    print_at_here(p->pLeft);
    cout<<p->val<<" ";
    print_at_here(p->pRight);  
  }
}
int main()
{
    Btree my_tree;
    string sPrompt = "Enter a name (ENTER when done): ";
    string sInput = "";
    while(true){
        cout << sPrompt;
        getline(cin, sInput);// get a full line.
        if (sInput.size() == 0) break;
        my_tree.insert(sInput);
    }
    cout << "Here are the names, in order." << endl;
    my_tree.print();
    cout << endl << "size="  << my_tree.size();
    cout << endl << "size2=" << my_tree.size2();
    
    string some_word = "";
	cout << "\n\nFind a word:";
	getline(cin, some_word);
    
	if(my_tree.find(some_word) == true){
		cout << "\nThe word IS one of the strings, therefore true: "<< my_tree.find(some_word)
		<< endl;
	}
	else cout << "The word you're looking for is NOT one of the strings therefore false: " 
	<< my_tree.find(some_word) << endl;;
	
	
	
	
	return 0;
}
