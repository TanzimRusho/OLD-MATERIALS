/**
 * @author  Quickgrid ( Asif Ahmed )
 * @link    http://quickgrid.wordpress.com
 */

#include<iostream>
#include<cstdio>
#include<sstream>
#include<cmath>

static char buffer[32768];

int main(){
    double a,b,c,s;

    /**
     * @brief Read file from stdin and create string stream of buffer
     */
	fread(buffer, 1, sizeof buffer, stdin);
	std::stringstream ss(buffer);

	while (ss >> a >> b >> c){

        /**
         * @var s
         * Heron's Formula: s, is semi perimeter
         */
        s = (a + b + c) / 2.0;

        /**
         * @var area
         * Heron's Formula: area, of a triangle
         */
        double area = (4.0 / 3.0) * sqrt(s * (s - a) * (s - b) * (s - c));

        /**
         * If area is not valid then print -1, otherwise print area
         */
        area > 0 ? printf("%0.3lf\n", area) : printf("-1.000\n");
	}
	return 0;
}
