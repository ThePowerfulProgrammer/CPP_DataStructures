#ifndef GRAPHTYPE_H
#define GRAPHTYPE_H
#include "unorderedLinkedList.h"

class graphType
{
    public:
        bool isEmpty();
        void createGraph();
        void clearGraph();
        void printGraph();
        // Processing a graph requires the ability to traverse the graph
        void depthFirstTraversal();
        void dftAtVertex(int vertex);
        void breadthFirstTraversal();

        graphType(int size = 0);
        ~graphType();

    protected:
        int maxSize;
        int gSize;
        unorderedLinkedList<int> *graph;


    private:
        void dft(int v, bool visited[]);
};

void graphType::isEmpty()
{
    return (gSize == 0);
}

/*
For illustration purposes, we assume that the data to the program is
input from a file. The user is prompted for the input file. The data in the file appears
in the following form:
5
0 2 4 ... −999
1 3 6 8 ... −999
...

The first line of input specifies the number of vertices in the graph. The first entry
in the remaining lines specifies the vertex, and all of the remaining entries in the line
(except the last) specify the vertices that are adjacent to the vertex. Each line ends
with the number −999.
Using these conventions, the definition of the function createGraph is as follows:
*/

void graphType::createGraph()
{
    ifstream infile;
    char fileName[50];

    int index;
    int vertex;
    int adjacentVertex;
    if (gSize != 0)
        {
            clearGraph();
        }
    cout << "Enter file name: ";
    cin >> fileName;
    cout << endl;

    infile.open(fileName);
    if (!infile)
        {
            cout << "Cannot open input file" << endl;
            return;
        }
    infile >> gSize;

    for (index = 0; index<gSize; index++)
        {
            infile >> vertex;
            infile >> adjacentVertex;
            while (adjacentVertex != -999)
                {
                    graph[vertex].insertLast(adjacentVertex);
                    infile >> adjacentVertex;
                }
        }
    infile.close();
}

void graphType::clearGraph()
{
    int index;
    for (index = 0;index<gSize;index++)
        {
            graph[index].destroyList();
        }
    gSize = 0;
}

void graphType::printGraph()
{
    int index;
    for (index = 0; index<gSize; index++)
        {
            cout << index << " ";
            graph[index].print();
            cout << endl;
        }
    cout << endl;
}

graphType::graphType(int size)
{
    maxSize = size;
    gSize = 0;
    graph = new unorderedLinkedList<int>[size];
}

graphType::~graphType()
{
    clearGraph();
}

void graphType::dft(int v, bool visited[])
{
    visited[v] = true;
    cout << " " << v << " "; // visit the vertex

    linkedListIterator<int> graphIt;

    for (graphIt = graph[v].begin(); graphIt != graph[v].end(); ++graphIt)
        {
            int w = *graphIt;
            if (!visited[w])
                {
                    dft(w,visited);
                }
        }
}

void graphType::depthFirstTraversal()
{
    bool *visited;

    visited = new bool[gSize];

    int index;

    for (index =0; index<gSize; index++)
        {
            visited[index] = false;
        }
    for (index = 0; index<gSize; index++)
        {
            if (!visited[index])
                {
                    dft(index, visited);
                }
        }
    delete [] visited;
}

void graphType::dftAtVertex(int vertex)
{
    bool *visited;

    visited = new bool[gSize];

    for (int index=0;index<gSize;index++)
        {
            visited[index] = false;
        }
    dft(vertex,visited);

    delete [] visited;
}

void graphType::breadthFirstTraversal()
{
    cout << "Need linkedQueue :(" << endl;
}



#endif // GRAPHTYPE_H
