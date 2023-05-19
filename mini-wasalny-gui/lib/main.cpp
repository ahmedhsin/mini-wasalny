#include <iostream>
#include "Graph.h"
using namespace std;

int main()
{
    Graph g(false);
    g.AddEdge("dahab", "cairo", 98);
    g.Print();
    //g.DelGraph();
   // cout << "test";
    return 0;
}
