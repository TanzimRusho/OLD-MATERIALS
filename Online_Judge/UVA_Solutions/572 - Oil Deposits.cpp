/**
 * Author:    Asif Ahmed
 * Site:      https://quickgrid.wordpress.com
 * Problem:   UVA
 * Technique:
 */

#include<stdio.h>
#include<string.h>

#define N 100


static char oilField[N][N];
static int oilFieldTracker[N][N];


// starts from NW
static const int drow[] = {-1, 0, 1, 1, 1, 0, -1, -1};
static const int dcol[] = {-1, -1, -1, 0, 1, 1, 1, 0};


int n, m;



void DFS(int x, int y){

    oilFieldTracker[x][y] = 1;


    for( int k = 0; k < 8; ++k ){

        int a = x + drow[k];
        int b = y + dcol[k];

        if( a >= 0 && b >= 0 && a < n && b < m && !oilFieldTracker[a][b] ){

            oilFieldTracker[ a ][ b ] = 1;

            if( oilField[ a ][ b ] == '@' )
                DFS( a, b );


        }
    }

}


int main(){

    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);


    while( scanf("%d%d", &n, &m) && n ){

        for( int i = 0; i < n; ++i ){

            getchar();
            for( int j = 0; j < m; ++j ){
                oilField[i][j] = getchar();
            }

        }

        int oilFieldCount = 0;


        for( int i = 0; i < n; ++i ){
            for( int j = 0; j < m; ++j ){

                if( !oilFieldTracker[i][j] ){
                    oilFieldTracker[i][j] = 1;

                    if( oilField[i][j] == '@' ){
                        ++oilFieldCount;
                        DFS(i,j);
                    }

                }

            }
        }

        printf("%d\n", oilFieldCount);

        memset(oilFieldTracker, 0, sizeof oilFieldTracker);
    }

    return 0;
}
