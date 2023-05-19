#include "ConsoleGraph.h"

ConsoleGraph::ConsoleGraph()
{
    //ctor
}
void ConsoleGraph::Print(unordered_map<string, unordered_set<Edge, EdgeHash>> &adj){
    for (auto vertex : adj){
        cout<<vertex.first<<" : "<<endl;
        for (auto edge : vertex.second){
            cout<<edge.dest<<" , ";
        }
        cout<<endl;
    }

}
ConsoleGraph::~ConsoleGraph()
{
    //dtor
}
