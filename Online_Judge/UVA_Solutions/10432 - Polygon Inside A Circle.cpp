/**
 * Author:    Asif Ahmed
 * Site:      https://quickgrid.wordpress.com
 * Problem:   UVA
 * Technique:
 */

#include<stdio.h>
#include<string.h>
#include<math.h>


int main(){

    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);


    double R;
    int n;

    while( scanf( "%lf%d", &R, &n ) == 2 ){
        printf("%.3lf\n",  (n * R * R * sin( 2 * M_PI / n )) / 2 );
    }

    return 0;
}
