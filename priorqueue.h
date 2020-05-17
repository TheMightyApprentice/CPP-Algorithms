#ifndef PQUEUE
#define PQUEUE

#include <iostream>
#include <string>

struct QueuePtr;


class PriorQueue
{
    public:
        PriorQueue();
        //Narrative: Creates a linked list with default parameters.
        //Pre: None
        //Post: A linked list is created with default parameters.

        ~PriorQueue();
        //Narrative: Deallocates memory and deletes linked list.
        //Pre: None
        //Post: List memory de-allocated and deleted.

        void Push(int item, int w);
        //Narrative: Inserts a vertex from the graph that is related to the vertex this list belongs to in a sorted position by weight(priority).
        //Pre: item and w are integers
        //Post: Item is inserted in the vertex's list in a sorted position by weight.

        int ExtractMin();
        //Narrative: Pops the minimum value off the front of the priority queue.
        //Pre: item is an integer
        //Post: Item is inserted in the vertex's list in a sorted position.

        void ChangeWeight(int k, int w);
        //Narrative: Changes the weight value of nodes with key k to w.
        //Pre: k and w are integers
        //Post: Node with key k has its weight changed to w.

        bool IsEmpty();
        //Narrative: Checks to see if linked list (priority queue) is empty.
        //Pre: None
        //Post: True or false is returned.

        void PrintList();
        //Narrative: Outputs the queue in order of priority.
        //Pre: None
        //Post: Queue's contents output.

    private:
        QueuePtr* current;
        QueuePtr* head;
};



#endif
