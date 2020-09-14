/**
 * Author:      Asif Ahmed
 * Site:        http://quickgrid.blogspot.com
 * Description: Inputting and Representing an Weighted Undirected graph
 *              in adjacency list vector list pair using C++ STL.
 */


#include<bits/stdc++.h>
using namespace std;
#define INF 2 << 22


class Graph{

private:
    int V;
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
    adjList[u].push_back( v );
}


void findPath(int startNode, int endNode, int* &parent){
    if( startNode == endNode || endNode == -1){
        printf("%d\n", startNode);
    }
    else{
        findPath(startNode, parent[endNode], parent);
        printf("%d\n", endNode);
    }
}


void Graph::BFS(int s){

    int *dist = new int[V];
    int *parent = new int[V];

    for(int v = 0; v < V; ++v){
        dist[v] = INF;
        parent[v] = -1;
    }

    dist[s] = 0;
    queue<int> Q;
    Q.push( s );


    while( !Q.empty() ){
        int u = Q.front();
        Q.pop();

        cout << u << " ";

        list<int>::iterator it;
        for(it = adjList[u].begin(); it != adjList[u].end(); ++it){
            if( dist[*it] == INF ){
                Q.push(*it);
                dist[*it] = dist[u] + 1;
                parent[*it] = u;
            }
        }
    }


    // Print all the reachable nodes with distance from current nodes
    printf("\n");
    for(int v = 0; v < V; ++v){
        if(dist[v] != INF){
            printf("%d -> %d: %d\n", s, v, dist[v]);
        }else{
            printf("%d -> %d: No Path\n", s, v);
        }
    }

    for(int v = 0; v < V; ++v){
        printf("parent of %d: %d\n", v, parent[v]);
    }

    findPath(2,1,parent);
}


int main(){

    //
    printf("Enter node count:\n");
    int n;
    scanf("%d", &n);

    // Create a graph given in the above diagram
    Graph *g = new Graph(n);


    // For inputting undirected graph either uncomment below or,
    // create Edges pointing from (u,v) and (v,u)
    int u, v;
    printf("Enter edges:\n");
    while( scanf("%d%d", &u, &v) == 2 ){
        g->addEdge(u,v);
        //g->addEdge(v,u);
    }


    // Run DFS on graph
    cout << "Breadth First Search Traversal: \n";
    g->BFS(2);





    return 0;
}
