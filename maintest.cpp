#include "graph.h"
#include "adjacencylist.h"
#include <iostream>
#include <string>

using namespace std;

void AskToInsertEdge(Graph& g, bool d);
//Narrative: Asks the user to input an edge and will continue to insert edges as long as the user wants to.
//Pre: g is a reference to a version of the Graph class and d is a boolean
//Post: The desired number of edges are inserted into the graph.

int main()
{
    int graphsize;
    int bvalue;
    int dvalue;
    int pvalue;
    int disvalue, dievalue;
    bool directb;

    cout << endl << "Is the graph directed (true: 1 or false: 0)? ";
    cin >> directb;
    cout << endl;

    cout << "How many nodes (vertices) make up this graph? ";
    cin >> graphsize;
    cout << endl;

    Graph testgraphUnd(graphsize);
    AskToInsertEdge(testgraphUnd, directb);
    testgraphUnd.TraversalPrint();


    cout << "What value is the start of BFS? ";
    cin >> bvalue;
    cout << endl;

    testgraphUnd.BFSTraversal(bvalue);


    cout << "What value is the start of DFS? ";
    cin >> dvalue;
    cout << endl;

    testgraphUnd.DFSTraversal(dvalue);


    cout << "What value is the start of Prim's? ";
    cin >> pvalue;
    cout << endl;

    testgraphUnd.Prims(pvalue);


    cout << "What value is the start of Dijkstra's? ";
    cin >> disvalue;
    cout << endl << "What value is the end of Dijkstra's? ";
    cin >> dievalue;
    cout << endl;

    testgraphUnd.Dijkstras(disvalue, dievalue);


    return 0;
}


void AskToInsertEdge(Graph& g, bool d)
{
    int secnum, vertexnum, weight;
    string vertname, secname;
    bool repeat = false;

    cout << "Input a vertex number. ";
    cin >> vertexnum;
    cout << endl << "Input the string related to vertex. ";
    cin >> vertname;
    cout << endl << "Input vertex that current vertex leads to. ";
    cin >> secnum;
    cout << endl << "Input the string related to second vertex. ";
    cin >> secname;
    cout << endl << "What is the weight value of this edge? ";
    cin >> weight;
    cout << endl;
    

    g.AssignString(vertexnum, vertname);
    g.AssignString(secnum, secname);
    g.Insert(vertexnum, secnum, weight, d);

    cout << endl << "Insert another edge (1 or 0)? ";
    cin >> repeat;
    cout << endl;

    if(repeat)
    {
        cout << endl;
        AskToInsertEdge(g, d);
    }
}
