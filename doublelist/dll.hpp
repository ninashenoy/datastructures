///////////////////////////////////////////////////////////////////////////////
//
//
///////////////////////////////////////////////////////////////////////////////
#ifndef __DLL_HPP__
#define __DLL_HPP__

struct Node
{
    int data;
    Node* prev;
    Node* next;
    Node(int val);
    ~Node();
};

///////////////////////////////////////////////////////////////////////////////
class DList
{
    private:
    public:
        Node* dummyHead;
        Node* dummyTail;

        DList();
        ~DList();
        void pushFront(int val);
        void popFront();
        void pushBack(int val);
        void popBack();
        void printList();
        void reversePrintList();
        void deleteAt(int pos);
        void insertAt(int pos, int val);
        Node* getNode(int pos);
        bool isEmpty();
};

#endif