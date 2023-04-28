#include "Graph.h"
Graph::Graph(bool Directed)
{
    this->Directed = Directed;
    this->load();
    FileEngine engine;
    GraphTraversal traverse;
    GraphMutator Mutator;
    ShortestPath Path;
    ConsoleGraph consoleG;
    this->Traversal = traverse;
    this->DataStorage = engine;
    this->Mutator = Mutator;
    this->ShortPath = Path;
    this->ConsoleG = consoleG;
    /*
    vector<pair<string, double>>v = {{"Alex", 35.5}, {"minia", 80}, {"Assuit", 60.30}};
    this->adjacencyList["Cairo"] = v;
    vector<pair<string, double>>vv = {{"Cairo", 60.14}, {"Minia", 20}, {"KafrElHahaha", 29.7}};
    this->adjacencyList["alex"] = vv;

    */
}
bool Graph::save(){
    DataStorage.save(this->adjacencyList);
    return true;
}
bool Graph::load(){
    DataStorage.load(this->adjacencyList);
    return true;
}
vector<string> Graph::BFS(string start){

    return this->Traversal.BFS(start ,this->adjacencyList);
}
vector<string> Graph::DFS(string start){
    return this->Traversal.DFS(start, this->adjacencyList);
}

bool Graph::AddVertex(string vertex) {
    return this->Mutator.AddVertex(vertex, this->adjacencyList);
}

bool Graph::AddEdge(string source, string destination,double Distance, bool Directed) {
    return this->Mutator.AddEdge(source, destination,Distance, this->Directed, this->adjacencyList);
}

bool Graph::DelVertex(string vertex) {
    return this->Mutator.DelVertex(vertex, this->adjacencyList);
}

bool Graph::DelEdge(string source, string destination, bool Directed) {
    return this->Mutator.DelEdge(source, destination,this->Directed, this->adjacencyList);
}
bool Graph::DelGraph(){
    this->adjacencyList.clear();
    return true;
}
pair<vector<string>, double> Graph::Dijkstra(string source, string destination){
    return this->ShortPath.Dijkstra(source, destination, this->adjacencyList);
}
void Graph::Print(){
    ConsoleG.Print(this->adjacencyList);
}
Graph::~Graph()
{
    this->save();
    //cout<<"KillProcess"<<endl;
}
