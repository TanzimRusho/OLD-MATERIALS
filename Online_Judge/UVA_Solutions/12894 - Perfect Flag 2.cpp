/*
 * Author: Quickgrid ( Asif Ahmed )
 * Site: http://quickgrid.wordpress.com
 * Problem: UVA 12894 ( Perfect Flag )
 */

#include<iostream>
int main(){
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);
	register unsigned int n;
    unsigned int x0, y0, x1, y1, cx, cy, r;
	std::cin >> n;
	while(n--){
        std::cin >> x0 >> y0 >> x1 >> y1 >> cx >> cy >> r;
        unsigned int len = x1 - x0, wid = y1 - y0;
        (( 5*wid == 3*len ) && ( len == 5*r ) && (20*( cx - x0 ) == 9*len) && ((( cy-y0 ) << 1) == wid) ) ? std::cout << "YES\n" : std::cout << "NO\n";
	}
	return 0;
}
