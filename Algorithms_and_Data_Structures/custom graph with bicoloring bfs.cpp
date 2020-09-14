/**
 * Author:    Asif Ahmed
 * Site:      https://quickgrid.wordpress.com
 * Problem:   UVA
 * Technique:
 */

#include<cstdio>
#include<cstring>
#include<queue>
using namespace std;

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
    int edge_count;             // edge count in[ graph
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



void insert_edge( graph* g, int u, int v, bool directed ){

    edgenode *temp = new edgenode(); // allocate edge node storage

    temp->weight = NULL;
    temp->name = v;

    temp->next = g->edges[u];
    g->edges[u] = temp;

    g->degree[u] ++;

    if( directed )
        g->edge_count ++;
    else
        insert_edge(g, v, u, true);
}



void read_graph( graph* g, bool directed ){

    int edges;  // no of edges
    int u, v, w;   // u (current node), v (next node)

    bool weighted;

    initialize_graph(g, directed);


    printf("Enter vertices and edges count:\n");
    scanf("%d %d", &(g->vertices_count), &edges );


    for( int i = 1; i <= edges; ++i ){
        scanf( "%d %d", &u, &v );
        insert_edge( g, u, v, directed );
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
    printf("\n");

}


#define UNCOLORED 0
#define WHITE 1
#define BLACK 2


int color[3];
bool bipertite = false;


bool discovered[MAX_NODES + 1];
bool processed[MAX_NODES + 1];
int  parent[MAX_NODES + 1];



void initialize_search( graph* g ){

    for( int i = 0; i <= g->vertices_count; ++i ){
        processed[i] = false;
        discovered[i] = false;
        parent[i] = -1;
    }

}


void clear( queue<int> &q )
{
   queue<int> empty;
   swap( q, empty );
}


int complement( int color ){

    if( color == WHITE )
        return (BLACK);
    if( color == BLACK )
        return (WHITE);

    return UNCOLORED;

}


void process_edge(int u, int v){

    if( color[u] == color[v] ){
        bipertite = false;
        printf("NOT BIPERTITE: (%d,%d)\n", u, v);
    }

    color[v] = complement( color[u] );
}


void bfs( graph* g, int start ){

    queue<int> q;
    clear(q);

    int u;
    int v;
    edgenode* temp;

    q.push(start);
    discovered[start] = true;


    while( !q.empty() ){

        u = q.front();
        q.pop();

        printf("Processing: %d\n", u);

        processed[u] = true;

        temp = g->edges[u];

        while( temp != NULL ){
            v = temp->name;

            if( processed[v] == false || g->directed )
                process_edge(u,v);

            if( discovered[v] == false ){
                q.push( v );
                discovered[v] = true;
                parent[v] = u;
            }
            temp = temp->next;
        }

    }

}



void two_color( graph* g ){

    for(int i = 1; i <= g->vertices_count; ++i)
        color[i] = UNCOLORED;

    bipertite = true;

    initialize_search( g );

    for(int i = 1; i <= g->vertices_count; ++i){
        if( discovered[i] == false ){
            color[i] = WHITE;
            bfs(g,i);
        }
    }

}



int main(){

    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);


    graph* g = new graph();


    read_graph(g, true);
    print_graph(g);


    printf("\n");
    two_color(g);


    return 0;
}
