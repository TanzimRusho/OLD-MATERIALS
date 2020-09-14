/*
 * Author: Quickgrid ( Asif Ahmed )
 * Site: http://quickgrid.wordpress.com
 * Problem: UVA 12854 - Automated Checking Machine
 */
#include<iostream>
#include<cstdio>
#include<sstream>
using namespace std;
string a, b;
bool x, y;
int main(){
	while( 1 ){
        getline(cin,a);
        getline(cin,b);
        if(a[0] == '\0' || b[0] == '\0') return 0;
        bool works = 0;
        unsigned int N = 5;
        while(N--){
            stringstream strin1(a);
            strin1 >> x;
            stringstream strin2(b);
            strin2 >> y;
            if(x^y){
                works = 1;
            }else{
                printf("N\n");
                break;
            }
        }
        if(works){
            printf("Y\n");
        }
	}
	return 0;
}
