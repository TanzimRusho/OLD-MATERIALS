/**
 * Author:    Asif Ahmed
 * Site:      https://quickgrid.wordpress.com
 * Problem:   UVA 438 - The Circumference of the Circle.
 * Technique: Finding diameter and circumference of Circumscribed
 *            circle or Circumcirlce.
 *            Using Heron's formula to calculate semi perimeter
 *            and area of triangle from Three points.
 */

#include<stdio.h>
#include<string.h>
#include<math.h>


#define PI 3.141592653589793


int main(){

    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);


    double x1, y1;
    double x2, y2;
    double x3, y3;


    while( scanf("%lf%lf%lf%lf%lf%lf", &x1, &y1, &x2, &y2, &x3, &y3 ) == 6 ){

        // a dist between (x1,y1) and (x2,y2)
        // b dist between (x2,y2) and (x3,y3)
        // c dist between (x3,y3) and (x1,y1)

        double a = sqrt( pow(x1 - x2, 2) + pow(y1 - y2, 2) );
        double b = sqrt( pow(x2 - x3, 2) + pow(y2 - y3, 2) );
        double c = sqrt( pow(x3 - x1, 2) + pow(y3 - y1, 2) );


        // semi perimeter, s = (a+b+c)/2

        double s = ( a + b + c ) / 2;


        // Area using Heron's Formula

        double A = sqrt( s*(s-a)*(s-b)*(s-c) );


        // Diameter of circumscribed circle d = abc/2A

        double d = (a * b * c) / (2 * A);


        // Result circumference of the circumcircle or circumscribed circle

        double circumference = PI * d;


        printf("%.2lf\n", circumference );

    }


    return 0;
}
