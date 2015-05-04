// Search.h

#include <string>
#include <unordered_map>
#include "graph.h"

class Search
{
public:
	Search();
	~Search();
	void Initialize(const Graph &graph);
	void Bfs(const Graph &graph, const std::string &start);
	void Dfs(const Graph &graph, const std::string &start);
	std::unordered_map<std::string, bool> discovered_;
	std::unordered_map<std::string, bool> processed_;
	std::unordered_map<std::string, std::string> parents_;
};