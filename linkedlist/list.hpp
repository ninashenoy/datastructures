///////////////////////////////////////////////////////////////////////////
//
//
///////////////////////////////////////////////////////////////////////////
#include <iostream>
using namespace std;

///////////////////////////////////////////////////////////////////////////
struct Node
{
    int data;
    Node* next;
    Node(int val);
    ~Node();
};

////////////////////////////////////////////////////////////////////////////
class List
{
    private:
        Node* head;
        Node* tail;

    public:
        List(); //
        ~List();
        void insertNode(int val); //
        void insertNode(int val, int pos); //
        void deleteNode(); //
        void displayList(); //
        Node* getHead(); //
        Node* getTail(); //
        Node* getNode(int pos);
};

//////////////////////////////////////////////////////////////////////////////
Node::Node(int val)
{
    data = val;
}

///////////////////////////////////////////////////////////////////////////////
Node::~Node()
{
    cout << "Deleting Node " << data << endl;
}

///////////////////////////////////////////////////////////////////////////////
List::List()
{
    head = nullptr;
    tail = nullptr;
}

///////////////////////////////////////////////////////////////////////////////
List::~List()
{
    Node* curr = getHead();
    if(head == tail)
    {
        delete curr;
        return;
    }
    while(curr != nullptr)
    {
        Node* next = curr->next;
        delete curr;
        curr = next;
    }
    cout << "Deleting List..." << endl;
}

///////////////////////////////////////////////////////////////////////////////
Node* List::getHead()
{
    return head;
}

///////////////////////////////////////////////////////////////////////////////
Node* List::getTail()
{
    return tail;
}

///////////////////////////////////////////////////////////////////////////////
void List::insertNode(int val)
{
    Node* n = new Node(val);
    n->next = nullptr;

    if(head == nullptr)
    {
        head = n;
        tail = n;
    }
    else
    {
        tail->next = n;
        tail = n;
    }    
}

///////////////////////////////////////////////////////////////////////////////
void List::insertNode(int val, int pos)
{
    Node* prev = nullptr;
    Node* curr = getHead();
    Node* n = new Node(val);

    if(pos == 0) //insert at head
    {
        n->next = head;
        head = n;
    }
    else
    {
        for(int i = 0; i < pos; i++)
        {
            prev = curr;
            curr = curr->next;
        }
        prev->next = n;
        n->next = curr;   
    }   
}
///////////////////////////////////////////////////////////////////////////////
//fix to delete from list with only one node
void List::deleteNode()
{
    if( head != nullptr )
    {
        Node* curr = getHead();
        if(head == tail)
        {
            delete curr;
            head = nullptr;
            tail = nullptr;
        }
        else
        {
            Node* prev = nullptr;
            while(curr->next != nullptr)
            {
                prev = curr;
                curr = curr->next;
            }
            tail = prev;
            prev->next = nullptr;
            delete curr;  
            }      
    }
    else
    {
        cout << "ERROR! Attempt to delete from empty list!!" << endl;
    }    
}

///////////////////////////////////////////////////////////////////////////////
Node* List::getNode(int pos)
{
    Node* curr = nullptr;
    int i = 0;
    for(curr = getHead(); curr != nullptr; curr = curr->next)
    {
        if(i == pos)
        {
            return curr;
        }
        i++;
    }
    cout << "Invalid position" << endl;
    return nullptr;
}

///////////////////////////////////////////////////////////////////////////////
void List::displayList()
{
    Node* curr;
    for(curr = getHead(); curr != nullptr; curr = curr->next)
    {
        cout << curr->data << " ";
    }
    cout << endl;
}