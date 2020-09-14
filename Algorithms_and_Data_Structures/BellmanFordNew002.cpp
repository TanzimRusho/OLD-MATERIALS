#include<stdio.h>

#define N 100

int W[N][N];
int pi[N];
int d[N];

int vertices, edges;
int u, v, w;
int i, j;
int source;
int node;

void InputGraph(){
    printf("Enter vertices and Edges:\n");
    scanf("%d%d", &vertices, &edges);

    // Reset graph
    for(i = 0; i < vertices; ++i)
        for(j = 0; j < vertices; ++j)
            W[i][j] = 0;

    // Input Graph
    printf("Enter (u v w):\n");
    for(i = 0; i < edges; ++i){
        scanf("%d%d%d", &u, &v, &w);
        W[u][v] = w;
    }
}

void PrintGraph(){
    // Print the current Graph
    printf("Graph:\n");
    for(i = 0; i < vertices; ++i){
        for(j = 0; j < vertices; ++j)
            printf("%d ", W[i][j]);
        printf("\n");
    }
    printf("\n");
}

void InitSingleSource(){
    for(i = 0; i < vertices; ++i){
        //Set infinity
        d[i] = 9999;
        pi[i] = -1;
    }

    printf("Enter Source:\n");
    scanf("%d", &source);

    d[source] = 0;
}

void Relax(int u, int v){
    // If distance is smaller then update the distance
    if(d[v] > d[u] + W[u][v]){
        d[v] = d[u] + W[u][v];
        pi[v] = u;
    }
}

int BellmanFord(){
    // Initialize distance and pi array
    InitSingleSource();

    // Distance Calculation
    for(i = 0; i < vertices - 1; ++i){
        for(u = 0; u < vertices; ++u){
            for(v = 0; v < vertices; ++v){
                if(W[u][v])
                    Relax(u, v);
            }
        }
    }

    // Negative Cycle Check
    for(u = 0; u < vertices; ++u){
        for(v = 0; v < vertices; ++v){
            if(W[u][v]){
                if(d[v] > d[u] + W[u][v]){
                    // False
                    node = u;
                    return 0;
                }
            }
        }
    }

    // True
    return 1;
}


void PrintPath(int v){
    if(pi[v] != -1){

        if(pi[v] == node)
            return;

        PrintPath(pi[v]);
        printf("-> %d ", v);
    }
    else printf("%d ", v);
}

void PrintPath2(int v){
    printf("%d ", v);
    if(pi[v] != -1){

        if(v == node)
            return;

        PrintPath(pi[v]);
        printf("-> %d ", v);
    }
}

int main(){
    InputGraph();
    PrintGraph();

    // Return True or False
    if(BellmanFord()){
        printf("No Negative Cycle\n");
    }else{
        printf("Negative Cycle\n");

        /*
        for(i = 0; i < vertices; ++i){
            PrintPath(i);
            printf("\n");
        }
        */


        //cycle(vertices-1);
        //PrintPath(node);
        //PrintPath2(vertices - 1);
        PrintPath2(source);
    }

    printf("\nPI Array:\n");
    for(i = 0; i < vertices; ++i)
        printf("%d ", pi[i]);
    printf("\n");

    /*
    printf("\nd Array:\n");
    for(i = 0; i < vertices; ++i)
        printf("%d ", d[i]);
    printf("\n");
    */




    return 0;
}
