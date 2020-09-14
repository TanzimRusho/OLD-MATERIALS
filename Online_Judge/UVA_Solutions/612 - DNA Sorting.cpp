/*
 * Author: Quickgrid ( Asif Ahmed )
 * Site: http://quickgrid.wordpress.com
 */

#include<bits/stdc++.h>
using namespace std;

struct dna{
    string seq;
    unsigned int count;
} node[105];

unsigned int countInversion(string seq){
    unsigned int count = 0, i = 0, j;
    for(; seq[i]; ++i ){
        for(j=i+1; seq[j]; ++j ){
            if(seq[i] > seq[j]) ++count;
        }
    }
    return count;
}

bool cmp(dna x, dna y){
    if(x.count < y.count ) return true;
    return false;
}

int main(){
    unsigned int n, blank = 0;
	scanf("%u", &n);

	while(n--){
        unsigned int w, t, i, j;
        scanf("%u%u", &w, &t);
        for(i=0; i<t; ++i){
            cin >> node[i].seq;
            node[i].count = countInversion(node[i].seq);
        }
        stable_sort(node, node+t, cmp);

        if(blank) printf("\n");
        blank = 1;

        for(i=0; i<t; ++i){
            cout << node[i].seq << "\n";
        }
	}
	return 0;
}
