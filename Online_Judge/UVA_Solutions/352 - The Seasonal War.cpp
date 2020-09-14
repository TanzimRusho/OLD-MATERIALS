/**
 * Author:      Asif Ahmed
 * Site:        http://quickgrid.blogspot.com
 * Description: Find out number of connected components.
 */


#include<bits/stdc++.h>
using namespace std;
#define M 26


static int picture[M][M];
static bool visited[M][M];
static char temp[M];
int n;


// Check all 8 direction co-ordinates.
// N, NE, E, SE, S, SW, W, NW
static int dr[] = {-1, -1, 0, 1, 1, 1, 0, -1};
static int dc[] = {0, 1, 1, 1, 0, -1, -1, -1};



// DFS visit. Call on each node that has node been visited.
// This code below traverses all the nodes connected with given node.
void visit(int i, int j){
    visited[i][j] = true;

    for( int k = 0; k < 8; ++k ){
        if( i + dr[k] >= 0 && i + dr[k] < n && j + dc[k] >= 0 && j + dc[k] < n ){
            int ti = i + dr[k];
            int tj = j + dc[k];
            if( !visited[ti][tj] && picture[ti][tj] ){
                visit(ti, tj);
            }
        }
    }

}


int main(){

    //
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);

    //
    int c = 0;
    while(scanf("%d", &n) == 1){
        getchar();

        for(int i = 0; i < n; ++i){
            scanf("%s", temp);
            for(int j = 0; j < n; ++j){
                picture[i][j] = temp[j] - '0';
                visited[i][j] = false;
            }
        }


        // DFS
        // Call for each of the nodes in 2D graph that has not been visited by DFS visit.
        // The number of unvisited nodes here is the connected component count.
        int connectedComponents = 0;
        for( int i = 0; i < n; ++i ){
            for( int j = 0; j < n; ++j ){
                if( !visited[i][j] && picture[i][j] ){
                    ++connectedComponents;
                    visit(i,j);
                }
            }
        }

        printf("Image number %d contains %d war eagles.\n", ++c, connectedComponents);

    }

    return 0;
}
