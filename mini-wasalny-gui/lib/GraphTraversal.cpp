#include "GraphTraversal.h"

GraphTraversal::GraphTraversal()
{
    //ctor
}
vector<string> GraphTraversal::BFS(string start, unordered_map<string, unordered_set<Edge, EdgeHash>> &adj){
    vector<string>route;
    queue<string> q;
    unordered_map<string, bool> isVisited;
    q.push(start);
    isVisited[start] = true;
    while (!q.empty()) {
        string curr = q.front();
        route.push_back(curr);
        q.pop();
        for (auto neighbour : adj[curr])
        {
            if (!isVisited[neighbour.dest]) {
                q.push(neighbour.dest);
                isVisited[neighbour.dest] = true;
            }
        }
    }
    return route;
}
vector<string> GraphTraversal::DFS(string start, unordered_map<string, unordered_set<Edge, EdgeHash>> &adj){
    vector<string>route;
    unordered_map<string, bool> visited;
    stack<string> s;
    s.push(start);
    visited[start] = true;

    while (!s.empty()) {
        string current = s.top();
        route.push_back(current);
        s.pop();

        for (auto child : adj[current]) {
            if (!visited[child.dest]) {
                s.push(child.dest);
                visited[child.dest] = true;
            }
        }

    }
    return route;
}
GraphTraversal::~GraphTraversal()
{
    //dtor
}
