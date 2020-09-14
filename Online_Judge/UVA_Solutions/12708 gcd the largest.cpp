/*
 * Author: Quickgrid ( Asif Ahmed )
 * Site: http://quickgrid.wordpress.com
 */

#include<iostream>
int main(){
    std::ios_base::sync_with_stdio(false);
	std::cin.tie(NULL);
	register unsigned int n;
	unsigned long a;
	std::cin >> n;
	while(n--){
        std::cin >> a;
        std::cout << (a>>1) << "\n";
	}
	return 0;
}
