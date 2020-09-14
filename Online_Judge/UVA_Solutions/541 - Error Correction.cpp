/**
 * Author:    Asif Ahmed
 * Site:      https://quickgrid.wordpress.com
 * Problem:   UVA
 * Technique:
 */

#include<stdio.h>
#include<string.h>


#define N 100


static int matrix[N][N];


int main(){

    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);


    int n;

    while( scanf("%d", &n) && n ){


        for(int i = 0; i < n; ++i)
            for(int j = 0; j < n; ++j)
                scanf("%d", &matrix[i][j]);


        int rowErrorCount = 0;
        int colErrorCount = 0;

        int rowNumber = 0;
        int colNumber = 0;


        for(int i = 0; i < n; ++i){

            int rowsum = 0;
            int colsum = 0;

            int j = 0;
            for(; j < n; ++j){
                rowsum += matrix[i][j];
                colsum += matrix[j][i];
            }

            if(rowsum % 2){
                ++rowErrorCount;
                rowNumber = i;
            }
            if(colsum % 2){
                ++colErrorCount;
                colNumber = i;
            }

            if( rowErrorCount > 1 || colErrorCount > 1 ){
                printf("Corrupt\n");
                goto done;
            }
        }


        if(rowErrorCount == 0 && colErrorCount == 0)
            printf("OK\n");
        else
            printf("Change bit (%d,%d)\n", rowNumber + 1, colNumber + 1);

        done:;

    }

    return 0;
}
