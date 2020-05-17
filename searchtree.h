#ifndef STREE
#define STREE

#include <iostream>
#include <string>

struct TreePtr;

class SearchTree
{
    public:
	SearchTree();
        //  Narrative: Creates search tree with parameters set to default values
        //  Pre-condition: None
        //  Post-condition: Search tree created with default values

        ~SearchTree();
        //  Narrative: De-allocates memory and deletes search tree
        //  Pre-condition: None
        //  Post-condition: Search tree memory de-allocated and deleted

        void Insert(int item, int itemP);
        //  Narrative: Inserts item into tree as a child of itemP.
        //  Pre-condition: item and itemP are integers
        //  Post-condition: Item placed into tree in correct position.

        TreePtr* Search(TreePtr* position, int item);
        //  Narrative: Returns the node that has key as its item if found
        //  Pre-condition: position is a TreePtr* and item is an integer
        //  Post-condition: Node related to key is returned or NULL

        TreePtr* GetHeadTree();
        //  Narrative: Returns the headTree node
        //  Pre-condition: None
        //  Post-condition: headTree node returned

	void PreorderTraverseToArr(TreePtr* x);
        //  Narrative: Inserts tree nodes into array in preorder formation
        //  Pre-condition: x is not null and is a TreePtr*
        //  Post-condition: Tree nodes are inserted into array in preorder formation

        void PreorderTraverse(TreePtr* x);
        //  Narrative: Outputs tree nodes in preorder formation
        //  Pre-condition: x is not null and is a TreePtr*
        //  Post-condition: Tree nodes are output in preorder formation

        void PostorderDelete(TreePtr* x);
        //  Narrative: Helps destructor deallocate nodes in a search tree by deleting the nodes from the bottom up to the top and final HeadTree
        //  Pre-condition: x is not null and is a TreePtr*
        //  Post-condition: Search tree nodes deleted from bottom to top


    private:
	TreePtr* headTree;
        TreePtr* current;
	TreePtr** array;
        int size;
};


#endif
