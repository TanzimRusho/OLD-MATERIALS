/*
 * Author: Quickgrid ( Asif Ahmed )
 * Site: http://quickgrid.wordpress.com
 * Problem: UVA 12854 - Automated Checking Machine
 */

#include<iostream>

int main(){
    std::ios_base::sync_with_stdio(false);
    bool a,b,c,d,e,f,g,h,i,j;
	while(std::cin >> a >> b >> c >> d >> e >> f >> g >> h >> i >> j){
        if(a^f && b^g && c^h && d^i && e^j){
            std::cout << "Y\n";
        }else{
            std::cout << "N\n";
        }
	}
	return 0;
}
