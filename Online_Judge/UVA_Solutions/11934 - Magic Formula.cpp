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

    int a, b, c, d, L;

    while( scanf("%d%d%d%d%d", &a, &b, &c, &d, &L) ){

        if( !a && !b && !c && !d && !L )
            return 0;

        int ans = 0;

        for(int i = 0; i <= L; ++i){
            int value = a * i * i + b * i + c;
            if( value % d == 0 )
                ++ans;
        }

        printf("%d\n", ans);

    }


    return 0;
}
