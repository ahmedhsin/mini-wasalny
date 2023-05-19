#ifndef GRAPHMUTATOR_H
#define GRAPHMUTATOR_H
#include <string>
#include <unordered_map>
#include "Edge.h"
#include<stack>
#include <vector>
using namespace std;
struct operations {
    int op;
    string src;
    Edge edge;
};
class GraphMutator
{
    public:
        GraphMutator();
        virtual ~GraphMutator();
        bool AddVertex(string vertex, unordered_map<string, unordered_set<Edge, EdgeHash>> &adj);
        bool AddEdge(string source, string destination,double Distance,bool Directed, unordered_map<string, unordered_set<Edge, EdgeHash>> &adj);
        bool DelVertex(string vertex,bool Directed, unordered_map<string, unordered_set<Edge, EdgeHash>> &adj);
        bool DelEdge(string source, string destination, double Distance,bool Directed, unordered_map<string, unordered_set<Edge, EdgeHash>> &adj);
        void Undo(bool Directed, unordered_map<string, unordered_set<Edge, EdgeHash>>& adj);
    protected:

    private:
        stack<operations> operation;
};

#endif // GRAPHMUTATOR_H
