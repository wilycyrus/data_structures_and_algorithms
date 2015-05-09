//
// Find the number of edges that transform the graph to a forest of trees with
// the even number of vertices whey they are removed from the graph
//

#include <iostream>

using namespace std;

#define MAX_VERTICES    100

int result = 0;

struct EdgeNode {
    int endpoint;
    EdgeNode* next;
};

struct Graph {
    int n_vertices;
    EdgeNode* edges[MAX_VERTICES + 1];
};

void insert_edge(Graph* g, int x, int y, bool directed) {
    EdgeNode* edge = new EdgeNode();
    edge->endpoint = y;
    edge->next = g->edges[x];
    g->edges[x] = edge;
    if (!directed) {
        insert_edge(g, y, x, true);
    }
}

void print_graph(Graph* g) {
    for (int i = 1; i <= g->n_vertices; ++i) {
        EdgeNode* edge = g->edges[i];
        while (edge != nullptr) {
            cout << edge->endpoint << " ";
            edge = edge->next;
        }
        cout << endl;
    }
}

int count_vertices(Graph* g, int vertex, int parent) {
    // if this vertex has only one edge to its parent...
    if (g->edges[vertex]->endpoint == parent &&
        g->edges[vertex]->next == nullptr) {
        return 1;
    } else {
        int sum = 0;
        EdgeNode* edge = g->edges[vertex];
        while (edge != nullptr) {
            if (edge->endpoint != parent) {
                sum += count_vertices(g, edge->endpoint, vertex);
            }
            edge = edge->next;
        }
        sum += 1;
        
        // if even size subtree and not the root...
        if (sum % 2 == 0 && parent != 0) {
            ++result;
        }
        return sum;
    }
}

void init_graph(Graph* g, bool directed) {
    for (int i = 1; i <= MAX_VERTICES; ++i) {
        g->edges[i] = nullptr;
    }
}

int main() {
    int n_vertices, n_edges;
    cin >> n_vertices >> n_edges;

    Graph g;
    g.n_vertices = n_vertices;
    bool directed = false;
    init_graph(&g, directed);
    
    for (int i = 0; i < n_edges; ++i) {
        int u, v;
        cin >> u >> v;
        insert_edge(&g, u, v, directed);
    }

    int count = count_vertices(&g, 1, 0);
    cout << result << endl;

    return 0;
}