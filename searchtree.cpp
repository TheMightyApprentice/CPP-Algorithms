#include "searchtree.h"
#include <iostream>
#include <string>

using namespace std;

struct TreePtr
{
    int key;
    TreePtr* leftChild;
    TreePtr* rightChild;
    TreePtr* Parent;
};


SearchTree::SearchTree()
{
    headTree = NULL;
    current = NULL;
    size = 0;
    array = new TreePtr*[25];
}


SearchTree::~SearchTree()
{
    PostorderDelete(headTree);
}


void SearchTree::Insert(int item, int itemP)
{
    TreePtr* currPtr = headTree;
    TreePtr* newTreePtr = new TreePtr;
    TreePtr* position = NULL;

    newTreePtr->key = item;
    newTreePtr->leftChild = NULL;
    newTreePtr->rightChild = NULL;
    newTreePtr->Parent = NULL;

    if(headTree == NULL)
    {
        headTree = newTreePtr;
    }
    else
    {
	position = Search(headTree, itemP);
	if(position != NULL)
        {
	    if(position->leftChild == NULL)
	    {
		position->leftChild = newTreePtr;
		newTreePtr->Parent = position;
	    }
	    else if(position->leftChild != NULL && position->rightChild == NULL)
	    {
		position->rightChild = newTreePtr;
                newTreePtr->Parent = position;
            }
        }
    }
}


TreePtr* SearchTree::GetHeadTree()
{
    return headTree;
}


TreePtr* SearchTree::Search(TreePtr* position, int item)
{
    int count = 0;

    PreorderTraverseToArr(headTree);

    while(array[count] != NULL && array[count]->key != item)
    {
	count++;
    }

    if(array[count] == NULL)
    {
	return NULL;
    }
    else
    {
        return array[count];
    }
}


void SearchTree::PreorderTraverseToArr(TreePtr* x)
{
    size = 0;

    if(x != NULL)
    {
        array[size] = x;
	size ++;
	PreorderTraverseToArr(x->leftChild);
        PreorderTraverseToArr(x->rightChild);
    }
}


void SearchTree::PreorderTraverse(TreePtr* x)
{
    if(x != NULL)
    {
	cout << x->key << "  ";
	PreorderTraverse(x->leftChild);
	PreorderTraverse(x->rightChild);
    }
}

void SearchTree::PostorderDelete(TreePtr* x)
{
    if(x != NULL)
    {
        PostorderDelete(x->leftChild);
	PostorderDelete(x->rightChild);
        delete(x);
    }
}

