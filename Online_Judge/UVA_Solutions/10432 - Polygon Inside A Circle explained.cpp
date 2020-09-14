/**
 * Author:    Asif Ahmed
 * Site:      https://quickgrid.wordpress.com
 * Problem:   UVA 10432 - Polygon Inside A Circle
 * Technique: circumcircle Or, Isocele Area calculation.
 */

#include<stdio.h>
#include<string.h>
#include<math.h>


int main(){

    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);


    double r;
    int n;

    while( scanf( "%lf%d", &r, &n ) == 2 ){

        // Angle between each two points for every point.
        double PHI = ( double ) 360 / n ;

        // For each Isosceles in the polygon the angle between the base and radius.
        double THETA = (double) 90 - ( PHI / 2 );


        // Convert Degree angle to Radian to use in code.
        double THETA_RADIAN = THETA * M_PI / 180;


        //  a is base.
        double a = 2 * r * cos( THETA_RADIAN );

        // H is the height.
        double h = r * sin( THETA_RADIAN );

        // S represent Area of a single segment.
        double S = (a * h) / 2;


        // S * n is the are of complete polygon.
        printf("%.3lf\n",  S * n );


    }

    return 0;
}
