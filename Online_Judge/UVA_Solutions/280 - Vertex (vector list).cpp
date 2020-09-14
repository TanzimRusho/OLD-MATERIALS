/**
 * Author:      Asif Ahmed
 * Site:        http://quickgrid.blogspot.com
 * Solution:    vector of list oop graph representation and operation.
 * Task:        Input directed graph, find out connected component count,
 *              print out unreachable nodes.
 * Note:        Input node is from 1 to 100. So, here it is 0 to 99 to
 *              keep it simple.
 */


#include<bits/stdc++.h>
using namespace std;


// The adjacency list is now vector of list.
class Graph{

private:
    int V;
    int connectedComponentsCount;
    vector< list<int> > adjList;

public:
    Graph(int V);
    void addEdge(int u, int v);
    void BFS(int s);
};


Graph::Graph(int V){
    this->V = V;
    adjList.resize(V);
}

void Graph::addEdge(int u, int v){
    adjList[u - 1].push_back(v - 1);
}

void Graph::BFS(int s){
    bool *visited = new bool[V];
    for(int v = 0; v < V; ++v){
        visited[v] = false;
    }

    queue<int> Q;
    Q.push(s);

    int node;
    while(!Q.empty()){
        node = Q.front();
        Q.pop();


        // Only change here to iterate the current node and see if its
        // connected nodes are visited or not.
        list<int>::iterator it;
        for( it = adjList[node].begin(); it != adjList[node].end(); ++it ){
            if( !visited[ *it ] ){
                visited[ *it ] = true;
                Q.push( *it );
            }
        }
    }

    int connectedComponentsCount = 0;

    for(int v = 0; v < V; ++v){
        if(!visited[v])
            ++connectedComponentsCount;
    }

    printf("%d", connectedComponentsCount);

    for(int v = 0; v < V; ++v){
        if(!visited[v])
            printf(" %d", v + 1);
    }
    printf("\n");

}


int main(){

    //
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);


    //
    int n;
    while( scanf("%d", &n) && n ){

        // Create a graph given in the above diagram
        Graph *g = new Graph(n);

        int u,v;
        while( scanf("%d", &u) && u ){
            while( scanf("%d", &v) && v ){
                g->addEdge(u,v);
            }
        }


        int c, node;
        scanf("%d", &c);
        for(int i = 0; i < c; ++i){
            scanf("%d", &node);
            g->BFS(node - 1);
        }

    }


    return 0;
}
