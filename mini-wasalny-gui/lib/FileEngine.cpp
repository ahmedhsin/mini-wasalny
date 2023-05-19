#include "FileEngine.h"
FileEngine::FileEngine()
{
    //ctor
}
using json = nlohmann::json;

void to_json(json& j, const Edge& edge)
{
    j = json{
        {"dest", edge.dest},
        {"dist", edge.dist},
        {"valid", edge.valid}
    };
}
void from_json(const json& j, Edge& edge)
{
    j.at("dest").get_to(edge.dest);
    j.at("dist").get_to(edge.dist);
    j.at("valid").get_to(edge.valid);
}

bool FileEngine::save(unordered_map<string, unordered_set<Edge, EdgeHash>> &adj) {

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
bool FileEngine::load(unordered_map<string, unordered_set<Edge, EdgeHash>> &adj) {
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
        json parsedJson = json::parse(ifs);
        ifs.close();

        adj = parsedJson.get<unordered_map<string, unordered_set<Edge, EdgeHash>>>();

        ifs.close();
    }
    return true;
}
FileEngine::~FileEngine()
{

}
