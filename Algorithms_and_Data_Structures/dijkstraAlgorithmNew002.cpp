#include<cstdio>
#include<iostream>
#include<climits>
#include<set>
#define SIZE 1000

#define keyValue pair<int,int>
#define PriorityQueue set<keyValue>


int W[SIZE][SIZE];
int d[SIZE];
int pi[SIZE];
int vertex[SIZE];

int u, v, w;
int i, j;
int no_of_vertices = -1, no_of_edges = -1;

int source = 0;

using namespace std;

void InputGraph(){
    /*take the graph as input*/
    scanf("%d%d", &no_of_vertices, &no_of_edges);

    /*
     * Reset graph
     */
    for(i = 0; i < no_of_vertices; ++i)
        for(j = 0; j < no_of_vertices; ++j)
            W[i][j] = 0;

    /*
     * Input weight in 2D matrix
     */
    for(i = 0; i < no_of_edges; ++i){
        scanf("%d%d%d", &u, &v, &w);
        W[u][v] = w;
        //W[v][u] = w;
    }
}

void InitSingleSource(){
    /* now initialize prim algorithm */
    for(i = 0; i < no_of_vertices; ++i){
		// 999 since any other value becomes unsigned
		d[i] = 999;
		pi[i] = -1;
    }
	d[source] = 0;
}

void Relax(int u, int v){
    if( d[v] > d[u] + W[u][v] ){
        d[v] = d[u] + W[u][v];
        pi[v] = u;
    }
}

void PrintPath(int v){
    if(pi[v] != -1){
        PrintPath(pi[v]);
        printf("-> %d ", v);
    }
    else printf("%d ", v);
}

int main()
{
    PriorityQueue Q;

    InputGraph();
    InitSingleSource();

    for(i = 0; i < no_of_vertices; ++i)
        Q.insert(keyValue(d[i], i));

    int cost = 0;
	cout << "The MST:" << endl;

	while(!Q.empty())
    {
		int u = Q.begin()->second;
		Q.erase(Q.begin());

		for(int v = 0; v < no_of_vertices; ++v)
		{
			if(W[u][v]){
				if( Q.find(keyValue(d[v], v)) != Q.end() ){
					Q.erase(Q.find(keyValue(d[v],v)));
					Relax(u, v);
					Q.insert(keyValue(d[v],v));
				}
			}
		}
	}

    /**
     * Print d and PI array
     */
    printf("\nd Array:\n");
	for(v = 0; v < no_of_vertices; ++v)
        printf("%d : ", d[v]);
    printf("\n");
    printf("\nPI Array:\n");
    for(v = 0; v < no_of_vertices; ++v)
        printf("%d : ", pi[v]);
    printf("\n\n");


    printf("With Integer:\n");
    for(v = 0; v < no_of_vertices; ++v){
        PrintPath(v);
        printf("\nCost:%d\n", d[v]);
        printf("\n");
    }

    return 0;
}
