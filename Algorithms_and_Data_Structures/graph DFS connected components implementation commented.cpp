/**
 * Author:      Asif Ahmed
 * Site:        http://quickgrid.blogspot.com
 * Description: Inputting and Representing unweighted graph in C++ STL vector lists.
 *              Easy implementation of Depth first search ( DFS ) with connected
 *              components count.
 */


#include<bits/stdc++.h>
using namespace std;


// Adjacency list representation of graph.
class Graph{

private:
    int V;
    int connectedComponentsCount;
    vector< list<int> > adjList;
    void DFSVisit(int const &v, bool* &visited);

public:
    Graph(int const &V);
    void addEdge(int const &u, int const &v);
    void DFS();
    int getConnectedComponentsCount();
};


// Initialize the graph with V nodes.
Graph::Graph(int const &V){
    this->V = V;
    adjList.resize(V);
}


// Push node v to the list of node u.
void Graph::addEdge(int const &u, int const &v){
    adjList[u].push_back(v);
}


// Keep an array to track visited nodes.
// If the node is not visited recursively visit it.
void Graph::DFSVisit(int const &v, bool* &visited){
    visited[v] = true;
    cout << v << " ";

    list<int>::iterator it;
    for( it = adjList[v].begin(); it != adjList[v].end(); ++it ){
        if( !visited[*it] ){
            DFSVisit(*it, visited);
        }
    }
}


// Fun for all nodes in the graph.
// The number of unvisited nodes here are the connected components of the graph.
void Graph::DFS(){

    connectedComponentsCount = 0;

    bool* visited = new bool[V];
    for(int v = 0; v < V; ++v){
        visited[v] = false;
    }

    for(int v = 0; v < V; ++v){
        if( !visited[v] ){
            ++connectedComponentsCount;
            DFSVisit(v, visited);
        }
    }
}


// Getter method to get the connected components count.
int Graph::getConnectedComponentsCount(){
    return connectedComponentsCount;
}



int main(){

    //
    printf("Enter node count:\n");
    int n;
    scanf("%d", &n);

    // Create a graph given in the above diagram
    Graph *g = new Graph(n);


    // Add u,v and v,u in input for undirected graph or,
    // uncomment the addeEdge(v,u) function call.
    int u, v;
    printf("Enter edges:\n");
    while( scanf("%d%d", &u, &v) == 2 ){
        g->addEdge(u,v);
        //g->addEdge(v,u);
    }


    // Run DFS on graph
    cout << "Depth First Search Traversal: \n";
    g->DFS();


    // Show connected components count
    cout << "\n";
    cout << "Connected Components Count: ";
    cout << g->getConnectedComponentsCount() << "\n";


    return 0;
}
