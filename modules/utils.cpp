#include "utils.h"

bool getParameterValue(char *parameter, int argc, char *argv[], string *value)
{
    for (int i = 0; i < argc; i++)
    {
        if (strcmp(parameter, argv[i]) == 0)
        {
            if ((strcmp(parameter, "-f") == 0 ||
                 strcmp(parameter, "-o") == 0 ||
                 strcmp(parameter, "-i") == 0) &&
                i + 1 < argc)
            {
                *value = string(argv[i + 1]);
                return true;
            }
            else if ((strcmp(parameter, "-h") == 0 ||
                      strcmp(parameter, "-s") == 0))
            {
                return true;
            }
            else
            {
                return false;
            }
        }
    }
    return false;
}

Graph createGraphFromFile(string filename)
{
    ifstream file(filename);

    int n, m;
    string line;

    getline(file, line);

    istringstream iss(line);
    iss >> n >> m;

    Graph graph(n);

    while (getline(file, line))
    {
        istringstream iss(line);
        int u, v, w;
        iss >> u >> v >> w;
        graph.addEdge(u, v, w);
    }
    file.close();

    return graph;
}

Graph createGraphFromFile2(string filename)
{
    ifstream file(filename);

    int n, m;
    string line;

    getline(file, line);

    istringstream iss(line);
    iss >> n >> m;

    Graph graph(n);

    while (getline(file, line))
    {
        istringstream iss(line);
        int u, v;
        iss >> u >> v;
        graph.addEdge2(u, v);
    }
    file.close();

    return graph;
}

Graph createGraphFromFile3(string filename)
{
    ifstream file(filename);

    int n, m;
    string line;

    getline(file, line);

    istringstream iss(line);
    iss >> n >> m;

    Graph graph(n);

    while (getline(file, line))
    {
        istringstream iss(line);
        int u, v, w;
        iss >> u >> v >> w;
        graph.addEdge3(u, v, w);
    }
    file.close();

    return graph;
}

int getTotalWeight(Graph &mst)
{
    int totalWeight = 0;
    for (int v = 0; v < mst.getSize(); ++v)
    {
        for (Edge e : mst.getVertexEdges(v))
        {
            totalWeight += e.weight;
        }
    }
    return totalWeight / 2;
}

void writeMstEdgesToFile(Graph &mst, string output_filename)
{
    ofstream file(output_filename);
    for (int i = 0; i < mst.getSize(); i++)
    {
        for (Edge e : mst.getVertexEdges(i))
        {
            if (e.source < e.neighbor)
            {
                file << e.source << " " << e.neighbor << " " << e.weight << endl;
            }
        }
    }
    file.close();
}

void printMstSolution(Graph &mst)
{
    for (int i = 0; i < mst.getSize(); i++)
    {
        for (Edge e : mst.getVertexEdges(i))
        {
            if (mst.notVisited(e.neighbor))
            {
                cout << "(" << i << "," << e.neighbor << ") ";
            }
        }
        mst.visit(i);
    }
    mst.resetVisited();
    cout << endl;
}