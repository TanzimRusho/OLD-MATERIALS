/*
 * Author:   Quickgrid ( Asif Ahmed )
 * Site:     https://quickgrid.wordpress.com
 * Problem:  UVA
 * Solution:
 */

#include<cstdio>
#include<iostream>
#include<vector>
#include<algorithm>


using namespace std;


vector<long long> medianSet;


int main(){

    long long n;

    while( scanf("%u", &n) == 1 ){

        medianSet.push_back( n );


        int medianSetSize = medianSet.size();


        if( n < medianSet[ medianSetSize - 2 ] )
            sort( medianSet.begin(), medianSet.end() );


        int medianSetMidPoint = medianSetSize >> 1;


        if( medianSetSize & 1 )
            printf("%d\n", medianSet[ medianSetMidPoint ] );
        else
            printf("%d\n", ( medianSet[ medianSetMidPoint ] + medianSet[ medianSetMidPoint - 1 ] ) >> 1 );

    }


    return 0;
}
