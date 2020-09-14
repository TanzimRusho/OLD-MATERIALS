/**
 * Author:    Asif Ahmed
 * Site:      https://quickgrid.wordpress.com
 * Problem:   UVA
 * Technique:
 */

#include<stdio.h>
#include<string.h>


int main(){

    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);


    int m;
    scanf("%d", &m);

    int c = 0;

    int x, y;
    while( m-- ){
        scanf("%d%d", &x, &y);

        int N = y - x;

        int p = 0;
        int q = 0;
        int c = 0;

        while( N > 0 ){

            p = p + 1;

            for( int i = 0; i < 2 && p > 0; ++i ){
                if( N - p >= 0 ){
                    N = N - p;
                    c = c + 1;
                    break;
                }
                --p;
            }

            if( N <= 0 )
                break;

            q = q + 1;

            for( int i = 0; i < 2 && q > 0; ++i ){
                if( N - q >= 0 ){
                    N = N - q;
                    c = c + 1;
                    break;
                }
                --q;
            }
        }

        printf("%d\n", c);
    }


    return 0;
}
