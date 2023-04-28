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
        bool AddVertex(string vertex, unordered_map<string, vector<pair<string, double>>> &adj);
        bool AddEdge(string source, string destination,double Distance,bool Directed, unordered_map<string, vector<pair<string, double>>> &adj);
        bool DelVertex(string vertex, unordered_map<string, vector<pair<string, double>>> &adj);
        bool DelEdge(string source, string destination,bool Directed, unordered_map<string, vector<pair<string, double>>> &adj);

    protected:

    private:

};

#endif // GRAPHMUTATOR_H
