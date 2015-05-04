#include <iostream>
#include "graph.h"

using namespace std;

Graph::Graph()
{}

Graph::~Graph()
{}

void Graph::Print()
{
    for (unordered_map<string, EdgeNode*>::iterator item = edges_.begin();
        item != edges_.end(); ++item)
    {
        cout << "Vertex " << item->first << endl;
        EdgeNode* edge = item->second;
        while (edge != nullptr)
        {
            cout << edge->endpoint_ << " ";
            edge = edge->next_;
        }
        cout << endl;
    }
}

void Graph::InsertEdge(string start, string end, int weight)
{
    if (edges_.find(start) == edges_.end())
    {
        edges_[start] = nullptr;
    }
    
    InsertEdgeUtil(start, end, weight);
    
    if (directed_ == false)
        InsertEdgeUtil(end, start, weight);
}

void Graph::InsertEdgeUtil(string start, string end, int weight)
{
    EdgeNode* edge = new EdgeNode(end);
    edge->next_ = edges_[start];
    edges_[start] = edge;
}