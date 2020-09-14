/**
 * Author:    Asif Ahmed
 * Site:      https://quickgrid.wordpress.com
 * Problem:   UVA
 * Technique:
 */

#include<cstdio>
#include<algorithm>
#include<iostream>


int main(){
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);


    int n;
    scanf("%d", &n);

    int A, B, C;


    while( n-- ){
        scanf("%d%d%d", &A, &B, &C);

        bool sol = false;
        int x, y, z;

        for( x = -100; x <= 100; ++x ){
            for( y = -100; y <= 100; ++y ){

                if( (x * x + y * y) + (A - x - y) * (A - x - y) == C   ){

                    int temp = x * y;

                    if( temp == 0 ) continue;

                    z = B / (x * y);

                    if( x != y && z != x && z != y && x + y + z == A && x * y * z == B && x * x + y * y + z * z == C  ){
                        if(!sol){
                            int tmpArray[3] = {x, y, z};
                            std::sort(tmpArray, tmpArray + 3);
                            printf("%d %d %d\n", tmpArray[0], tmpArray[1], tmpArray[2] );
                        }
                        sol = true;

                    }

                }
            }
        }


        if(!sol)
            printf("No solution.\n");

    }


    return 0;
}
