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
    int connectedComponentsCount;
    vector< list<int> > adjList;
    void DFSVisit(int v, bool* &visited);

public:
    Graph(int V);
    void addEdge(int u, int v);
    void DFS();
    int getConnectedComponentsCount();
};


Graph::Graph(int V){
    this->V = V;
    adjList.resize(V);
}

void Graph::addEdge(int u, int v){
    adjList[u].push_back(v);
}

void Graph::DFSVisit(int v, bool* &visited){
    visited[v] = true;
    cout << v << " ";

    list<int>::iterator it;
    for( it = adjList[v].begin(); it != adjList[v].end(); ++it ){
        if( !visited[*it] ){
            DFSVisit(*it, visited);
        }
    }
}


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


    // For undirected graph
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
