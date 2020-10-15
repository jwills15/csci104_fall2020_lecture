#include <iostream>
#include <vector>
using namespace std;



struct Edge {
int node_label;
int weight;
Edge(int n, int w) : node_label(n), weight(w) {}
};

class DirectedGraph {
public:
/* There is no default constructor. Once the graph is created with n nodes,
no nodes will be added or deleted. */
DirectedGraph(int n); // constructor
~DirectedGraph (); // destructor

void addEdge(int start, int end, int weight);
/* adds a directed edge from start to end in the graph and runs in O(1)
Duplicate edges are fine. Your code does not need to check if an edge
already exists before adding it. */

void countEdges(int node_label, int &outd, int &ind) const;
// Returns the outdegree and indegree of vertex with node_label in O(d)
// where d = max(indegree,outdegree)

DirectedGraph transpose();
/* The transpose of this graph has all of the edges with directions reversed.
This should run in O(|V|+|E|). For example, if the graph pointed to by the this pointer
contains the edge (1,3), the graph object returned should have the edge (3,1).
The edge weights would be the same in both graphs.*/



private:
// feel free to add private member variables or functions
// You should use STL vector, vector<BLANK>, but what should the BLANK be?
vector<vector<Edge>> in_list;
vector<vector<Edge>> out_list;
int nodes;

};

DirectedGraph::DirectedGraph(int n) {
    for (int i = 0; i < n; ++i) {
        out_list.push_back(vector<Edge>());
        in_list.push_back(vector<Edge>());
    }
    nodes = n;
}

DirectedGraph::~DirectedGraph() {}

void DirectedGraph::addEdge(int start, int end, int weight) {
    if (start < 1 || end < 1 || start > nodes || end > nodes) return;

    in_list[end - 1].push_back(Edge(start, weight));
    out_list[start - 1].push_back(Edge(end, weight));
}

void DirectedGraph::countEdges(int node_label, int& outd, int& ind) const {
    outd = 0;
    ind = 0;
    if (node_label > nodes || node_label < 1) return;

    outd = out_list[node_label - 1].size();
    ind = in_list[node_label - 1].size();
}

DirectedGraph DirectedGraph::transpose() {
    DirectedGraph output(this->nodes);
    output.in_list = out_list;
    output.out_list = in_list;
    return output;
}


int main()
{
    
    DirectedGraph triangle(3);
    triangle.addEdge(1,2, 5);
    triangle.addEdge(2,3, 10);
    triangle.addEdge(3,1,15);
    DirectedGraph reversed = triangle.transpose();
   
    return 0;


}

