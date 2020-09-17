#include "list.hpp"
#include "gtest/gtest.h"
#include <iostream>

using namespace std;
/////////////////////////////////////////////////////////////////////////////////

TEST(NodeTest, createNode)
{
    Node* n = new Node(5);
    EXPECT_EQ(n->data, 5);
    delete n;
}

TEST(ListTest, createList)
{
    List* l = new List();
    Node* n = l->getHead();
    EXPECT_EQ(n, nullptr);
    n = l->getTail();
    EXPECT_EQ(n, nullptr);
    delete l;
}

TEST(ListTest, insertToEmptyList)
{
    List* l = new List();
    l->insertNode(1);
    EXPECT_EQ(l->getHead()->data, l->getTail()->data);
    delete l;
}

TEST(ListTest, insertTwoNodes)
{
    List* l = new List();
    l->insertNode(1);
    l->insertNode(2);
    EXPECT_EQ(l->getHead()->data, 1);
    EXPECT_EQ(l->getTail()->data, 2);
    delete l;
}

TEST(DisplayTest, displayOneElement)
{
    List* l = new List();
    l->insertNode(1);
    EXPECT_EQ(l->getHead()->data, l->getTail()->data);
    l->displayList();
    delete l;
}

TEST(DisplayTest, displayElements)
{
    List* l = new List();
    l->insertNode(1);
    l->insertNode(2);
    l->insertNode(3);
    EXPECT_EQ(l->getHead()->data, 1);
    EXPECT_EQ(l->getTail()->data, 3);
    l->displayList();
    delete l;
}

TEST(DeleteTest, deleteFromEmpty)
{
    List* l = new List();
    l->deleteNode();
    delete l;
}


TEST(DeleteTest, deleteElement)
{
    List* l = new List();
    l->insertNode(1);
    l->deleteNode();
    delete l;
}

TEST(DeleteTest, deleteElements)
{
    List* l = new List();
    l->insertNode(1);
    l->insertNode(2);
    l->deleteNode();
    delete l;
}

TEST(ListTest, insertAtPosition)
{
    List* l = new List();
    l->insertNode(1);
    l->insertNode(2);
    l->insertNode(3);
    cout << "before insertion:\n";
    l->displayList();
    l->insertNode(10, 0);
    cout << "after insertion:\n";
    l->displayList();
    delete l;
}

TEST(ListTest, getNodeAtPos)
{
    List* l = new List();
    l->insertNode(1);
    l->insertNode(2);
    l->insertNode(3);
    l->displayList();
    Node* n = l->getNode(1);
    EXPECT_EQ(n->data, 2);
    delete l;
}

TEST(ListTest, ComboTest)
{
    List* l = new List();
    l->insertNode(10);
    l->insertNode(15);
    l->insertNode(20);
    l->insertNode(25);
    l->insertNode(30);
    l->displayList();
    cout << "Insert value 23 at pos 3..." << endl;
    l->insertNode(23, 3);
    l->displayList();
    l->deleteNode();
    l->displayList();
    delete l;
}

/////////////////////////////////////////////////////////////////////////////////
int main(int argc, char **argv)
{
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
