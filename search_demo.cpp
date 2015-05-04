#include <iostream>
#include "search.h"

using namespace std;

int main(int argc, char** argv)
{
    Graph graph;
    graph.InsertEdge("A", "B");
    graph.InsertEdge("A", "C");
    graph.InsertEdge("B", "D");
    graph.Print();
    
    Search search;
    
    search.Initialize(graph);
    search.Bfs(graph, "A");
    for (unordered_map<string, string>::iterator item = search.parents_.begin();
    	item != search.parents_.end(); ++item)
	    cout << item->first << ":" << item->second << endl;

    search.Initialize(graph);
    search.Dfs(graph, "A");
    for (unordered_map<string, string>::iterator item = search.parents_.begin();
    	item != search.parents_.end(); ++item)
	    cout << item->first << ":" << item->second << endl;

    return 0;
}
