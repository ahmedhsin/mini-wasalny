#include "FileEngine.h"
FileEngine::FileEngine()
{
    //ctor
}
using json = nlohmann::json;

bool FileEngine::save(unordered_map<string, vector<pair<string, double>>> &adj) {

    /*
    // using boost lib to save data //
    std::ofstream ofs("Storage/data.enc");
    boost::archive::text_oarchive oa(ofs);
    oa & adj;
    */
    json j(adj); // convert the map to a json object
    std::ofstream ofs("Storage/data.enc");
    ofs << j.dump(4); // pretty-print with 4 spaces
    ofs.close();
    return true;
}
bool FileEngine::load(unordered_map<string, vector<pair<string, double>>> &adj) {
    /*
    // using boost lib to load data //
    ifstream file("Storage/data.enc");
    if (!file.good())
        save(adj);
    ifstream ifs("Storage/data.enc");
    boost::archive::text_iarchive ia(ifs);
    ia & adj;
    */
    std::ifstream ifs("Storage/data.enc");
    if (!ifs.good()) {
        save(adj);
    } else {
        json j;
        ifs >> j;
        adj = j.get<unordered_map<string, vector<pair<string, double>>>>(); // convert the json object back to a map
        ifs.close();
    }
    return true;
}
FileEngine::~FileEngine()
{

}
