#include <iostream>
#include <string>
#include "priorqueue.h"

using namespace std;


struct QueuePtr
{
    int key;
    int weight;
    QueuePtr* nextNode;
};


PriorQueue::PriorQueue()
{
    current = NULL;
    head = NULL;
}


PriorQueue::~PriorQueue()
{
    QueuePtr* temp;
    QueuePtr* currentPtr;

    currentPtr = head;

    while(currentPtr != NULL)
    {
        temp = currentPtr;
        currentPtr = currentPtr->nextNode;
        delete temp;
    }
}


void PriorQueue::Push(int item, int w)
{
    QueuePtr* currentPtr = head;
    QueuePtr* temp;
    QueuePtr* prev;
    QueuePtr* newQueuePtr = new QueuePtr;

    newQueuePtr->key = item;
    newQueuePtr->weight = w;

    if(head == NULL)
    {
        head = newQueuePtr;
    }
    else
    {
        if(head->weight > w)
        {
            temp = head;
	    head = newQueuePtr;
            head->nextNode = temp;
        }
        else
        {
	    while(currentPtr->nextNode != NULL && currentPtr->weight < w)
            {
	        currentPtr = currentPtr->nextNode;
	    }

	    newQueuePtr->nextNode = currentPtr->nextNode;
	    currentPtr->nextNode = newQueuePtr;
        }
    }
}


int PriorQueue::ExtractMin()
{
    QueuePtr* temp = head;
    int min;

    min = temp->key;
    head = head->nextNode;
    delete temp;

    return min;
}


void PriorQueue::ChangeWeight(int k, int w)
{
    QueuePtr* curr = head;
    QueuePtr* temp;
    QueuePtr* prev = NULL;

    while(curr->nextNode != NULL && curr->key != k)
    {
	prev = curr;
        curr = curr->nextNode;
    }

    if(curr->key == k)
    {
	curr->weight = w;

        temp = curr;

        if(temp == head)
        {
        }
        else
        {
            prev->nextNode = temp->nextNode;
            Push(temp->key, temp->weight);
        }
    }
}


bool PriorQueue::IsEmpty()
{
    return (head == NULL);
}


void PriorQueue::PrintList()
{
    QueuePtr* printPtr;
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
