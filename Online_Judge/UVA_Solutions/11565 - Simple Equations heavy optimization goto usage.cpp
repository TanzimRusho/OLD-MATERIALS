/**
 * Author:    Asif Ahmed
 * Site:      https://quickgrid.wordpress.com
 * Problem:   UVA 11565 - Simple Equations
 * Technique: Mathematical elimination and substitution
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

        bool solutionFound = false;
        int x, y, z;


        for( x = -58; x <= 58; ++x ){
            for( y = -22; y <= 22; ++y ){

                if( x != y && ( (x * x + y * y) + (A - x - y) * (A - x - y) == C )  ){

                    int temp = x * y;

                    if( temp == 0 ) continue;

                    z = B / temp;

                    if( z != x && z != y && x + y + z == A   ){
                        if(!solutionFound){
                            int tmpArray[3] = {x, y, z};
                            std::sort(tmpArray, tmpArray + 3);
                            std::cout << tmpArray[0] << " " << tmpArray[1] << " " << tmpArray[2] << "\n";

                            solutionFound = true;
                            goto done;
                        }
                    }

                }
            }
        }

        if(!solutionFound) std::cout << "No solution." << "\n";
        done:;

    }


    return 0;
}
