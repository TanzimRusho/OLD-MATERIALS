#include<cstdio>
#include<iostream>
#include<set>
#include<climits>
#include<algorithm>

#define SIZE 1000

#define KeyValue pair<int,int>
#define PriorityQueue set<KeyValue>

struct node{
    int u, v;
    int w;
} nodes[SIZE];

using namespace std;

int W[SIZE][SIZE];
int pi[SIZE];
int key[SIZE];
int Output[SIZE];

int main()
{
    int u, v, w;
    int i = 0, j = 0;
    int no_of_vertices = -1, no_of_edges = -1;

    /*take the graph as input*/
    cout << "How many vertices?\n";
    cin >> no_of_vertices;
    cout << "How many edges?\n";
    cin >> no_of_edges;

    for(i = 0; i < no_of_vertices; i++)
        for(j = 0; j < no_of_vertices; j++)
            W[i][j] = 0;

    printf("Enter Connection:\n");
    for(i = 0; i < no_of_edges; i++){
        cin >> u >> v >> w;
        W[u][v] = w;
        W[v][u] = w;
        nodes[i].u = u;
        nodes[i].v = v;
        nodes[i].w = w;
    }

    for(i = 0; i < no_of_edges; ++i){
        for(j = i + 1; j < no_of_edges; ++j){
            if(nodes[i].w > nodes[j].w){
                struct node temp = nodes[i];
                nodes[i] = nodes[j];
                nodes[j] = temp;
            }
        }
    }

    for(i = 0; i < no_of_edges; ++i)
        printf("nodes: %d - %d : %d\n", nodes[i].u, nodes[i].v, nodes[i].w);

    for(i = 0; i < no_of_edges; ++i){
        for(j = i + 1; j < no_of_edges; ++j){
            if(nodes[i].u != nodes[j].v){
                Output[i] = W[i][j];
                nodes[u].w = nodes[v].w = W[i][j];
            }
        }
    }

    int sum = 0;
    printf("Main Output:\n");
    for(i = 0; i < no_of_edges; ++i){
        printf("nodes: %d - %d : %d\n", nodes[i].u, nodes[i].v, nodes[i].w);
        sum += nodes[i].w;
    }

    printf("\nSum: %d\n", sum);

    return 0;
}
