#ifndef FILEENGINE_H
#define FILEENGINE_H
#include <boost/serialization/vector.hpp>
#include <boost/serialization/unordered_map.hpp>
#include <boost/archive/text_oarchive.hpp>
#include <boost/archive/text_iarchive.hpp>
#include <fstream>
#include <unordered_map>
#include <vector>
#include <string>
#include <iostream>
using namespace std;
class FileEngine
{
    public:
        FileEngine();
        bool save(unordered_map<string, vector<string>> &adj);
        bool load(unordered_map<string, vector<string>> &adj);
        virtual ~FileEngine();

    protected:

    private:

};

#endif // FILEENGINE_H
