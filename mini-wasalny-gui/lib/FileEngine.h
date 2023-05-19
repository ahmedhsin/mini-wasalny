#ifndef FILEENGINE_H
#define FILEENGINE_H
/*
#include <boost/serialization/vector.hpp>
#include <boost/serialization/unordered_map.hpp>
#include <boost/archive/text_oarchive.hpp>
#include <boost/archive/text_iarchive.hpp>
*/
#include "include/nlohmann/json.hpp"
#include <fstream>
#include <unordered_map>
#include <vector>
#include <string>
#include <iostream>
#include "Edge.h"

using namespace std;
class FileEngine
{
    public:
        FileEngine();
        bool save(unordered_map<string, unordered_set<Edge, EdgeHash>> &adj);
        bool load(unordered_map<string, unordered_set<Edge, EdgeHash>> &adj);
        virtual ~FileEngine();

    protected:

    private:

};

#endif // FILEENGINE_H
