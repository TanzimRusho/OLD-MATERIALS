/**
 * Author:    Asif Ahmed
 * Site:      https://quickgrid.wordpress.com
 * Problem:   Lattice Multiplication.
 * Technique: Structure array representing upper left and
 *            and lower right corner in single cell.
 */

#include<stdio.h>
#include<string.h>


#define N 37


struct multiplicationTable{
    int upper;
    int lower;
};
struct multiplicationTable node[N][N];


static char string1[] = "2493244375547893760909809350745093295";
static char string2[] = "4534574586585490342689034093046946899";



void printMultiplicationMatrix(){

    printf("\n\n");
    for( int i = 0; i < N; ++i ){
        for( int j = N - 1; j >= 0; --j )
            printf("%d :: %d, ", node[i][j].upper, node[i][j].lower );
        printf("\n");
    }

}


int sum;
int m;

int recursiveAdder( int i, int j ){

    if( j < 0 || i >= N )
        return sum;

    int val;

    if( m % 2 ){
        val = node[i][j].upper;
        //printf("EVEN %d\n", node[i][j].upper);
        j = j - 1;
    }
    else{
        val = node[i][j].lower;
        //printf("ODD %d\n", node[i][j].lower);
        i = i + 1;
    }
    ++m;

    sum = sum + val;

    recursiveAdder(i,j);

    return sum;
}



int main(){

    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);

    int k = N - 1;

    for( int i = 0; string2[i]; ++i ){
        for( int j = 0; string2[j]; ++j ){

            int num1 = string2[j] - '0';
            int num2 = string1[k] - '0';

            int multiply = num1 * num2;

            node[j][k].upper = multiply / 10;
            node[j][k].lower = multiply % 10;

            //printf("%d :: %d\n", num1, num2);
        }
        --k;
    }


    //printMultiplicationMatrix();


    // result of upper half
    int upperHalfResult[N];

    // Add upper half
    int i = N - 1;
    for(; i >= 0; --i){

        sum = 0;
        m = 1;
        upperHalfResult[i] = recursiveAdder(0, i);
    }


    /*
    printf("\n\n");
    for(i = 0; i < N; ++i)
        printf("%d ", upperHalfResult[i]);
    */

    //printf("\n\n---------------\n\n");


    // result of upper half
    int lowerHalfResult[N];

    // Add upper half
    i = 0;
    for(; i < N; ++i){
        sum = 0;
        m = 0;
        lowerHalfResult[i] = recursiveAdder(i, N - 1);
    }


    /*
    printf("\n\n");
    for(i = 0; i < N; ++i)
        printf("%d ", lowerHalfResult[i]);
    */



    int combinedRawResult[N + N];
    i = 0;
    for(; i < N; ++i )
        combinedRawResult[i] = upperHalfResult[i];
    for(k = 0; i < N + N; ++i, ++k )
        combinedRawResult[i] = lowerHalfResult[k];


    /*
    printf("\n\n");
    for(i = 0; i < N + N; ++i)
        printf("%d ", combinedRawResult[i]);
    */




    for( int i = N + N - 1; i >= 0; --i ){

        if( combinedRawResult[i] > 9 ){
            combinedRawResult[i - 1] = combinedRawResult[i - 1] + combinedRawResult[i] / 10;
            combinedRawResult[i] = combinedRawResult[i] % 10;
        }

    }



    printf("\n");
    for(i = 0; i < N + N; ++i)
        printf("%d", combinedRawResult[i]);
    printf("\n");



    return 0;
}
