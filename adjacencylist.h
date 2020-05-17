#ifndef AJLIST
#define AJLIST

#include <iostream>
#include <string>

struct ListPtr;

class AdjList {
    public:
        AdjList();
        //Narrative: Creates a linked list with default parameters.
        //Pre: None
        //Post: A linked list is created with default parameters.

        ~AdjList();
        //Narrative: Deallocates memory and deletes linked list.
        //Pre: None
        //Post: List memory de-allocated and deleted.

	void SortedInsert(int item);
        //Narrative: Inserts a vertex from the graph that is related to the vertex this list belongs to in a sorted position.
        //Pre: item is an integer
        //Post: Item is inserted in the vertex's list in a sorted position.

        int GetNextItem();

        void Reset();

        bool HasNext() const;

	void PrintList();
        //Narrative: Outputs the linked list of vertices that are connected to the vertex this list belongs to.
        //Pre: None
        //Post: List of vertices output.

    private:
	ListPtr* current;
	ListPtr* head;
	int smallest;
};



#endif
