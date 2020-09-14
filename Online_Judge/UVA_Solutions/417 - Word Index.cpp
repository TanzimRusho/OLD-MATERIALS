/**
 * Author:    Asif Ahmed
 * Site:      https://quickgrid.wordpress.com
 * Problem:   UVA 417 - word index
 * Technique: Very Slow and worst possible solution.
 */

#include <vector>
#include <iostream>
#include<cstdio>
#include<cstring>
using namespace std;


#define N 26


int main() {


    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);


    vector<vector<vector<vector<vector<int> > > > > array5d;

      // Set up sizes. (HEIGHT x WIDTH)
      array5d.resize(N);
      for (int i = 0; i < N; ++i) {
        array5d[i].resize(N);

        for (int j = 0; j < N; ++j){
          array5d[i][j].resize(N);

            for (int k = 0; k < N; ++k){
              array5d[i][j][k].resize(N);

                for (int m = 0; m < N; ++m){
                  array5d[i][j][k][m].resize(N);
                }

            }
        }

      }

        int s1[N];
        int s2[N][N];
        int s3[N][N][N];
        int s4[N][N][N][N];
        int n = 0;


        for(int i = 0; i < N; ++i)
            s1[i] = ++n;



        for(int i = 0; i < N; ++i){
            for(int j = i + 1; j < N; ++j){
                s2[i][j] = ++n;

            }
        }



        for(int i = 0; i < N; ++i){
            for(int j = i + 1; j < N; ++j){
                for(int k = j + 1; k < N; ++k){

                        s3[i][j][k] = ++n;

                }
            }
        }




        for(int i = 0; i < N; ++i){
            for(int j = i + 1; j < N; ++j){
                for(int k = j + 1; k < N; ++k){
                    for(int m = k + 1; m < N; ++m){

                        s4[i][j][k][m] = ++n;

                    }
                }
            }
        }




        for(int i = 0; i < N; ++i){
            for(int j = i + 1; j < N; ++j){
                for(int k = j + 1; k < N; ++k){
                    for(int m = k + 1; m < N; ++m){
                        for(int t = m + 1; t < N; ++t){

                            array5d[i][j][k][m][t] = ++n;

                        }

                    }
                }
            }
        }




        char input[N];

        while( gets(input) ){

            int len = strlen(input);

            switch(len){
            case 1:
                printf("%d\n", s1[ input[0] - 'a' ] );
                break;
            case 2:
                printf("%d\n", s2[ input[0] - 'a' ][ input[1] - 'a' ] );
                break;
            case 3:
                printf("%d\n", s3[ input[0] - 'a' ][ input[1] - 'a' ][ input[2] - 'a' ] );
                break;
            case 4:
                printf("%d\n", s4[ input[0] - 'a' ][ input[1] - 'a' ][ input[2] - 'a' ][ input[3] - 'a' ] );
                break;
            case 5:
                printf("%d\n", array5d[ input[0] - 'a' ][ input[1] - 'a' ][ input[2] - 'a' ][ input[3] - 'a' ][ input[4] - 'a' ] );
                break;
            }

       }



  return 0;
}
