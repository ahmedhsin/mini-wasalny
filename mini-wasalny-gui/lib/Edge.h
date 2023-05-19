#ifndef MY_HEADER_FILE_H
#define MY_HEADER_FILE_H

#include <iostream>
#include <unordered_map>
#include <unordered_set>
#include <string>

struct Edge {
    std::string dest;
    double dist;
    bool valid;

    bool operator==(const Edge& other) const {
        return (dest == other.dest && dist == other.dist && valid == other.valid);
    }
};

struct EdgeHash {
    size_t operator()(const Edge& edge) const {
        size_t destHash = std::hash<std::string>{}(edge.dest);
        size_t distHash = std::hash<double>{}(edge.dist);
        size_t validHash = std::hash<bool>{}(edge.valid);
        size_t seed = 0xdeadbeef;  // Optional: Seed the hash value

        // Combine the member hashes using XOR
        size_t combinedHash = destHash ^ distHash ^ validHash ^ seed;

        return combinedHash;
    }
};
#endif // MY_HEADER_FILE_H
