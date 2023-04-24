#ifndef GRAPHMUTATOR_H
#define GRAPHMUTATOR_H
#include <string>
#include <unordered_map>
#include <vector>
using namespace std;
class GraphMutator
{
    public:
        GraphMutator();
        virtual ~GraphMutator();
        bool AddVertex(string vertex, unordered_map<string, vector<string>> &adj);
        bool AddEdge(string source, string destination, unordered_map<string, vector<string>> &adj);
        bool DelVertex(string vertex, unordered_map<string, vector<string>> &adj);
        bool DelEdge(string source, string destination, unordered_map<string, vector<string>> &adj);

    protected:

    private:

};

#endif // GRAPHMUTATOR_H
