#include "searchstack.h"
#include <iostream>

struct SearchPtr
{
    int vertex;
    SearchPtr* nextVertex;
};


SearchStack::SearchStack()
{
    length = 0;
    topVertex = NULL;
}


SearchStack::~SearchStack()
{
    SearchPtr* temp;
    SearchPtr* currentPtr = topVertex;

    while(currentPtr != NULL)
    {
        temp = currentPtr;
        currentPtr = currentPtr->nextVertex;
        delete temp;
    }
}


void SearchStack::PushVertex(int value)
{
    SearchPtr* newSearchPtr = new SearchPtr;

    if(value >= 0)
    {
        newSearchPtr->vertex = value;
        newSearchPtr->nextVertex = topVertex;

        topVertex = newSearchPtr;

        length++;
    }
}


void SearchStack::PopVertex()
{
    SearchPtr* temp;

    if(!IsEmpty())
    {
        temp = topVertex;
        topVertex = topVertex->nextVertex;
        temp->nextVertex = NULL;

        length --;
    }
}


int SearchStack::Peek()
{
    if(!IsEmpty())
    {
        return topVertex->vertex;
    }
    else
    {
        return -1;
    }
}

int SearchStack::GetLength() const
{
    return length;
}


bool SearchStack::IsEmpty() const
{
    return (topVertex == NULL);
}


void SearchStack::Display()
{
    SearchPtr* temp;

    if(topVertex != NULL)
    {
        temp = topVertex;
        while(temp != NULL)
        {
            std::cout << temp->vertex << "  ";
            temp = temp->nextVertex;
        }

        std::cout << std::endl;
    }
}

