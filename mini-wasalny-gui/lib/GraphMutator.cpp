#include "GraphMutator.h"

GraphMutator::GraphMutator()
{
    //ctor
}

bool GraphMutator::AddVertex(string vertex, unordered_map<string, unordered_set<Edge, EdgeHash>> &adj) {
    // check if the vertex already exists in the graph
    if (adj.count(vertex)) {
        return false; // vertex already present
    }
    // vertex not in graph, add it with an empty adjacency list
    unordered_set<Edge, EdgeHash>emptyEdge;
    adj[vertex] = emptyEdge;
    operation.push({ 1, vertex });
    return true;
}

bool GraphMutator::AddEdge(string source, string destination,double Distance,bool Directed, unordered_map<string, unordered_set<Edge, EdgeHash>> &adj) {
    // Implementation for adding an edge between two vertices'
    // Implementation for adding an edge between two vertices
    //check if cities are not in list
    if (!adj.count(source) || !adj.count(destination))
        return false;
    Edge new_Edge = { destination, Distance, 1 };
    if (adj[source].count(new_Edge))
        return false;
    adj[source].insert(new_Edge);
    new_Edge.dest = source;
    new_Edge.valid = !Directed;
    adj[destination].insert(new_Edge);
    operation.push({ 3,source,destination,Distance });
    return true;

}

bool GraphMutator::DelVertex(string vertex,bool Directed, unordered_map<string, unordered_set<Edge, EdgeHash>> &adj) {
    // Implementation for deleting a vertex.    return true;

    if (!adj.count(vertex))
        return false;

    unordered_set<Edge, EdgeHash> children = adj[vertex];
    for (auto city : children) {
        DelEdge(vertex, city.dest,city.dist, Directed, adj);
    }
    adj.erase(vertex);
    operation.push({ 2, vertex });
    return true;
}

bool GraphMutator::DelEdge(string source, string destination, double Distance,bool Directed, unordered_map<string, unordered_set<Edge, EdgeHash>> &adj) {
    if (!adj.count(source) || !adj.count(destination))
        return false;
    Edge e = {destination, Distance, 1};
    int check=adj[source].erase(e);
    if(!check)
        return false;
    e.dest=source;
    e.valid=!Directed;
    adj[destination].erase(e);
    operation.push({ 4, source,destination,Distance });
    return true;
}
void GraphMutator::Undo(bool Directed, unordered_map<string, unordered_set<Edge, EdgeHash>>& adj) {
    if (operation.empty())
        return;
    operations current = operation.top();
    operation.pop();
    switch (current.op) {
    case 1:
        DelVertex(current.src, Directed, adj);
        break;
    case 2:
        AddVertex(current.src, adj);
        operation.pop();
        while (!operation.empty() && operation.top().src == current.src)
            Undo(Directed, adj);
        break;
    case 3:
        DelEdge(current.src, current.edge.dest, current.edge.dist, Directed, adj);
        break;
    case 4:
        AddEdge(current.src, current.edge.dest, current.edge.dist, Directed, adj);
        break;
    default:
        break;
    }
    if (current.op != 2)
        operation.pop();
}
GraphMutator::~GraphMutator()
{
    //dtor
}
