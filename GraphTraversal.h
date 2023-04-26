#ifndef GRAPHTRAVERSAL_H
#define GRAPHTRAVERSAL_H
#include <unordered_map>
#include <vector>
#include <string>
#include <iostream>
using namespace std;

class GraphTraversal
{
    public:
        GraphTraversal();
        virtual ~GraphTraversal();
        vector<string> BFS(string start ,unordered_map<string, vector<pair<string, double>>> &adj);
        vector<string> DFS(string start, unordered_map<string, vector<pair<string, double>>> &adj);


    protected:

    private:
};

#endif // GRAPHTRAVERSAL_H
