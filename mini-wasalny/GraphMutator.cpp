#include "GraphMutator.h"

GraphMutator::GraphMutator()
{
    //ctor
}

bool GraphMutator::AddVertex(string vertex, unordered_map<string, vector<pair<string, double>>> &adj) {
    // Implementation for adding a vertex
    return true;
}

bool GraphMutator::AddEdge(string source, string destination,double Distance,bool Directed, unordered_map<string, vector<pair<string, double>>> &adj) {
    // Implementation for adding an edge between two vertices'
    return true;

}

bool GraphMutator::DelVertex(string vertex, unordered_map<string, vector<pair<string, double>>> &adj) {
    // Implementation for deleting a vertex.    return true;
    return true;

}

bool GraphMutator::DelEdge(string source, string destination,bool Directed, unordered_map<string, vector<pair<string, double>>> &adj) {
    // Implementation for deleting an edge between two vertices
    return true;

}

GraphMutator::~GraphMutator()
{
    //dtor
}
