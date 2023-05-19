#ifndef SHORTESTPATH_H
#define SHORTESTPATH_H
#include <string>
#include <unordered_map>
#include <queue>
#include <vector>
#include "Edge.h"
#include <algorithm>
using namespace std;

class ShortestPath
{
    public:
        ShortestPath();
        pair<vector<string>, double> Dijkstra(string source, string destination, unordered_map<string, unordered_set<Edge, EdgeHash>> &adj);
        pair<vector<string>, double> BellmanFord(string source, string destination, unordered_map<string, unordered_set<Edge, EdgeHash>>& adj);

        virtual ~ShortestPath();

    protected:

    private:
};

#endif // SHORTESTPATH_H
