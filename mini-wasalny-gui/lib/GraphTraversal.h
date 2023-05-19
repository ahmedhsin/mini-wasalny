#ifndef GRAPHTRAVERSAL_H
#define GRAPHTRAVERSAL_H
#include <unordered_map>
#include <vector>
#include <string>
#include <queue>
#include <stack>

#include "Edge.h"

#include <iostream>
using namespace std;

class GraphTraversal
{
    public:
        GraphTraversal();
        virtual ~GraphTraversal();
        vector<string> BFS(string start, unordered_map<string, unordered_set<Edge, EdgeHash>> &adj);
        vector<string> DFS(string start, unordered_map<string, unordered_set<Edge, EdgeHash>> &adj);


    protected:

    private:
};

#endif // GRAPHTRAVERSAL_H
