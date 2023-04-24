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
        vector<string> Dijkstra(unordered_map<string, vector<string>> &adj);
        virtual ~ShortestPath();

    protected:

    private:
};

#endif // SHORTESTPATH_H
