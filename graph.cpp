#include "graph.h"
#include <iostream>

using namespace std;

const string Graph::NOTAVAIL = "NA";

Graph::Graph()
{
    vertexString = new string[1];
    graphArray = new AdjList[1];
    discovered = new bool[1];
    searchArray = new SearchStack[1];
    parent = new int[1];
    priorA = new int[1];
    nodePrim = new int[1];
    edgeList = new int*[1];
    rowNum = 0;
    currentWeight = 0;
    primNum = 0;
    traversed = false;

    vertexString[0] = NOTAVAIL;
    vertexString[1] = NOTAVAIL;
}


Graph::Graph(int size)
{
    s = size + 1;
    vertexString = new std::string[s];
    graphArray = new AdjList[s];
    discovered = new bool[s];
    searchArray = new SearchStack[20];
    parent = new int[s];
    priorA = new int[s];
    nodePrim = new int[s];
    edgeList = new int*[s];

    for(int x = 0; x < s; x++)
    {
	edgeList[x] = new int[s];
    }

    rowNum = 0;
    currentWeight = 0;
    primNum = 0;
    traversed = false;

    for(int i = 0; i < s; i++)
    {
        vertexString[i] = NOTAVAIL;
	discovered[i] = false;
    }
}


void Graph::Insert(int n, int m, int w, bool directed)
{
    if(!directed)
    {
	graphArray[n].SortedInsert(m);
	graphArray[m].SortedInsert(n);
        edgeList[n][m] = w;
	rowNum++;
        edgeList[m][n] = w;
        rowNum++;
    }
    else
    {
	graphArray[n].SortedInsert(m);
        edgeList[n][m] = w;
        rowNum++;
    }
}


void Graph::AssignString(int vertex, string name)
{
    vertexString[vertex] = name;
}


void Graph::BFSTraversal(int value)
{
    int layer = 0;
    int fromVertex;
    int toVertex;
    bool test;
    discovered[value] = true;

    SearchTree tree;

    tree.Insert(value, value);

    searchArray[layer].PushVertex(value);

    while(searchArray[layer].IsEmpty() != true)
    {
        cout << "Layer " << layer << ": ";
        searchArray[layer].Display();
        for(int w = searchArray[layer].GetLength(); w > 0; w--)
	{
	    fromVertex = searchArray[layer].Peek();
	    searchArray[layer].PopVertex();
            graphArray[fromVertex].Reset();

	    while(graphArray[fromVertex].HasNext() != false)
	    {
                toVertex = graphArray[fromVertex].GetNextItem();

        	if(discovered[toVertex] == false)
		{
		    discovered[toVertex] = true;
		    tree.Insert(toVertex, fromVertex);
		    searchArray[layer + 1].PushVertex(toVertex);
		}
	    }
	}
	layer = layer + 1;
    }

    cout << endl;
}


void Graph::DFSTraversal(int value)
{
    int fromVertex, toVertex;

    cout << "Depth Path: ";

    for(int t = 0; t < s; t++)
    {
        discovered[t] = false;
    }

    SearchStack ss;
    SearchTree tr;

    ss.PushVertex(value);
    while(!ss.IsEmpty())
    {
	fromVertex = ss.Peek();
        ss.PopVertex();

        if(discovered[fromVertex] == false)
	{
            cout << fromVertex << " (" << vertexString[fromVertex] << ")  ";
	    discovered[fromVertex] = true;

            tr.Insert(fromVertex, parent[fromVertex]);

            graphArray[fromVertex].Reset();
	    while(graphArray[fromVertex].HasNext() != false)
	    {
		toVertex = graphArray[fromVertex].GetNextItem();
                parent[fromVertex] = toVertex;
		ss.PushVertex(toVertex);
	    }
	}
    }

    cout << endl << endl;
}


void Graph::Prims(int value)
{
    int extract;
    int vertex;

    for(int h = 0; h < s; h++)
    {
        priorA[h] = 1000000;
	discovered[h] = false;
        nodePrim[h] = 0;
    }

    priorA[value] = 0;

    PriorQueue Q;

    for(int w = 0; w < s; w++)
    {
	Q.Push(w, priorA[w]);
    }

    while(!Q.IsEmpty())
    {
	extract = Q.ExtractMin();
        nodePrim[primNum] = extract;
        primNum++;
        discovered[extract] = true;
        graphArray[extract].Reset();

        while(graphArray[extract].HasNext() != false)
        {
	    vertex = graphArray[extract].GetNextItem();

            if(discovered[vertex] == false && edgeList[extract][vertex] < priorA[vertex])
	    {
	        priorA[vertex] = edgeList[extract][vertex];
                Q.ChangeWeight(vertex, priorA[vertex]);
	    }
        }
    }

    cout << endl << "Prim's Algorithm: ";

    for(int q = 0; q < s; q++)
    {
	cout << nodePrim[q] << "  ";
    }

    cout << endl << endl;
}


void Graph::Dijkstras(int start, int end)
{
    int extract;
    int vertex;

    primNum = 0;

    for(int h = 0; h < s; h++)
    {
        priorA[h] = 1000000;
        discovered[h] = false;
        nodePrim[h] = 0;
    }

    priorA[start] = 0;

    PriorQueue R;

    for(int w = 0; w < s; w++)
    {
        R.Push(w, priorA[w]);
    }

    while(!R.IsEmpty())
    {
        extract = R.ExtractMin();
        nodePrim[primNum] = extract;
        primNum++;
        discovered[extract] = true;
        graphArray[extract].Reset();

        for(int q = 0; q < s; q++)
        {
            cout << priorA[q] << "  ";
        }
        cout << endl;
        R.PrintList();
        cout << endl;

        while(graphArray[extract].HasNext() != false)
        {
            vertex = graphArray[extract].GetNextItem();

            if(discovered[vertex] == false && (edgeList[extract][vertex] + priorA[extract]) < priorA[vertex])
            {
                priorA[vertex] = edgeList[extract][vertex] + priorA[extract];
	        R.ChangeWeight(vertex, priorA[vertex]);
            }
        }
    }

    cout << endl << "Dijkstra's Algorithm: ";

    for(int q = 0; q < s; q++)
    {
        cout << nodePrim[q] << "  ";
    }

    cout << endl << endl;
}


void Graph::TraversalPrint()
{
    int head;
    int value = 0;

    cout << endl;

    for(int p = 0; p < s; p++)
    {
        cout << p << " (" << vertexString[p] << ") " << "Goes to: ";
        graphArray[p].PrintList();

        cout << endl;
    }
}
