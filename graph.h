#ifndef GRAPH
#define GRAPH

#include "adjacencylist.h"
#include "searchstack.h"
#include "searchtree.h"
#include "priorqueue.h"
#include <iostream>
#include <string>


class Graph {
    public:
        Graph();
        //Narrative: Creates a Graph object with default parameters.
        //Pre: None
        //Post: A Graph object is created with default parameters.

        Graph(int size);
        //Narrative: Creates a Graph object with an adjacency list array of given size.
        //Pre: Size is a non-negative integer
        //Post: A Graph object is created with an adjacency list array of given size.

        void Insert(int n, int m, int w, bool directed);
        //Narrative: Inserts m as a connection from n if the directed boolean is true and both as a connection to each other if false.
        //Pre: n and m are integers that represent vertices in the adjacency list and directed is a boolean
        //Post: M is inserted as connection to n or both n and m are inserted into each other's connection lists.

        void AssignString(int vertex, std::string name);
        //Narrative: Assigns a string value to a vertex in the adjacency list.
        //Pre: vertex is an integer and name is a string
        //Post: String value assigned to vertex value.

        void BFSTraversal(int value);
        //Narrative: Traverses the graph using the breadth first search algorithm then outputs the search tree.
        //Pre: Value is an integer in the graph
        //Post: Graph traversed and search tree output.

        void DFSTraversal(int value);
        //Narrative: Traverses the graph using the depth first search algorithm then outputs the search tree.
        //Pre: Value is an integer in the graph
        //Post: Graph traversed and search tree output.

        void Prims(int value);
        //Narrative: Traverses the graph using prim's algorithm then outputs the minimum spanning tree.
        //Pre: Value is an integer in the graph
        //Post: Graph traversed and search tree output.

        void Dijkstras(int start, int end);

        void TraversalPrint();
        //Narrative: Outputs the adjacency list as a vertex with each vertex that it connects to.
        //Pre: None
        //Post: Adjacency list output.

    private:
	std::string* vertexString;
        AdjList* graphArray;
	SearchStack* searchArray;
        bool* discovered;
	bool traversed;
        int s;
        int rowNum;
        int currentWeight;
        int primNum;
	int* parent;
	int* priorA;
        int* nodePrim;
	int** edgeList;
        static const std::string NOTAVAIL;
};




#endif
