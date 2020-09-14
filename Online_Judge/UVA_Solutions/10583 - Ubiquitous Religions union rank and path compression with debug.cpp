/**
 * Author:    Asif Ahmed
 * Site:      https://quickgrid.wordpress.com
 * Problem:   UVA
 * Technique:
 */

#include<stdio.h>
#include<string.h>


#define N 50002


static int parentArray[N];
static int rankArray[N];


int disjointSetCount;


void MakeSet(int n){
    for(int i = 0; i < n; ++i){
        parentArray[i]  = i;
        rankArray[i] = 0;
    }

    disjointSetCount = n;
}


int FindSet(int x){
    if( x != parentArray[x] )
        parentArray[x] = FindSet( parentArray[x] );
    return parentArray[x];
}


bool SameSet(int x, int y){
    return FindSet(x) == FindSet(y);
}



void Link(int x, int y){

    if( !SameSet(x, y) ){

        if( rankArray[x] > rankArray[y] )
            parentArray[y] = x;
        else{
            parentArray[x] = y;

            if(rankArray[x] == rankArray[y])
                rankArray[y] =rankArray[y] + 1;
        }

        --disjointSetCount;
    }
}


void Union(int x, int y){
    Link( FindSet(x), FindSet(y) );
}


/**
 * This is for debugging only and can be deleted.
 */
void PrintSet(int n){
    printf("Set Array:\n");
    for(int i = 0; i < n; ++i)
       printf("%d ", parentArray[i] );

    printf("\n");

    printf("Rank Array:\n");
    for(int i = 0; i < n; ++i)
        printf("%d ", rankArray[i] );

    printf("\n\n");
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
