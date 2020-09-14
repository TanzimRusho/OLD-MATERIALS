/*
 * Author:   Quickgrid ( Asif Ahmed )
 * Site:     https://quickgrid.wordpress.com
 * Problem:  UVA
 * Solution:
 */

#include<cstdio>
#include<iostream>
#include<algorithm>
#include<vector>
#include<set>


using namespace std;


static const int ALLOWABLE_NODE_COUNT = 50;
static const int INFINITY = 999;


int W[ALLOWABLE_NODE_COUNT][ALLOWABLE_NODE_COUNT];
int d[ALLOWABLE_NODE_COUNT];
int pi[ALLOWABLE_NODE_COUNT];


int no_of_vertices, no_of_edges;


void inputGraph(){

    // Input vertices and edge count
    printf("Enter vertices and edge count:\n");
    scanf("%d %d", &no_of_vertices, &no_of_edges);


    // Reset the weights
    for(int u = 0; u < no_of_vertices; ++u)
        for(int v = 0; v < no_of_vertices; ++v)
            W[u][v] = 0;


    int u, v, w;


    // Make connections between nodes or vertices
    for(int i = 0; i < no_of_edges; ++i){

        printf("Enter u (node), v (node) and w (edge weight). Ex: 1 2 5\n");
        scanf("%d%d%d", &u, &v, &w);

        // Using undirected graph
        W[u][v] = w;
        W[v][u] = w;

    }


}


void displayGraph(){

  for(int u = 0; u < no_of_vertices; ++u){
    for(int v = 0; v < no_of_vertices; ++v)
        printf("%d ", W[u][v]);
    printf("\n");
  }

}


void displayArrays(){

    int v;

    printf("d Array:\n");
	for(v = 0; v < no_of_vertices; ++v)
        printf("%d : ", d[v]);
    printf("\n");


    printf("PI Array:\n");
    for(v = 0; v < no_of_vertices; ++v)
        printf("%d : ", pi[v]);
    printf("\n");
}


void  relax(int u, int v){

    if( d[v] > d[u] + W[u][v] ){
        d[v] = d[u] + W[u][v];
        pi[v] = u;
    }

}


void initSingleSource(int s){

    for(int v = 0; v < no_of_vertices; ++v){
        d[v] = INFINITY;
        pi[v] = -1;
    }

    d[s] = 0;

}


void dijkstra(){

    set< pair<int,int> > PQ;


    int source;
    printf("Enter starting / Source Node:\n");
    scanf("%d", &source);


    initSingleSource( source );


    for(int v = 0; v < no_of_vertices; ++v)
        PQ.insert( pair<int,int>(v, d[v]) );


    while( !PQ.empty() ){

        int u = PQ.begin()->first;
        PQ.erase( PQ.begin() );

        for(int v = 0; v < no_of_vertices; ++v){
            if( W[u][v] ){

                if( PQ.find( pair<int,int>(v, d[v]) ) != PQ.end() ){
                    PQ.erase( PQ.find( pair<int,int>(v, d[v]) ) );
                    relax(u, v);
                    PQ.insert( pair<int,int>(v, d[v]) );
                }

            }
        }
    }

}


void printPath(int v){

    if( pi[v] != -1 ){
        printPath( pi[v] );
        printf("-> %d ", v);
    }
    else printf("%d ", v);

}


int main(){


    inputGraph();

    dijkstra();

    displayGraph();
    displayArrays();

    for(int v = 0; v < no_of_vertices; ++v){
        printPath(v);
        printf("\n");
    }


    return 0;
}
