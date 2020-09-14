/**
 * Author:    Asif Ahmed
 * Site:      https://quickgrid.wordpress.com
 * Problem:   UVA 10583 - Ubiquitous Religions
 * Technique: Disjoint-Set Forest Union by Rank
 *            and Path Compression using Structure.
 */

#include<stdio.h>
#include<string.h>


#define N 100000


static int parentArray[N];
static int rankArray[N];
static int elementsArray[N];


int maximum;


// Basically create n sets with elements from
// 0 to n - 1. Reset their rank to 0 since the
// sets have only one element. So each set is
// basically pointing to itself in the parent
// array.
void MakeSet(int n){
    for(int i = 0; i < n; ++i){
        parentArray[i]  = i;
        rankArray[i] = 0;
        elementsArray[i] = 1;
    }
}


// Find the parent of the node and
// do path compression in the process.
int FindSet(int x){
    if( x != parentArray[x] )
        parentArray[x] = FindSet( parentArray[x] );
    return parentArray[x];
}


// Check if both elements are in the same set.
bool SameSet(int x, int y){
    return FindSet(x) == FindSet(y);
}


// Check if they are already in the same set.
// If not then the tree or Set with the bigger
// rank becomes the parent of tree with smaller
// rank.
// If both have same rank then arbitrarily choose
// one to be the parent of the other set. Here y
// is chosen.
void Link(int x, int y){

    if( !SameSet(x, y) ){

        if( rankArray[x] > rankArray[y] ){
            parentArray[y] = x;
            elementsArray[x] += elementsArray[y];
            maximum = ( maximum < elementsArray[x] ) ? elementsArray[x] : maximum;
        }
        else{
            parentArray[x] = y;
            elementsArray[y] += elementsArray[x];
            maximum = ( maximum < elementsArray[y] ) ? elementsArray[y] : maximum;

            if(rankArray[x] == rankArray[y])
                rankArray[y] = rankArray[y] + 1;
        }

    }
}


// Union two sets.
// First find their representative and link them.
void Union(int x, int y){
    Link( FindSet(x), FindSet(y) );
}



int main(){


    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);


    int n, m;
    int i, j;


    int times;
    scanf("%d", &times);


    while( times-- ){

        scanf("%d%d", &n, &m);

            MakeSet(n);

            maximum = 1;

            while(m--){
                scanf("%d%d", &i, &j);
                --i, --j;
                Union(i, j);
            }

            printf("%d\n", maximum);

        }


    return 0;
}
