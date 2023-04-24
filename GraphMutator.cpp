#include "GraphMutator.h"

GraphMutator::GraphMutator()
{
    //ctor
}

bool GraphMutator::AddVertex(string vertex, unordered_map<string, vector<string>> &adj) {
    // Implementation for adding a vertex
}

bool GraphMutator::AddEdge(string source, string destination, unordered_map<string, vector<string>> &adj) {
    // Implementation for adding an edge between two vertices
}

bool GraphMutator::DelVertex(string vertex, unordered_map<string, vector<string>> &adj) {
    // Implementation for deleting a vertex
}

bool GraphMutator::DelEdge(string source, string destination, unordered_map<string, vector<string>> &adj) {
    // Implementation for deleting an edge between two vertices
}

GraphMutator::~GraphMutator()
{
    //dtor
}
