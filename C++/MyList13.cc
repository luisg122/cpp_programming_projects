#include <iostream>
#include <string>
using namespace std;


class myList
{

public:

    struct node
    {
        int num;
        string word;
        node *link;
        node(): link(NULL) {}
        node( int Number, string Word, node* Link ): num(Number), word(Word), link(Link) {}
    };

    //*** functions ***
    void push_front(int number,string word );// add node to front of list
    void push_back(int number,string words);// add node to back of list
    void pop_front(void);// delete node at front of list
    void pop_back(void);// delete node at back of list
    void clear(void);// delete all nodes. Leave front = back = NULL
    void insert_asc(int number, string word);// use instead of push_front/back to build an ordered list

    void displaylist(void);// write entire list contents to cout

    // operators
    myList& operator=( const myList& r_list );// assignment
    myList& operator+= ( const myList& r_list );// append lists

    // ctor
    myList();// default ctor
    myList( const myList& r_list );// copy ctor
    // dtor
    ~myList();

private:
    node *front;// points to 1st node in the list
    node *back; // points to last node in the list
};

// destructor
myList::~myList()
{
    unsigned N = 0;// a frill
    while( front )// could call clear() here, but we want a node count
    {
        pop_front();
        ++N;// counting nodes
    }
    cout << "*** deleted myList with " << N << " nodes" << endl;
}

myList::myList(): front(NULL), back(NULL) // default ctor
{ cout << "default ctor here." << endl; }

// copy ctor
myList::myList( const myList& r_list )
{
    front = back = NULL;
    for( node* iter = r_list.front; iter != NULL; iter = iter->link )
        push_back( iter->num, iter->word );

        cout << "copy ctor here." << endl;
}

myList& myList::operator=( const myList& r_list )
{
    clear();// destroy existing nodes

    // create the new nodes
    for( node* iter = r_list.front; iter != NULL; iter = iter->link )
        push_back( iter->num, iter->word );

    cout << "operator = here" << endl;
    return *this;
}

myList& myList::operator+= ( const myList& r_list )
{
    // add nodes  to existing list
    for( node* iter = r_list.front; iter != NULL; iter = iter->link )
        push_back( iter->num, iter->word );

    cout << "operator += here" << endl;
    return *this;
}

void myList::push_front(int number,string word )
{
    front = new node(number, word, front);
    if( !back ) back = front;

    return;
}

void myList::push_back(int number,string word)
{
    if( back )
    {
        back->link = new node(number, word, NULL);
        back = back->link;
    }
    else
        front = back = new node(number, word, NULL);

    return;
}

void myList::pop_front(void)
{
    if( front )
    {
        node* temp = front;
        front = front->link;
        delete temp;
        if( !front ) back = NULL;
    }
}

void myList::pop_back(void)
{
    if( front )
    {
        if( front->link )// multi node myList
        {
            node* iter = front;
            while( iter->link->link )// looking for: link->link = NULL
                iter = iter->link;

            // iter points to node before back
            delete iter->link;
            iter->link = NULL;
            back = iter;
        }
        else// only 1 node in myList
        {
            delete front;
            front = back = NULL;
        }
    }
}

// delete all nodes from myList. Post cond: front = back = NULL
void myList::clear(void)
{
    while( front )
        pop_front();
}

//insert nodes in ascending order
void myList::insert_asc(int number,string word)
{
    if( front == NULL )
        push_front(number, word);// new front because myList is empty
    else if( number < front->num )
        push_front(number, word);// new front because it belongs there
    else// insert past front
    {
        node* iter = front;
        while( (iter->link != NULL) && (number > iter->link->num) )
            iter = iter->link;

        // iter now points to the node before the insertion point
        if( iter->link )// mid-myList
            iter->link = new node(number, word, iter->link);
        else// iter = back
            push_back(number, word);
    }
}

void myList::displaylist(void)
{
    node* iter = front;
    while( iter )
    {
        cout << iter->word << iter->num << endl;// customize here
        iter = iter->link;
    }
}
int main ()
{
    myList chapter_1;
    chapter_1.insert_asc( 6," Lay on the ground quite still  " );
    chapter_1.insert_asc( 4," Find fresh underpants to try on ");
    chapter_1.insert_asc( 1," ** CHAPTER 1 ** ");
    chapter_1.insert_asc( 8," Keep like that day after day  ");
    chapter_1.insert_asc( 2," If you're attacked by a Lion ");
    chapter_1.insert_asc( 7," Pretend you are very ill ");
    chapter_1.insert_asc( 9," Perhaps the lion will go away ");
    // display chapter 1
    chapter_1.displaylist(); cout << endl << endl;

    // a list to store all chapters
    myList wholeStory( chapter_1 );// start as a copy of chapter 1

    myList chapter_2;
    chapter_2.insert_asc( 3," that boy stood on the burning deck ");
    chapter_2.insert_asc( 5, " a wolly scarf around his neck ");
    chapter_2.insert_asc( 9," shoes on his feet ");
    chapter_2.insert_asc( 11, " he wished he was wearing trunks instead ");
    chapter_2.insert_asc( 7, " hat on his head ");
    chapter_2.insert_asc( 1, " ** CHAPTER 2 ** ");
    // display chapter 2
    chapter_2.displaylist(); cout << endl << endl;

    wholeStory += chapter_2;// add chapter 2 to the story

    // display entire story so far
    wholeStory.displaylist();cout << endl << endl;

    cout << endl;
   return 0;
}
