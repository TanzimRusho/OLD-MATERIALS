#include<cstdio>
#include<iostream>
#include<climits>
#include<set>
#define SIZE 1000

#define keyValue pair<int,char>
#define PriorityQueue set<keyValue>


int W[SIZE][SIZE];
int key[SIZE];
int pi[SIZE];

using namespace std;
int main()
{
    int u,v,w,i=0,j=0,no_of_vertices=-1,no_of_edges=-1;

    /*take the graph as input*/
    scanf("%d%d", &no_of_vertices, &no_of_edges);

    for(i = 0;i < no_of_vertices; ++i)
        for(j = 0;j < no_of_vertices; ++j)
            W[i][j] = 0;

    for(i = 0;i < no_of_edges; ++i){
        scanf("%d%d%d",&u, &v, &w);
        W[u][v] = w;
        W[v][u] = w;
    }


	PriorityQueue Q;
    /* now initialize prim algorithm */
	for(int i = 0; i < no_of_vertices; ++i){
		pi[i] = -1;
		key[i] = INT_MAX;
		Q.insert(keyValue(key[i], i));
	}
	int source = 6;

	Q.erase(Q.find(keyValue(INT_MAX, source)));
	Q.insert(keyValue(0, source));


	cout << "The MST " << endl;
	int cost = 0;
	while(!Q.empty())
    {
		int u = Q.begin()->second;
		Q.erase(Q.begin());
		if(u!=source)
		{
			cout << pi[u] << " "<< u << endl;
			cost += W[pi[u]][u];
		}

		for(int v = 0; v < no_of_vertices; ++v)
		{
			if(W[u][v])
			{

				if(Q.find(keyValue(key[v],v)) != Q.end()
					&& W[u][v] <key[v])
				{
					pi[v] = u;
					Q.erase(Q.find(keyValue(key[v],v)));
					key[v] = W[u][v];
					Q.insert(keyValue(key[v],v));

				}
			}
		}
	}
	cout << "The cost was: " << cost<<endl;



    return 0;
}
