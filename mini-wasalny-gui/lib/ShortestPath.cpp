#include "ShortestPath.h"

ShortestPath::ShortestPath()
{
    //ctor
}
pair<vector<string>, double> ShortestPath::Dijkstra(string source, string destination, unordered_map<string, unordered_set<Edge, EdgeHash>> &graph){
    pair<vector<string>, double> route;
    if (!graph.count(source) || !graph.count(destination))
        return route;
    double inf = numeric_limits<double>::infinity();
    unordered_map<string, double> dist;
    for (auto& city : graph)
        dist[city.first] = inf;
    unordered_map<string, string> pre;
    unordered_map<string, bool> visited;

    priority_queue<pair<double, string>>nexttovisit;
    dist[source] = 0;
    pre[source] = source;

    nexttovisit.push({ 0, source });
    while (!nexttovisit.empty())
    {
        pair<double, string> u = nexttovisit.top();
        u.first *= -1;
        nexttovisit.pop();
        if (visited[u.second])
            continue;
        visited[u.second] = true;
        for (auto e : graph[u.second])
        {
            if (!e.valid)
                continue;
            string v = e.dest;
            double c = e.dist;
            if (u.first + c < dist[v]) {
                dist[v] = u.first + c;
                pre[v] = u.second;
            }
            nexttovisit.push({ -dist[v], v });

        }
    }
    if (dist[destination] == inf)
        return route;
    route.second = dist[destination];

    while (destination != source) {
        route.first.push_back(destination);
        destination = pre[destination];
    }
    /*

    */
    route.first.push_back(source);
    reverse(route.first.begin(), route.first.end());
    return route;
}
pair<vector<string>, double> ShortestPath::BellmanFord(string source, string destination, unordered_map<string, unordered_set<Edge, EdgeHash>>& adj) {
    unordered_map<string, double> distances;
    for (auto node : adj) {
        distances[node.first] = numeric_limits<double>::infinity();
    }
    distances[source] = 0;

    // Initialize parent pointers for path reconstruction
    unordered_map<string, string> parents;
    parents[source] = "";

    // Relax edges V-1 times
    //unordered_map<string, vec<pair<string,double>>>
    for (size_t i = 0; i < adj.size() - 1; ++i) {
        for (auto u : adj) {
            for (auto v : u.second) {
                if (!v.valid)
                    continue;
                if (distances[u.first] + v.dist < distances[v.dest]) {
                    distances[v.dest] = distances[u.first] + v.dist;
                    parents[v.dest] = u.first;
                }
            }
        }
    }

    // Check for negative weight cycles
    for (auto u : adj) {
        for (auto v : u.second) {
            if (!v.valid)
                continue;
            if (distances[u.first] + v.dist < distances[v.dest]) {
                // Negative cycle found, return empty path and negative infinity value
                return make_pair(vector<string>(), -numeric_limits<double>::infinity());
            }
        }
    }

    // Reconstruct shortest path from source to destination
    vector<string> path;
    string current = destination;
    while (current != "") {
        path.push_back(current);
        current = parents[current];
    }
    reverse(path.begin(), path.end());
    //for (auto i : adj)
    //    cout << i.first << " " << distances[i.first] << endl;
    // Return path and shortest distance
   // Return the shortest distance to the destination nodeand the path that yields that distance
    return make_pair(path, distances[destination]);
}
ShortestPath::~ShortestPath()
{
    //dtor
}
