// #include <iostream>

#include "queue"
#include "search.h"

using namespace std;

Search::Search()
{}

Search::~Search()
{}

void Search::Initialize(const Graph &graph)
{
	for (unordered_map<string, EdgeNode*>::const_iterator edge = graph.edges_.begin();
		edge != graph.edges_.end(); ++edge)
	{
		string key = edge->first;
		discovered_[key] = false;
		processed_[key] = false;
		parents_[key] = "";
	}
}

void Search::Bfs(const Graph &graph, const string &start)
{
	queue<string> que;
	que.push(start);
	discovered_[start] = true;
	string u;
	string v;
	while (!que.empty())
	{
		u = que.front();
		que.pop();
		EdgeNode* edge = graph.edges_.at(u);
		while (edge != nullptr)
		{
			v = edge->endpoint_;
			if (!discovered_[v])
			{
				discovered_[v] = true;
				parents_[v] = u;
				que.push(v);
			}
			edge = edge->next_;
		}
		processed_[u] = true;
	}
}

void Search::Dfs(const Graph &graph, const string &start)
{
	string u = start;
	string v;
	EdgeNode* edge = graph.edges_.at(u);
	discovered_[start] = true;
	while (edge != nullptr)
	{
		v = edge->endpoint_;
		if (!discovered_[v])
		{
			discovered_[v] = true;
			parents_[v] = u;
			Dfs(graph, v);
		}
		edge = edge->next_;
	}
	processed_[start] = true;
}