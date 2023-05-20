
**Exploring Function Implementations in the Project with the Assistance of GPT**

```cpp
bool GraphMutator::AddVertex(string vertex, unordered_map<string, unordered_set<Edge, EdgeHash>>& adj) {
    if (adj.count(vertex)) {
        return false;
    }
    unordered_set<Edge, EdgeHash> emptyEdge;
    adj[vertex] = emptyEdge;
    operation.push({ 1, vertex });
    return true;
}
```
Explanation: This function adds a new vertex to the graph. It checks if the vertex already exists in the adjacency list (`adj`) using the `count()` function. If the vertex already exists, it returns `false` indicating that the addition failed. Otherwise, it creates an empty `unordered_set<Edge, EdgeHash>` to represent the adjacency list for the new vertex and adds it to the adjacency list using the vertex name as the key. The function also adds the operation to the `operation` stack to track the changes made to the graph. Finally, it returns `true` to indicate a successful addition of the vertex.

```cpp
bool GraphMutator::AddEdge(string source, string destination, double Distance, bool Directed, unordered_map<string, unordered_set<Edge, EdgeHash>>& adj) {
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
```
Explanation: This function adds a new edge between two vertices in the graph. It checks if both the source and destination vertices exist in the adjacency list (`adj`). If any of the vertices is missing, it returns `false` indicating that the addition failed. Next, it creates a new `Edge` object with the destination vertex, distance, and a flag indicating whether the edge is valid. It then checks if the edge already exists in the adjacency list for the source vertex. If the edge already exists, it returns `false`. Otherwise, it inserts the new edge into the adjacency lists of both the source and destination vertices. Finally, it adds the operation to the `operation` stack and returns `true` to indicate a successful addition of the edge.

```cpp
bool GraphMutator::DelVertex(string vertex, bool Directed, unordered_map<string, unordered_set<Edge, EdgeHash>>& adj) {
    if (!adj.count(vertex))
        return false;
    unordered_set<Edge, EdgeHash> children = adj[vertex];
    for (auto city : children) {
        DelEdge(vertex, city.dest, city.dist, Directed, adj);
    }
    adj.erase(vertex);
    operation.push({ 2, vertex });
    return true;
}
```
Explanation: This function deletes a vertex from the graph. It first checks if the vertex exists in the adjacency list (`adj`). If the vertex does not exist, it returns `false` indicating that the deletion failed. Next, it retrieves the set of edges connected to the vertex and iterates over them. For each edge, it calls the `DelEdge()` function to delete the edge from the graph. After deleting all the connected edges, it removes the vertex from the adjacency list and adds the operation to the `operation` stack. Finally, it returns `true` to indicate a successful deletion of the vertex.

```cpp
bool GraphMutator::DelEdge(string source, string destination, double Distance, bool Directed, unordered_map<string

, unordered_set<Edge, EdgeHash>>& adj) {
    if (!adj.count(source) || !adj.count(destination))
        return false;
    Edge e = { destination, Distance, 1 };
    int check = adj[source].erase(e);
    if (!check)
        return false;
    e.dest = source;
    e.valid = !Directed;
    adj[destination].erase(e);
    operation.push({ 4, source,destination,Distance });
    return true;
}
```
Explanation: This function deletes an edge between two vertices in the graph. It first checks if both the source and destination vertices exist in the adjacency list (`adj`). If any of the vertices is missing, it returns `false` indicating that the deletion failed. Next, it creates an `Edge` object with the destination vertex, distance, and a flag indicating whether the edge is valid. It uses the `erase()` function to remove the edge from the adjacency list of the source vertex. If the edge is not found in the adjacency list, it returns `false`. Then, it updates the destination vertex and the validity flag of the edge and removes the edge from the adjacency list of the destination vertex. Finally, it adds the operation to the `operation` stack and returns `true` to indicate a successful deletion of the edge.

```cpp
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
```
Explanation: This function undoes the previous graph operation by reverting the changes made to the graph. If the `operation` stack is empty, indicating no operations to undo, the function simply returns. Otherwise, it retrieves the most recent operation from the stack. Depending on the type of operation, it calls the corresponding function (`DelVertex()`, `AddVertex()`, `DelEdge()`, or `AddEdge()`) to undo the operation. If the operation was a vertex deletion (operation type 2), it also checks for additional consecutive vertex deletions and recursively calls `Undo()` to undo those deletions as well. Finally, it removes the operation from the stack (except for consecutive vertex deletions) and returns.

```cpp
pair<vector<string>, double> ShortestPath::Dijkstra(string source, string destination, unordered_map<string, unordered_set<Edge, EdgeHash>> &graph) {
    pair<vector<string>, double> route;
    if (!graph.count(source) || !graph.count(destination))
        return route;
    double inf = numeric_limits<double>::infinity();
    unordered_map<string, double> dist;
    for (auto& city : graph)
        dist[city.first] = inf;
    unordered_map<string, string> pre;
    unordered_map<string, bool> visited;

    priority_queue<pair<double, string>> nexttovisit;
    dist[source] = 0;
    pre[source] = source;

    nexttovisit.push({ 0, source });
    while (!nexttovisit.empty()) {
        pair<double, string> u = nexttovisit.top();
        u.first *= -1;
        nexttovisit.pop();
        if (visited[u.second])
            continue;
        visited[u.second] = true;
        for (auto e : graph[u.second]) {
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

    route.first.push_back(source);
    reverse(route.first.begin(), route.first.end());
    return route;
}
```

