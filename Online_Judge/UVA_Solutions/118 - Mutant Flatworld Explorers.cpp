/**
 * Author:      Asif Ahmed
 * Site:        http://quickgrid.blogspot.com
 * Description: Inputting and Representing an Weighted Undirected graph
 *              in adjacency list vector list pair using C++ STL.
 */


#include<bits/stdc++.h>
using namespace std;
#define M 4


static int directions[] = {'N', 'E', 'W', 'S'};
static int helper[M];
static int Rmapper[] = {'E', 'S', 'N', 'W'};
static int Lmapper[M];

static int dr[] = {0, 1, -1, 0};
static int dc[] = {1, 0, 0, -1};


int main(){

    //
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);


    //
    for(int i = 0, j = M - 1; i < M; ++i, --j)
        Lmapper[i] = Rmapper[j];
    for(int i = 0; i < M; ++i)
        helper[ directions[i] ] = i;


    int r, c;
    scanf("%d%d", &r, &c);

    //
    ++r, ++c;


    // Initialize two dimensional array.
    int** terrain = new int*[r];
    for(int i = 0; i < r; ++i)
        terrain[i] = new int[c];

    int** scent = new int*[r];
    for(int i = 0; i < r; ++i){
        scent[i] = new int[c];
        for(int j = 0; j < c; ++j)
            scent[i][j] = 0;
    }


    string instructions;
    int posX, posY;
    char dir;


    while( cin >> posX >> posY >> dir >> instructions ){

        // Make all positions unmarked.
        for(int i = 0; i < r; ++i)
            for(int j = 0; j < c; ++j)
                terrain[i][j] = 0;


        // Sit in given position with given direction.
        terrain[posX][posY] = dir;
        bool stopProcessing = false;


        //
        for(int i = 0; instructions[i]; ++i ){

            if( instructions[i] == 'L' ){
                terrain[posX][posY] = Lmapper[ helper[ terrain[posX][posY] ] ];
            }
            else if( instructions[i] == 'R'){
                terrain[posX][posY] = Rmapper[ helper[ terrain[posX][posY] ] ];
            }
            else{
                int idx = helper[ terrain[posX][posY] ];

                bool outOfBound = ( posX + dr[idx] < 0 || posX + dr[idx] >= r || posY + dc[idx] < 0 || posY + dc[idx] >= c );

                if( outOfBound ){
                    if( scent[posX][posY] != 'x' ){
                        scent[posX][posY] = 'x';
                        printf("%d %d %c LOST\n", posX, posY, terrain[posX][posY]);
                        stopProcessing = true;
                        break;
                    }
                }else{
                    int prevPosX = posX;
                    int prevPosY = posY;

                    posX = posX + dr[idx];
                    posY = posY + dc[idx];

                    terrain[posX][posY] = terrain[prevPosX][prevPosY];
                    terrain[prevPosX][prevPosY] = 0;
                }
            }
        }


        if( !stopProcessing )
            printf("%d %d %c\n", posX, posY, terrain[posX][posY]);



    }



    return 0;
}
