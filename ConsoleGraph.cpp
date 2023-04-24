#include "ConsoleGraph.h"

ConsoleGraph::ConsoleGraph()
{
    //ctor
}
void ConsoleGraph::Print(unordered_map<string, vector<string>> &adj){
    for (auto vertex : adj){
        cout<<vertex.first<<" : "<<endl;
        for (auto edge : vertex.second){
            cout<<edge<<" , ";
        }
        cout<<endl;
    }

}
ConsoleGraph::~ConsoleGraph()
{
    //dtor
}