Now, let's explain how the `Dijkstra` function works:

- The function takes the `source` and `destination` nodes as input along with a `graph`, which is represented as an unordered map of strings and unordered sets of `Edge` objects.
- It initializes an empty `route` and checks if the `source` and `destination` nodes exist in the graph. If either of them doesn't exist, it returns the empty `route`.
- It initializes the distance values for all nodes in the `dist` unordered map and sets them to infinity (`inf`).
- It also initializes two additional unordered maps: `pre` to keep track of the previous node in the shortest path and `visited` to mark visited nodes.
- A priority queue named `nexttovisit` is used to store nodes based on their current shortest distance.
- The distance of the `source` node is set to 0, and the `pre` map is updated with the source node itself as the previous node.
- The `source` node is pushed into `nexttovisit` with a distance of 0.
- The algorithm enters a loop that continues until `nexttovisit` is empty.
- In each iteration, the node with the shortest distance is extracted from `nexttovisit`. The distance is negated to ensure that the priority queue sorts nodes based on the smallest distance.
- If the extracted node has already been visited, the loop continues to the next iteration.
- For each outgoing edge from the current node, the algorithm checks if the edge is valid. If it is not valid, the loop continues to the next iteration.
- The destination node of the edge is assigned to `v`, and the weight of the edge is assigned to `c`.
- If the sum of the current distance and the edge weight is smaller than

 the previously recorded distance for `v`, the distance for `v` is updated, and `pre` is updated with the current node as the previous node for `v`.
- The updated distance and the destination node `v` are pushed into `nexttovisit`, ensuring that the node with the smallest distance is at the top of the priority queue.
- After the loop ends, the function checks if the distance to the `destination` node is still infinity. If it is, the function returns the empty `route`.
- The shortest distance from the `source` to the `destination` is assigned to `route.second`.
- The function then reconstructs the shortest path by starting from the `destination` node and following the previous nodes stored in the `pre` map until it reaches the `source` node.
- The nodes are added to `route.first` in reverse order.
- Finally, the `route.first` vector is reversed to obtain the correct order of nodes in the shortest path, and the `route` is returned.


1. `pair<vector<string>, double> ShortestPath::BellmanFord(string source, string destination, unordered_map<string, unordered_set<Edge, EdgeHash>>& adj)`:
```cpp
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

    // Return path and shortest distance
    return make_pair(path, distances[destination]);
}
```
Explanation: The `BellmanFord` function implements the Bellman-Ford algorithm to find the shortest path from a source node to a destination node in a weighted graph. It initializes the distances of all nodes to infinity except for the source node, which is set to 0. The function then relaxes the edges V-1 times to find the shortest distances. It also checks for negative weight cycles. If a negative weight cycle is found, the function returns an empty path and a negative infinity value. Otherwise, it reconstructs the shortest path by following the parent pointers and returns the path and shortest distance.

2. `vector<string> GraphTraversal::BFS(string start, unordered_map<string, unordered_set<Edge, EdgeHash>> &adj)`:
```cpp
vector<string> GraphTraversal::BFS(string start, unordered_map<string, unordered_set<Edge, EdgeHash>> &adj) {
    vector<string> route;
    queue<string> q;
    unordered_map<string, bool> isVisited;
    q.push(start);
    isVisited[start] = true;

    while (!q.empty()) {
        string curr = q.front();
        route.push_back(curr);
        q.pop();
        for (auto neighbour : adj[curr]) {
            if (!isVisited[neighbour.dest]) {
                q.push(neighbour.dest);
                isVisited[neighbour.dest] = true;
            }
        }
    }
    return route;
}
```
Explanation: The `BFS` function performs a breadth-first search traversal starting from a given node. It uses a queue to keep track of the nodes to visit. It starts by pushing the `start` node into the queue and

 marks it as visited. Then, it enters a loop that continues until the queue is empty. In each iteration, it dequeues a node, adds it to the `route` vector, and explores its neighbors. If a neighbor has not been visited before, it is added to the queue and marked as visited. This process continues until all reachable nodes have been visited, and the function returns the `route` vector.

3. `vector<string> GraphTraversal::DFS(string start, unordered_map<string, unordered_set<Edge, EdgeHash>> &adj)`:
```cpp
vector<string> GraphTraversal::DFS(string start, unordered_map<string, unordered_set<Edge, EdgeHash>> &adj) {
    vector<string> route;
    unordered_map<string, bool> visited;
    stack<string> s;
    s.push(start);
    visited[start] = true;

    while (!s.empty()) {
        string current = s.top();
        route.push_back(current);
        s.pop();

        for (auto child : adj[current]) {
            if (!child.valid)
                continue;
            if (!visited[child.dest]) {
                s.push(child.dest);
                visited[child.dest] = true;
            }
        }
    }
    return route;
}
```
Explanation: The `DFS` function performs a depth-first search traversal starting from a given node. It uses a stack to keep track of the nodes to visit. It starts by pushing the `start` node into the stack and marks it as visited. Then, it enters a loop that continues until the stack is empty. In each iteration, it pops a node from the stack, adds it to the `route` vector, and explores its children (neighbors). If a child has not been visited before, it is pushed onto the stack and marked as visited. This process continues until all reachable nodes have been visited, and the function returns the `route` vector.
