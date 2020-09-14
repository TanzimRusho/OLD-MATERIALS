/**
 * Author:    Asif Ahmed
 * Site:      https://quickgrid.wordpress.com
 * Problem:   UVA
 * Technique:
 */

#include<cstdio>
#include<queue>
#include<vector>
#include<iostream>


using namespace std;


static unsigned n;

void Rfastscan(){
    register unsigned c = getchar();
    n = 0;
    for(;(c > 47 && c < 58); c = getchar())
        n = (n << 1) + (n << 3) + c - 48;
}


static unsigned num;

void Rfastscan2(){
    register unsigned c = getchar();
    num = 0;
    for(;(c > 47 && c < 58); c = getchar())
        num = (num << 1) + (num << 3) + c - 48;
}



int main(){

    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);


    Rfastscan();

    while( n ){

        priority_queue<int, vector<int>, greater<int> > pq;


        while( n-- ){
            Rfastscan2();
            pq.push(num);
        }
        getchar();


        int total = 0, cost = 0;
        while( pq.size() > 1 ){

            total  = pq.top();
            pq.pop();
            total = total + pq.top();
            pq.pop();

            pq.push( total );

            cost = cost + total;

        }


        printf("%d\n", cost);


        Rfastscan();
    }


    return 0;
}
