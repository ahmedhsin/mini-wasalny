#ifndef GRAPH_H
#define GRAPH_H
#include "FileEngine.h"
#include "GraphTraversal.h"
#include "GraphMutator.h"
#include "ShortestPath.h"
#include "ConsoleGraph.h"
#include "Edge.h"
#include <unordered_map>
#include <vector>
#include<stack>
#include <string>
#include <iostream>
using namespace std;
class Graph
{
    public:
        virtual ~Graph();
        Graph(bool Directed);
        vector<string> BFS(string start);
        vector<string> DFS(string start);
        pair<vector<string>, double> Dijkstra(string source, string destination);
        pair<vector<string>, double> BellmanFord(string source, string destination);
        bool save();
        bool load();
        bool DelGraph();
        bool AddVertex(string vertex);
        bool AddEdge(string source, string destination,double Distance);
        bool DelVertex(string vertex);
        bool DelEdge(string source, string destination,double Distance);
        unordered_map<string, unordered_set<Edge, EdgeHash>>* getAdjacencyList();
        void Undo();
        void Print();
        bool Directed;
        bool IsEmpty();

    protected:

    private:
        FileEngine DataStorage;
        GraphTraversal Traversal;
        GraphMutator Mutator;
        ShortestPath ShortPath;
        ConsoleGraph ConsoleG;
        unordered_map<string, unordered_set<Edge, EdgeHash>> adjacencyList;
};

#endif // GRAPH_H
