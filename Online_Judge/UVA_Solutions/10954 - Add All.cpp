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



int main(){

    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);


    int n;
    while( scanf("%d", &n) && n ){

        priority_queue<int, vector<int>, greater<int> > pq;


        int num;
        while( n-- ){
            scanf("%d", &num);
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


    }


    return 0;
}
