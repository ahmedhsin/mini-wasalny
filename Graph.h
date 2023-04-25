#ifndef GRAPH_H
#define GRAPH_H
#include "FileEngine.h"
#include "GraphTraversal.h"
#include "GraphMutator.h"
#include "ShortestPath.h"
#include "ConsoleGraph.h"
#include <unordered_map>
#include <vector>
#include <string>
#include <iostream>

using namespace std;
class Graph
{
    public:
        virtual ~Graph();
        Graph();
        vector<string> BFS();
        vector<string> DFS();
        pair<vector<string>, double> Dijkstra();
        bool save();
        bool load();
        bool DelGraph();
        bool AddVertex(string vertex);
        bool AddEdge(string source, string destination);
        bool DelVertex(string vertex);
        bool DelEdge(string source, string destination);
        void Print();


    protected:

    private:
        FileEngine DataStorage;
        GraphTraversal Traversal;
        GraphMutator Mutator;
        ShortestPath ShortPath;
        ConsoleGraph ConsoleG;
        unordered_map<string, vector<pair<string, double>>> adjacencyList;

};

#endif // GRAPH_H
