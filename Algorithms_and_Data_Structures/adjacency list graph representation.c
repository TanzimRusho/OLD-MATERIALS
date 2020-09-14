/**
 * Author:    Asif Ahmed
 * Site:      https://quickgrid.wordpress.com
 * Problem:   UVA
 * Technique:
 */

#include<stdio.h>
#include<string.h>
#include<stdbool.h>


#define MAXV 1000


typedef struct{
    int y;                      // adjacency info
    int weight;                 // weight of the edge if any
    struct edgenode* next;      // pointer to next edge in list
} edgenode;


typedef struct{
    edgenode* edges[MAXV + 1];  // Adjacency info
    int degree[MAXV + 1];       // out degree of each vertex
    int nvertices;              // vertices count in graph
    int nedges;                 // edge count in graph
    bool directed;              // is graph directed
} graph;


void initialize_graph( graph* g, bool directed ){

    int i;

    g->nvertices = 0;
    g->nedges = 0;
    g->directed = directed;

    for( i = 1; i <= MAXV; ++i )
        g->degree[i] = 0;


    for( i = 1; i <= MAXV; ++i )
        g->edges[i] = NULL;
}



void insert_edge( graph* g, int x, int y, bool directed ){

    edgenode *p;    // temp pointer

    p = malloc( sizeof(edgenode) ); // allocate edge node storage

    p->weight = NULL;
    p->y = y;
    p->next = g->edges[x];

    g->edges[x] = p;

    g->degree[x] ++;

    if( directed )
        g->nedges ++;
    else
        insert_edge(g, y, x, true);
}



void read_graph( graph* g, bool directed ){

    int i;      // counter
    int m;      // no of edges
    int x, y;   // vertices in edge (x,y)

    initialize_graph(g, directed);

    printf("Enter vertices and edges:\n");
    scanf("%d %d", &(g->nvertices), &m );

    for( i = 1; i <= m; ++i ){
        scanf("%d %d", &x, &y);
        insert_edge( g, x, y, directed );
    }
}



void print_graph( graph* g ){

    int i;
    edgenode* p;

    for( i = 1; i <= g->nvertices; ++i){

        printf("%d: ", i);

        p = g->edges[i];
        while( p != NULL ){
            printf(" %d", p->y );
            p = p->next;
        }
        printf("\n");
    }

}


int main(){

    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);

    graph* g = malloc( sizeof(graph) );

    read_graph(g, true);
    print_graph(g);


    return 0;
}
