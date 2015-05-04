// Graph.h

#include <unordered_map>
#include "edge_node.h"

class Graph
{
public:
    Graph();
    ~Graph();
    void Print();
    void InsertEdge(std::string start, std::string end, int weight = 1);
    std::unordered_map<std::string, EdgeNode*> edges_;
    bool directed_ = false;
private:
	void InsertEdgeUtil(std::string start, std::string end, int weight);
};
