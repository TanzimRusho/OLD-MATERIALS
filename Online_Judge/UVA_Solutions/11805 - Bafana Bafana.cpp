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

    int N, K, P;
    while( m-- ){
        scanf("%d%d%d", &N, &K, &P);

        for( int i = 0; i < P; ++i )
            K = (K % N) + 1;

        printf("Case %d: %d\n", ++c,  K );
    }


    return 0;
}
