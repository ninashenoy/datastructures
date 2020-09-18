#include "dll.hpp"
#include "gtest/gtest.h"
#include <iostream>

using namespace std;
/////////////////////////////////////////////////////////////////////////////////
TEST(NodeTest, createNode)
{
    Node* n = new Node(1);
    EXPECT_EQ(n->data, 1);
    EXPECT_EQ(n->next, nullptr);
    EXPECT_EQ(n->prev, nullptr);
    delete n;
}

TEST(ListTest, pushNode)
{
    DList* l = new DList();
    l->pushFront(1);
    EXPECT_EQ(l->dummyHead->next->data, 1);
    EXPECT_EQ(l->dummyHead->next->next, l->dummyTail);
    delete l;
}

TEST(ListTest, pushTwoNodes)
{
    DList* l = new DList();
    l->pushFront(1);
    l->pushBack(2);
    EXPECT_EQ(l->dummyHead->next->data, 1);
    EXPECT_EQ(l->dummyTail->prev->data, 2);
    EXPECT_EQ(l->dummyHead->next->next, l->dummyTail->prev);
    delete l;
}

TEST(ListTest, popFrontTest)
{
    DList* l = new DList();
    l->pushFront(1);
    l->pushFront(2);
    l->popFront();
    EXPECT_EQ(l->dummyHead->next->data, 1);
    delete l;
}

TEST(ListTest, printTest)
{
    DList* l = new DList();
    for( int i = 1; i < 6; i++)
    {
        l->pushBack(i);
    }
    l->printList();
    l->popBack();
    l->printList();
    l->popFront();
    l->printList();
    delete l;
}

TEST(ListTest, reversePrintTest)
{
    DList* l = new DList();
    for(int i = 1; i < 6; i++)
    {
        l->pushBack(i);
    }
    l->reversePrintList();
    delete l;
}

TEST(ListTest, getNodeAtPos)
{
    DList* l = new DList();
    l->pushBack(1);
    l->pushBack(2);
    Node* n = l->getNode(1);
    EXPECT_EQ(n->data, 2);
    delete l;
}

TEST(ListTest, insertAtTest)
{
    DList* l = new DList();
    for(int i = 1; i < 6; i++)
    {
        l->pushBack(i);
    }
    l->printList();
    l->insertAt(6, 20);
    l->printList();
    delete l;
}

TEST(ListTest, deleteAtTest)
{
    DList* l = new DList();
    for(int i = 1; i < 6; i++)
    {
        l->pushBack(i);
    }
    l->printList();
    l->deleteAt(1);
    l->printList();
    delete l;
}


/////////////////////////////////////////////////////////////////////////////////
int main(int argc, char **argv)
{
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
