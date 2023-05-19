#ifndef CONSOLEGRAPH_H
#define CONSOLEGRAPH_H
#include <iostream>
#include <unordered_map>
#include <vector>
#include <string>
#include "Edge.h"
using namespace std;

class ConsoleGraph
{
    public:
        ConsoleGraph();
        virtual ~ConsoleGraph();
        void Print(unordered_map<string, unordered_set<Edge, EdgeHash>> &adj);
    protected:

    private:
};

#endif // CONSOLEGRAPH_H
