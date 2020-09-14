/**
 * Author:    Asif Ahmed
 * Site:      https://quickgrid.wordpress.com
 * Problem:   UVA
 * Technique:
 */

#include<stdio.h>
#include<string.h>


#define MAXSIZE 101


static char MineField[MAXSIZE][MAXSIZE];



// W, SW, S, SE, E, NE, N, NW
static const int drow[] = {0, 1, 1, 1, 0, -1, -1, -1};
static const int dcol[] = {-1, -1, 0, 1, 1, 1, 0, -1};



int main(){

    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);


    int n, m;

    int FieldNumber = 0;

    while( scanf("%d%d", &n, &m), n ){

        getchar();

        for(int i = 0; i < n; ++i)
            scanf("%s", &MineField[i]);


        if( FieldNumber )
            printf("\n");


        for(int i = 0; i < n; ++i){
            for(int j = 0; j < m; ++j){

                int temp = 0;

                if( MineField[i][j] == '*' )
                    continue;


                for(int k = 0; k < 8; ++k){

                    if( i + drow[k] < 0 || j + dcol[k] < 0 || i + drow[k] >= n || j + dcol[k] >= m )
                        continue;

                    if( MineField[i + drow[k] ][j + dcol[k]] == '*' )
                        ++temp;

                }

                MineField[i][j] = temp + '0';

            }
        }


        printf("Field #%d:\n", ++FieldNumber);


       for(int i = 0; i < n; ++i){
            for(int j = 0; j < m; ++j)
                putchar(MineField[i][j]);
            printf("\n");
       }

    }

    return 0;
}
