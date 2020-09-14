#include<stdio.h>
#include<stdlib.h>

#define V 10

struct node{
    int v;
    struct node *next;
};

typedef struct node *link;

node *NEWNODE(int v, node *n){
    node *temp = new node();
    temp->v = v;
    temp->next = n;
    return temp;
}

int main(){
    int i, j;
    node *adj[V];

    for(i = 0; i < V; ++i)
        adj[i] = NULL;

    while(scanf("%d%d", &i, &j) == 2){
        adj[i] = NEWNODE(j, adj[i]);
        adj[j] = NEWNODE(i, adj[j]);
    }

    for(i = 0; i < V; ++i)
        printf("%d\n", adj[i]->next->v);

    return 0;
}
