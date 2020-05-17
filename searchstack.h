#ifndef SSTACK
#define SSTACK

struct SearchPtr;

class SearchStack
{
    public:
        SearchStack();
        //Narrative: Creates stack with parameters set to default values
        //Pre-condition: None
        //Post-condition: Stack created with default values

        ~SearchStack();
        //Narrative: De-allocates memory and deletes stack
        //Pre-condition: None
        //Post-condition: Stack memory de-allocated and deleted

        void PushVertex(int value);
        //Narrative: Inserts value onto top of stack and sets up nextVertex. Length incremented by 1.
        //Pre-condition: value is an integer
        //Post-condition: Value placed onto stack and link set up. Length incremented by 1.

        void PopVertex();
        //Narrative: Removes top node and sets topVertex to be one lower than the node removed. Length is decremented by one.
        //Pre-condition: Stack is not empty
        //Post-condition: Length is decremented by one, top node removed, and nextVertex changed.

        int Peek();
        //Narrative: Returns the name of the top node
        //Pre-condition: None
        //Post-condition: Name or empty string returned

        int GetLength() const;
        //Narrative: Returns length/size of stack
        //Pre-condition: None
        //Post-condition: Length/size returned

        bool IsEmpty() const;
        //Narrative: Checks if topVertex is NULL
        //Pre-condition: None
        //Post-condition: True or false returned if topVertex is or is not equal to NULL

        void Display();
        //Narrative: Outputs stack from topVertex's value to value of bottom node
        //Pre-condition: topMan is not NULL
        //Post-condition: Stack is output

    private:
        int length;
        SearchPtr* topVertex;
};

#endif

