/**
 * Author:      Asif Ahmed
 * Site:        http://quickgrid.blogspot.com
 * Description: Inputting and Representing an Weighted Undirected graph
 *              in adjacency list vector list pair using C++ STL.
 */


#include<bits/stdc++.h>
using namespace std;


class Graph{

private:
    int V;
    list<int> *adj;
    void DFSUtil(int v, bool* &visited);

public:
    Graph(int V);
    void addEdge(int v, int u);
    void DFS();
};


Graph::Graph(int V){
    this->V = V;
    adj = new list<int>[V];
}

void Graph::addEdge(int v, int u){
    adj[v].push_back(u);
}

void Graph::DFSUtil(int v, bool* &visited){
    visited[v] = true;
    cout << v << " ";

    list<int>::iterator it;
    for( it = adj[v].begin(); it != adj[v].end(); ++it ){
        if( !visited[*it] ){
            DFSUtil(*it, visited);
        }
    }
}


void Graph::DFS(){
    bool * visited = new bool[V];
    for(int v = 0; v < V; ++v){
        visited[v] = false;
    }

    for(int v = 0; v < V; ++v){
        if( !visited[v] ){
            DFSUtil(v, visited);
        }
    }
}


int main(){

// Create a graph given in the above diagram

    Graph g(4);
    g.addEdge(0, 1);
    g.addEdge(0, 2);
    g.addEdge(1, 2);
    g.addEdge(2, 0);
    g.addEdge(2, 3);
    g.addEdge(3, 3);

    cout << "Following is Depth First Traversal\n";
    g.DFS();

    return 0;
}
