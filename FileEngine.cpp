#include "FileEngine.h"
FileEngine::FileEngine()
{
    //ctor
}
bool FileEngine::save(unordered_map<string, vector<string>> &adj) {
    std::ofstream ofs("Storage/data.enc");
    boost::archive::text_oarchive oa(ofs);
    oa & adj;
    return true;
}
bool FileEngine::load(unordered_map<string, vector<string>> &adj) {
    ifstream file("Storage/data.enc");
    if (!file.good())
        save(adj);
    ifstream ifs("Storage/data.enc");
    boost::archive::text_iarchive ia(ifs);
    ia & adj;
    return true;
}
FileEngine::~FileEngine()
{

}
