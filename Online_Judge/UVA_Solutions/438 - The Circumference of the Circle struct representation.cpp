/**
 * Author:    Asif Ahmed
 * Site:      https://quickgrid.wordpress.com
 * Problem:   UVA 438 - The Circumference of the Circle.
 * Technique: Point and Line representation in structure.
 *            Finding diameter and circumference of Circumscribed
 *            circle or Circumcirlce.
 *            Using Heron's formula to calculate semi perimeter
 *            and area of triangle from Three points.
 */

#include<stdio.h>
#include<string.h>
#include<math.h>


#define PI 3.141592653589793


struct Point{
    double x;
    double y;
};


struct Line{
    Point a;
    Point b;

    Point setPoints( Point _a = {0.0,0.0}, Point _b = {0.0,0.0} ){
        a = _a;
        b = _b;
    }

    double length(){
        return sqrt( pow(a.x - b.x, 2) + pow(a.y - b.y, 2) );
    }

};


int main(){

    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);


    Point point[3];
    Line  line [3];


    while( scanf("%lf%lf%lf%lf%lf%lf", &point[0].x, &point[0].y, &point[1].x, &point[1].y, &point[2].x, &point[2].y ) == 6 ){


        // Loop is same as code below.
        //line[0].setPoints(point[0], point[1]);
        //line[1].setPoints(point[1], point[2]);
        //line[2].setPoints(point[2], point[0]);

        int N = 3;
        for( int i = 0; i < N; ++i )
            line[i].setPoints( point[i], point[(i+1) % N] );



        // semi perimeter is half of perimeter.
        // Perimeter is distance around the shape in 2D.

        double s = ( line[0].length() + line[1].length() + line[2].length() ) / 2;


        // Area using Heron's Formula

        double A = sqrt( s * (s - line[0].length()) * (s - line[1].length()) * (s - line[2].length()) );


        // Diameter of circumscribed circle d = abc/2A

        double d = (line[0].length() * line[1].length() * line[2].length()) / (2 * A);


        // Result circumference of the circumcircle

        double circumference = PI * d;


        printf("%.2lf\n", circumference );

    }


    return 0;
}
