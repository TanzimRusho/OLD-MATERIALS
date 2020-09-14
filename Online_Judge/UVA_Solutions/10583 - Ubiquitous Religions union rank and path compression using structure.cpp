/**
 * Author:    Asif Ahmed
 * Site:      https://quickgrid.wordpress.com
 * Problem:   UVA 10583 - Ubiquitous Religions
 * Technique: Disjoint-Set Forest Union by Rank
 *            and Path Compression using Array.
 */

#include<stdio.h>
#include<string.h>


#define N 50000


// Since both object or thing were performing
// the same task they are combined into one
// using structure.
struct SetCollection{
    int Parent;
    int Rank;
} Set[N];


int disjointSetCount;


void MakeSet(int n){
    for(int i = 0; i < n; ++i){
        Set[i].Parent  = i;
        Set[i].Rank = 0;
    }

    disjointSetCount = n;
}


int FindSet(int x){
    if( x != Set[x].Parent )
        Set[x].Parent = FindSet( Set[x].Parent );
    return Set[x].Parent;
}


bool SameSet(int x, int y){
    return FindSet(x) == FindSet(y);
}



void Link(int x, int y){

    if( !SameSet(x, y) ){

        if( Set[x].Rank > Set[y].Rank )
            Set[y].Parent = x;
        else{
            Set[x].Parent = y;

            if(Set[x].Rank == Set[y].Rank)
                Set[y].Rank = Set[y].Rank + 1;
        }

        --disjointSetCount;
    }
}


void Union(int x, int y){
    Link( FindSet(x), FindSet(y) );
}



int main(){


    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);


    int n, m;

    int i, j;

    int caseNumber = 0;


    while( scanf("%d%d", &n, &m) && n && m ){

        MakeSet(n);

        while(m--){
            scanf("%d%d", &i, &j);
            Union(i, j);
        }

        printf("Case %d: %d\n", ++caseNumber, disjointSetCount);

    }


    return 0;
}
