/**
 * Author:    Asif Ahmed
 * Site:      https://quickgrid.wordpress.com
 * Problem:   UVA
 * Technique:
 */

#include<stdio.h>
#include<string.h>


#define MAX_NODES 1000


typedef struct edgenode{
    int name;                   // adjacency info
    int weight;                 // weight of the edge if any
    struct edgenode* next;      // pointer to next edge in list
};


typedef struct graph{
    edgenode* edges[MAX_NODES + 1];  // Adjacency info
    int degree[MAX_NODES + 1];       // out degree of each vertex
    int vertices_count;         // vertices count in graph
    int edge_count;             // edge count in graph
    bool directed;              // is graph directed
};


void initialize_graph( graph* g, bool directed ){

    g->vertices_count = 0;
    g->edge_count = 0;
    g->directed = directed;


    for( int i = 1; i <= MAX_NODES; ++i )
        g->degree[i] = 0;


    for( int i = 1; i <= MAX_NODES; ++i )
        g->edges[i] = NULL;
}



void insert_edge( graph* g, int u, int v, bool directed, int weight ){

    edgenode *p;    // temp pointer

    p = new edgenode(); // allocate edge node storage

    p->weight = weight;
    p->name = v;
    p->next = g->edges[u];

    g->edges[u] = p;

    g->degree[u] ++;

    if( directed )
        g->edge_count ++;
    else
        insert_edge(g, v, u, true, weight);
}



void read_graph( graph* g, bool directed ){

    int edges;  // no of edges
    int u, v, w;   // u (current node), v (next node)

    bool weighted;

    initialize_graph(g, directed);


    printf("Enter vertices, edges, unweighted(0):\n");
    scanf("%d %d %d", &(g->vertices_count), &edges, &weighted );


    if( weighted ){
        for( int i = 1; i <= edges; ++i ){
            scanf( "%d %d %d", &u, &v, &w );
            insert_edge( g, u, v, directed, w );
        }
    }
    else{
        for( int i = 1; i <= edges; ++i ){
            scanf( "%d %d", &u, &v );
            insert_edge( g, u, v, directed, NULL );
        }
    }

}



void print_graph( graph* g ){

    edgenode* v;

    for( int u = 1; u <= g->vertices_count; ++u ){

        printf("%d: ", u);

        v = g->edges[u];

        while( v != NULL ){
            printf(" %d", v->name );
            v = v->next;
        }
        printf("\n");
    }

}


int main(){

    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);


    graph* g = new graph();


    read_graph(g, true);
    print_graph(g);


    return 0;
}
