#include<cstdio>
#include<iostream>
#include<climits>
#include<set>

#define SIZE 1000

#define PriorityQueue set< pair<int, int> >


int W[SIZE][SIZE];
int key[SIZE];
int pi[SIZE];


int u, v, w;
int i, j;
int vertices, edges;

int source;

using namespace std;

void InputGraph(){
    scanf("%d%d", &vertices, &edges);

    for(i = 0; i < vertices; ++i)
        for(j = 0; j < vertices; ++j)
            W[i][j] = 0;

    for(i = 0; i < edges; ++i){
        scanf("%d%d%d",&u, &v, &w);
        W[u][v] = w;
        W[v][u] = w;
    }
}

void ResetValues(){
    for(int i = 0; i < vertices; ++i){
		pi[i] = -1;
		key[i] = INT_MAX;
	}
}

int main()
{
    InputGraph();
    ResetValues();

	PriorityQueue Q;
    /* now initialize prim algorithm */
	for(int i = 0; i < vertices; ++i)
		Q.insert( pair<int, int> (key[i], i) );

    printf("Input source vertex:\n");
	scanf("%d", &source);

	Q.erase( Q.find( pair<int,int> (INT_MAX, source) ) );
	Q.insert( pair<int, int>(0, source));


	cout << "The MST:\n" << endl;
	int cost = 0;

	while(!Q.empty())
    {
		u = Q.begin()->second;
		Q.erase(Q.begin());

		if(u != source)
		{
			cout << pi[u] << " "<< u << endl;
			cost += W[pi[u]][u];
		}

		for(v = 0; v < vertices; ++v)
		{
			if(W[u][v])
			{
				if(Q.find( pair<int, int>(key[v],v)) != Q.end() && W[u][v] < key[v])
				{
					pi[v] = u;
					Q.erase(Q.find(pair<int, int>(key[v],v)));
					key[v] = W[u][v];
					Q.insert(pair<int, int>(key[v],v));
				}
			}
		}
	}
	cout << "The cost was: " << cost<<endl;


    return 0;
}
