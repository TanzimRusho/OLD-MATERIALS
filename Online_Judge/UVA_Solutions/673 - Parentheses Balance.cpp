/*
 * Author: Quickgrid ( Asif Ahmed )
 * Site: http://quickgrid.wordpress.com
 */

//#include<bits/stdc++.h>
//#include<iostream>
//#include<cstdio>
//#include<sstream>
//using namespace std;

#include<stdio.h>

#define rep(i,n) for(i=0; i<(n); ++i)
#define XORSWAP(a, b) ((a)^=(b)^=(a)^=(b))
#define max(a, b) (((a)>(b))?(a):(b))

template<class T> inline T abs(T x){
   return (x ^ (x >> 31)) - (x >> 31);
}

template<class T> void swap(T& x, T& y){
    T tmp = x;
    x = y;
    y = tmp;
}

int GCD(int a,int b){
    while(b^=a^=b^=a%=b);
    return a;
}

string intToString(unsigned int n){
    stringstream strout;
    strout << n;
    return strout.str();
}

int main(){
    //freopen("in.txt", "r", stdin);
    //freopen("out.txt", "w", stdout);

	//Per ms no of inputs, judges computer speed
	for  (I=1;I<=20;I++){
        if  (I*1000>=N){
            for(j=0;j<I*100000000;j++);
        }
    }


	register unsigned int n;
	scanf("%u", &n);
	while(n--){

	}
	return 0;
}
