#include<bits/stdc++.h>
using namespace std;


// contains adjacent node name and weight
typedef pair<int, int> vertex;


int main(){

    printf("Enter number of nodes:\n");
    int v;
    cin >> v;

    vector< vector<vertex> > adjList(v);

    printf("%d\n", adjList.size());


    int edges;
    cin >> edges;

    // For undirected graph
    int source, dest, weight;
    for(int i = 0; i < 2 * edges; ++i){
        cin >> source >> dest >> weight;
        vertex vet(dest, weight);
        adjList[source].push_back(vet);
    }


    for(int i = 0; i < v; ++i){

        int adjNodes = adjList[i].size();
        printf("Adjacent of: %d", i);

        if(adjNodes > 0){
            for(int j = 0; j < adjNodes; ++j){
                printf(" -> %d (w:%d)", adjList[i][j].first, adjList[i][j].second);
            }
            printf("\n");
        }
    }


    return 0;
}
