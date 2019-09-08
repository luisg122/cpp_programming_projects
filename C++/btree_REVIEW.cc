#include<iostream>
#include<string>
using namespace std;

struct Bnode{
	string val;
	Bnode *pLeft  = nullptr;
	Bnode *pRight = nullptr;
	Bnode(string s):val(s){}
};
class Btree{
	private:
		Bnode *root;
		Bnode *insert_at_sub(string s, Bnode *p);
		void  print_sub(Bnode *p);
	public:
		//Btree():root(nullptr){}
		//Btree(){root = nullptr;}
		
		Btree():root{nullptr}{}
		void insert(string s){root = insert_at_sub(s, root);cout << "The root of tree is: " <<
															root->val << endl;}
		void print(){print_sub(root);}
};
Bnode *Btree::insert_at_sub(string s, Bnode *p){
	if(p == nullptr) return new Bnode(s);		//create new node if one does not exist
	else if(s <=  p->val) p->pLeft  = insert_at_sub(s,p->pLeft );
	else if(s >   p->val) p->pRight = insert_at_sub(s,p->pRight);
	
	return p;
}
void   Btree::print_sub(Bnode *p){
	if(p != nullptr){
		print_sub(p->pLeft);
		cout << p->val << " ";
		print_sub(p->pRight);
	}
}
int main(){
	
	Btree my_tree;
	string sPrompt = "Enter a name (ENTER when done): ";
	string sInput = " ";
	while(true){
		cout << sPrompt;
		getline(cin, sInput);
		if(sInput.size() == 0){break;}
		my_tree.insert(sInput);
	}
	
	cout << "Here are the names, in order." << endl;
	my_tree.print();
	
	return 0;
}
