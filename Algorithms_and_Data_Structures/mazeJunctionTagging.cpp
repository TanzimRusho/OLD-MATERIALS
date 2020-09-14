// Sample Input:
/*
6
xoxxoS
xooooo
xoxoxx
xoooox
ooxxox
Doxxoo
*/


#include<bits/stdc++.h>
using namespace std;

#define N 16
char maze[N][N];


struct point{
    int x;
    int y;
};


int dr[] = {-1,0,1,0};
int dc[] = {0,1,0,-1};


void inputGraph(int n){
    // Take input of the maze
    for(int i = 0; i < n; ++i ){
        for(int j = 0; j < n; ++j ){
            scanf("%c", &maze[i][j]);
        }
        getchar();
    }
}

void printMaze(int n){
    for(int i = 0; i < n; ++i ){
        for(int j = 0; j < n; ++j ){
            printf("%c", maze[i][j]);
        }
        printf("\n");
    }
}

struct point* findSource(int n){
   for(int i = 0; i < n; ++i ){
        for(int j = 0; j < n; ++j ){
            if(maze[i][j] == 'S'){
                point* p = new point();
                p->x = i;
                p->y = j;
                return p;
            }
        }
    }
}

int modifyJunction(int n){

    int junctionCount = 0;

    for(int i = 0; i < n; ++i ){
        for(int j = 0; j < n; ++j ){

            if( maze[i][j] == 'o' ){
                int adjacentRouteCount = 0;

                // check all sides
                for(int d = 0; d < 4; ++d){
                    if( i + dr[d] < 0 || i + dr[d] >= n || j + dc[d] < 0 || j + dc[d] >= n ){
                        continue;
                    }
                    else{
                        // Change the not equal x with equal o to get different junction
                        if( maze[ i + dr[d] ][ j + dc[d] ] != 'x' )
                            adjacentRouteCount = adjacentRouteCount + 1;
                    }
                }

                if( adjacentRouteCount >= 3 ){
                    maze[i][j] = 'A' + junctionCount;
                    junctionCount = junctionCount + 1;
                }

            }

        }
    }

    return junctionCount;
}

int main(){

    printf("Maze Size:\n");
    int n;
    scanf("%d", &n);
    getchar();


    inputGraph(n);
    printf("\n");
    printMaze(n);


    point* p = findSource(n);
    printf("%d,%d\n", p->x, p->y );


    printf("Junctions: %d\n", modifyJunction(n) );
    printf("\n");
    printMaze(n);

    return 0;
}
