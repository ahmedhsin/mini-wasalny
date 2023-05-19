#include "Graph.h"
Graph::Graph(bool Directed)
{
    this->Directed = Directed;
    this->load();
}
bool Graph::save(){
    DataStorage.save(this->adjacencyList);
    return true;
}
bool Graph::load(){
    DataStorage.load(this->adjacencyList);
    return true;
}
unordered_map<string, unordered_set<Edge, EdgeHash>>* Graph::getAdjacencyList(){
    return &(this->adjacencyList);
}
vector<string> Graph::BFS(string start){

    return this->Traversal.BFS(start ,this->adjacencyList);
}
vector<string> Graph::DFS(string start){
    return this->Traversal.DFS(start, this->adjacencyList);
}

bool Graph::AddVertex(string vertex) {
    return  this->Mutator.AddVertex(vertex, this->adjacencyList); 
}

bool Graph::AddEdge(string source, string destination,double Distance) {
    return this->Mutator.AddEdge(source, destination, Distance, this->Directed, this->adjacencyList);
}

bool Graph::DelVertex(string vertex) {
    return this->Mutator.DelVertex(vertex,this->Directed, this->adjacencyList);
}

bool Graph::DelEdge(string source, string destination,double distance) {
    return this->Mutator.DelEdge(source, destination,distance ,this->Directed, this->adjacencyList);
}
bool Graph::DelGraph(){
    this->adjacencyList.clear();
    this->save();

    return true;
}
bool Graph::IsEmpty(){
    if (this->adjacencyList.size() == 0)
        return true;
    return false;
}
pair<vector<string>, double> Graph::Dijkstra(string source, string destination){
    return this->ShortPath.Dijkstra(source, destination, this->adjacencyList);
}
pair<vector<string>, double> Graph::BellmanFord(string source, string destination) {
    return this->ShortPath.BellmanFord(source, destination, this->adjacencyList);
}
void Graph::Undo() {
    this->Mutator.Undo(this->Directed, this->adjacencyList);
}
void Graph::Print(){
    ConsoleG.Print(this->adjacencyList);
}
Graph::~Graph()
{

    this->save();
    //cout<<"killOBJECT"<<endl;
}
