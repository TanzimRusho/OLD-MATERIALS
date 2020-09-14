/**
 * Author:    Asif Ahmed
 * Site:      https://quickgrid.wordpress.com
 * Problem:   UVA 11565 - Simple Equations
 * Technique: Mathematical elimination and substitution
 */

#include<cstdio>
#include<algorithm>
#include<iostream>


int main()
{
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);

    int A, B, C;

    int n;
    scanf("%d", &n);


    while( n-- )
    {
        scanf("%d%d%d", &A, &B, &C);

        int x, y, z;

        int maxval;


        if( A > B && A > C )
            maxval = A;
        if(B > C)
            maxval = B;
        else
            maxval = C;



        if(maxval > 58)
            maxval = 58;


        for( z = -maxval; z <= maxval; ++z )
        {
            if(!z) continue;

            int temp = B / z;

            if( ( ( A - z ) * ( A - z ) - (2 * temp) ) == ( C - z * z )  )
            {
                int tmp = z >> 1;

                for( int y = -tmp; y <= tmp; ++y ){

                    x = A - z - y;

                    if( x * y == temp && x != y && x != z ){
                        int tmpArray[3] = {x, y, z};
                        std::sort(tmpArray, tmpArray + 3);
                        std::cout << tmpArray[0] << " " << tmpArray[1] << " " << tmpArray[2] << "\n";

                        goto done;
                    }

                }
            }
        }


        std::cout << "No solution." << "\n";
        done:;

    }


    return 0;
}
