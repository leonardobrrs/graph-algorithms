#include <iostream>
#include <vector>
#include "../modules/graph.h"

using namespace std;

void DFSRec(Graph &graph, int v)
{
    graph.visit(v);

    const vector<Edge> &edges = graph.getVertexEdges(v);
    for (unsigned int i = 0; i < edges.size(); i++)
    {
        if (graph.notVisited(edges[i].neighbor))
        {
            graph.registerParent(edges[i].neighbor, v);
            DFSRec(graph, edges[i].neighbor);
        }
    }
}

void DFS(Graph &graph, bool ignoreZero = true)
{
    int firstVertex;
    if (ignoreZero)
    {
        firstVertex = 1;
    }
    else
    {
        firstVertex = 0;
    }

    for (int v = firstVertex; v < graph.getSize(); v++)
    {
        if (graph.notVisited(v))
        {
            DFSRec(graph, v);
        }
    }
}

void readGraph(Graph &graph, int edgeCount)
{
    for (int i = 0; i < edgeCount; i++)
    {
        int u, v, w;
        cin >> u >> v >> w;
        graph.addEdge(u, v, w);
    }
}

int main()
{
    int n, m;
    cin >> n >> m;

    Graph graph(n + 1);
    readGraph(graph, m);
    graph.print();

    DFS(graph);

    graph.printVisited();
    graph.printParents();
}