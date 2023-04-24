#include "Graph.h"
Graph::Graph()
{
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
    /*vector<string>v = {"Alex", "Minia", "Assuit"};
    this->adjacencyList["Cairo"] = v;
    vector<string>vv = {"Cairo", "Minia", "AInSHames"};
    this->adjacencyList["Assuit"] = vv;*/
}
bool Graph::save(){
    DataStorage.save(this->adjacencyList);
    return true;
}
bool Graph::load(){
    DataStorage.load(this->adjacencyList);
    return true;
}
vector<string> Graph::BFS(){

    return this->Traversal.BFS(this->adjacencyList);
}
vector<string> Graph::DFS(){
    return this->Traversal.DFS(this->adjacencyList);
}

bool Graph::AddVertex(string vertex) {
    return this->Mutator.AddVertex(vertex, this->adjacencyList);
}

bool Graph::AddEdge(string source, string destination) {
    return this->Mutator.AddEdge(source, destination, this->adjacencyList);
}

bool Graph::DelVertex(string vertex) {
    return this->Mutator.DelVertex(vertex, this->adjacencyList);
}

bool Graph::DelEdge(string source, string destination) {
    return this->Mutator.DelEdge(source, destination, this->adjacencyList);
}
bool Graph::DelGraph(){
    this->adjacencyList.clear();
}
vector<string> Graph::Dijkstra(){
    return this->ShortPath.Dijkstra(this->adjacencyList);
}
void Graph::Print(){
    ConsoleG.Print(this->adjacencyList);
}
Graph::~Graph()
{
    this->save();
    //cout<<"KillProcess"<<endl;
}
