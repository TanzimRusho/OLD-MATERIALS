/**
 * Author:      Asif Ahmed
 * Site:        http://quickgrid.blogspot.com
 * Solution:    vector of vector oop graph representation and operation.
 * Task:        Input directed graph, find out connected component count,
 *              print out unreachable nodes.
 * Note:        Input node is from 1 to 100. So, here it is 0 to 99 to
 *              keep it simple.
 */


#include<bits/stdc++.h>
using namespace std;


// The whole graph structure look at my graph
// related posts for visualization of this structure.
class Graph{

private:
    int V;
    int connectedComponentsCount;
    vector< vector<int> > adjList;

public:
    Graph(int V);
    void addEdge(int u, int v);
    void BFS(int s);
};


Graph::Graph(int V){
    this->V = V;
    adjList.resize(V);
}


// Since start node is from 0 in current structure.
// So, 1 is turned into 0 here.
void Graph::addEdge(int u, int v){
    adjList[u - 1].push_back(v - 1);
}


// BFS Algorithm
void Graph::BFS(int s){

    // Initialize an array with all nodes unvisited.
    bool *visited = new bool[V];
    for(int v = 0; v < V; ++v){
        visited[v] = false;
    }

    // Insert the given node to run BFS.
    queue<int> Q;
    Q.push(s);


    // Get the front of the queue and check all its adjacent nodes if
    // they were visited. If not mark them visited and push the unvisited
    // node to the queue.
    int node;
    while(!Q.empty()){
        node = Q.front();
        Q.pop();

        for(int v = 0; v < adjList[node].size(); ++v){
            if( !visited[ adjList[node][v] ] ){
                visited[ adjList[node][v] ] = true;
                Q.push( adjList[node][v] );
            }
        }
    }


    // Count the number of connected components in graph and print.
    int connectedComponentsCount = 0;
    for(int v = 0; v < V; ++v){
        if(!visited[v])
            connectedComponentsCount++;
    }
    printf("%d", connectedComponentsCount);


    // Print all the unreachable nodes from the given node. Since, BFS
    // on the start node already filled up the array now just print all
    // the unvisited node.
    for(int v = 0; v < V; ++v){
        if(!visited[v])
            printf(" %d", v + 1);
    }
    printf("\n");

}


int main(){

    // Create the graph in given linked list format.
    int n;
    while( scanf("%d", &n) && n ){

        // Initialize the new graph with node count.
        Graph *g = new Graph(n);

        // Connect node u with given v nodes to create an edge.
        int u,v;
        while( scanf("%d", &u) && u ){
            while( scanf("%d", &v) && v ){
                g->addEdge(u,v);
            }
        }

        // Take input of the nodes where to run the custom BFS algorithm.
        int c, node;
        scanf("%d", &c);
        for(int i = 0; i < c; ++i){
            scanf("%d", &node);
            g->BFS(node - 1);
        }

    }


    return 0;
}
