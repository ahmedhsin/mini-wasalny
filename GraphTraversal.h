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
        vector<string> BFS(unordered_map<string, vector<string>> &adj);
        vector<string> DFS(unordered_map<string, vector<string>> &adj);


    protected:

    private:
};

#endif // GRAPHTRAVERSAL_H
