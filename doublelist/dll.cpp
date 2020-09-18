///////////////////////////////////////////////////////////////////////////////
//
//
///////////////////////////////////////////////////////////////////////////////
#include "dll.hpp"
#include <iostream>
using namespace std;

///////////////////////////////////////////////////////////////////////////////
Node::Node(int val)
{
    data = val;
    prev = nullptr;
    next = nullptr;
}

///////////////////////////////////////////////////////////////////////////////
Node::~Node()
{
    if(data == 0)
    {
        if(prev == nullptr)
        {
            cout << "Deleting dummy head...";
        }
        else
        {
            cout << "Deleting dummy tail...";
        }
    }
    else
    {
        cout << "Deleting node->val = " << data;
    }
    cout << endl;   
}

///////////////////////////////////////////////////////////////////////////////
DList::DList()
{
    dummyHead = new Node(0);
    dummyTail = new Node(0);
    dummyHead->next = dummyTail;
    dummyTail->prev = dummyHead;
}

///////////////////////////////////////////////////////////////////////////////
DList::~DList()
{
    cout << "Deleting List" << endl;
    Node* curr = dummyHead->next;
    while(curr != dummyTail)
    {
        Node* next = curr->next;
        delete curr;
        curr = next;
    }
    delete dummyHead;
    delete dummyTail;
}

///////////////////////////////////////////////////////////////////////////////
void DList::pushFront(int val)
{
    Node* n = new Node(val);
    n->next = dummyHead->next;
    n->prev = dummyHead;
    dummyHead->next->prev = n;
    dummyHead->next = n;
}

///////////////////////////////////////////////////////////////////////////////
void DList::pushBack(int val)
{
    Node* n = new Node(val);
    n->next = dummyTail;
    n->prev = dummyTail->prev;
    dummyTail->prev->next = n;
    dummyTail->prev = n;
}

///////////////////////////////////////////////////////////////////////////////
void DList::popFront()
{
    Node* npop = nullptr;
    if(!isEmpty())
    {
        npop = dummyHead->next;
        dummyHead->next = npop->next;
        npop->next->prev = dummyHead;
        delete npop;
    }
    else
    {
        cout << "Error! Attempt to pop from empty list..." << endl;
    }    
}

///////////////////////////////////////////////////////////////////////////////
void DList::popBack()
{
    Node* npop = nullptr;
    if(!isEmpty())
    {
        npop = dummyTail->prev;
        dummyTail->prev = npop->prev;
        npop->prev->next = dummyTail;
        delete npop;
    }
    else
    {
        cout << "Error! Attempt to pop from empty list..." << endl;
    }
    
}

///////////////////////////////////////////////////////////////////////////////
void DList::printList()
{
    Node* curr = dummyHead->next;
    while(curr != dummyTail)
    {
        cout << curr->data << " ";
        curr = curr->next;
    }
    cout << endl;
}

///////////////////////////////////////////////////////////////////////////////
void DList::reversePrintList()
{
    Node* curr = dummyTail->prev;
    while(curr != dummyHead)
    {
        cout << curr->data << " ";
        curr = curr->prev;
    }
    cout << endl;
}

///////////////////////////////////////////////////////////////////////////////
Node* DList::getNode(int pos)
{
    Node* curr = dummyHead->next;
    int i = 0;
    while(curr != nullptr)
    {
        if(i == pos)
        {
            return curr;
        }
        curr = curr->next;
        i++;
    }
    cout << "Error! Node does not exist at position..." << endl;
    return nullptr;
}

///////////////////////////////////////////////////////////////////////////////
void DList::insertAt(int pos, int val)
{
    Node* n = new Node(val);
    Node* temp = getNode(pos);
    if(temp == nullptr)
    {
        cout << "Error!! Position does not exist in list..." << endl;
        return;
    }
    n->next = temp;
    n->prev = temp->prev;
    temp->prev->next = n;
    temp->prev = n;
}

///////////////////////////////////////////////////////////////////////////////
void DList::deleteAt(int pos)
{
    Node* n = getNode(pos);
    n->prev->next = n->next;
    n->next->prev = n->prev;
    delete n;
}
///////////////////////////////////////////////////////////////////////////////
bool DList::isEmpty()
{
    if(dummyHead->next == dummyTail)
    {
        return true;
    }
    return false;
}

