#ifndef SHORTESTPATH_H
#define SHORTESTPATH_H
#include <string>
#include <unordered_map>
#include <vector>
using namespace std;

class ShortestPath
{
    public:
        ShortestPath();
        pair<vector<string>, double> Dijkstra(string source, string destination, unordered_map<string, vector<pair<string, double>>> &adj);
        virtual ~ShortestPath();

    protected:

    private:
};

#endif // SHORTESTPATH_H
