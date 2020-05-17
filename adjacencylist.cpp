#include "adjacencylist.h"
#include <iostream>

using namespace std;

struct ListPtr
{
    int key;
    ListPtr* nextNode;
};


AdjList::AdjList()
{
    head = NULL;
    current = head;
    smallest = 1000;
}


AdjList::~AdjList()
{
    ListPtr* temp;
    ListPtr* currentPtr;

    currentPtr = head;

    while(currentPtr != NULL)
    {
        temp = currentPtr;
        currentPtr = currentPtr->nextNode;
        delete temp;
    }
}


void AdjList::SortedInsert(int item)
{
    ListPtr* newListPtr = new ListPtr;
    ListPtr* temp;
    ListPtr* prev = NULL;
    ListPtr* curr = head;

    newListPtr->key = item;
    newListPtr->nextNode = NULL;

    if(item < smallest)
    {
	if(head != NULL)
	{
	    temp = head;
	    head = newListPtr;
	    head->nextNode = temp;
	}
	else
	{
	    head = newListPtr;
	}

	smallest = item;
    }
    else
    {
	while(curr != NULL && curr->key < item)
        {
	    prev = curr;
	    curr = curr->nextNode;
	}

	if(curr != NULL)
	{
	    prev->nextNode = newListPtr;
	    prev->nextNode->nextNode = curr;
	}
	else
	{
	    prev->nextNode = newListPtr;
	    curr = newListPtr;
	}
    }
}


int AdjList::GetNextItem()
{
    int value;

    value = current->key;
    current = current->nextNode;

    return value;
}


void AdjList::Reset()
{
    current = head;
}


bool AdjList::HasNext() const
{
    return (current != NULL);
}


void AdjList::PrintList()
{
    ListPtr* printPtr;
    printPtr = head;

    if(printPtr != NULL)
    {
        std::cout << printPtr->key << "  ";

        while(printPtr->nextNode != NULL)
        {
	    printPtr = printPtr->nextNode;
	    std::cout << printPtr->key << "  ";
        }
    }

    cout << endl;
}
