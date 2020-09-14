/**
 * Author:    Asif Ahmed
 * Site:      https://quickgrid.wordpress.com
 * Problem:   Lattice Multiplication.
 * Technique: High precision large number multiplication.
 *            Structure array representing upper left and
 *            and lower right corner in single cell.
 */

#include<stdio.h>
#include<string.h>


// Change this to match the length of strings.
#define M 260

int N;


// Assuming both strings are of same length.
struct multiplicationTable{
    int upper;
    int lower;
};
struct multiplicationTable node[M][M];



static char string1[M];
static char string2[M];



// stores the diagonal sums;
int sum;

// decides whether to get the upper or lower
// value based on even or odd.
int m;


// Add diagonals.
int recursiveAdder( int i, int j ){

    // Termination condition.
    if( j < 0 || i >= N )
        return sum;

    int val;


    // Whether to get the upper left corner or
    // the lower right corner.
    if( m % 2 ){
        val = node[i][j].upper;
        j = j - 1;
    }
    else{
        val = node[i][j].lower;
        i = i + 1;
    }
    ++m;


    // store the sum of the whole diagonal.
    sum = sum + val;


    // recursively visit all row ans column
    // diagonally ( at least on pen and paper format ).
    // actually moves more like the snake in the snakes game.
    recursiveAdder(i,j);

    return sum;
}


// Debug.
// Print the matrix showing the multiplications.
// Please note left and right directions may be different.
void printMultiplicationMatrix(){

    printf("\n\n");
    for( int i = 0; i < N; ++i ){
        for( int j = N - 1; j >= 0; --j )
            printf("%d,%d, ", node[i][j].upper, node[i][j].lower );
        printf("\n");
    }

}







int main(){

    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);


    while( gets(string1) ){
        gets(string2);

        int len1 = strlen(string1);
        int len2 = strlen(string2);

        // Fix length if both string are not equal size.
        // Adding leading zeros to smaller string.
        if( len1 > len2 ){
            N = len1;

            int shiftWidth = len1 - len2;

            for( int i = len1 - 1; i >= 0; --i )
                string2[i + shiftWidth] = string2[i];

            for(int j = 0; j < shiftWidth; ++j)
                string2[j] = '0';

        }
        else if(len2 > len1){
            N = len2;

            int shiftWidth = len2 - len1;

            for( int i = len2 - 1; i >= 0; --i )
                string1[i + shiftWidth] = string1[i];

            for(int j = 0; j < shiftWidth; ++j)
                string1[j] = '0';

        }
        else N = len1;


        //printf("%s \n%s \n", string1, string2);


        int k = N - 1;


        // Multiply the numbers digit by digit and set in the lattice.
        for( int i = 0; string2[i]; ++i ){
            for( int j = 0; string2[j]; ++j ){

                int num1 = string1[k] - '0';
                int num2 = string2[j] - '0';

                int multiply = num1 * num2;

                node[j][k].upper = multiply / 10;
                node[j][k].lower = multiply % 10;

            }
            --k;
        }

        //printMultiplicationMatrix();


        // Lattice is divided into two parts upper left half and
        // lower right half.


        // result of upper half
        int upperHalfResult[N];

        // Add upper half
        int i = N - 1;
        for(; i >= 0; --i){
            sum = 0;
            m = 1;
            upperHalfResult[i] = recursiveAdder(0, i);
        }


        // result of upper half
        int lowerHalfResult[N];

        // Add upper half
        i = 0;
        for(; i < N; ++i){
            sum = 0;
            m = 0;
            lowerHalfResult[i] = recursiveAdder(i, N - 1);
        }



        // Combine upper and lower left half to a single array to fix addition
        // problems.
        int combinedRawResult[N + N];
        i = 0;
        for(; i < N; ++i )
            combinedRawResult[i] = upperHalfResult[i];
        for(k = 0; i < N + N; ++i, ++k )
            combinedRawResult[i] = lowerHalfResult[k];



        // If a cell has more than 9 then it should be added to the next cell.
        for( int i = N + N - 1; i >= 0; --i ){

            if( combinedRawResult[i] > 9 ){
                combinedRawResult[i - 1] = combinedRawResult[i - 1] + combinedRawResult[i] / 10;
                combinedRawResult[i] = combinedRawResult[i] % 10;
            }

        }


        // Discard leading zeros.
        for(i = 0; i < N + N; ++i)
            if(combinedRawResult[i]) break;


        // print if the result can be printed or its zero.
        bool zero = true;
        for(; i < N + N; ++i){
            printf("%d", combinedRawResult[i]);
            zero = false;
        }

        // If the result is zero.
        if( zero )
            printf("0");

        printf("\n");



    }

    return 0;
}
