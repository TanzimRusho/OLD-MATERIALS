#include<cstdio>
#include<iostream>
#include<string>
#include<map>

using namespace std;

#define N 5

map <int, int> m;
pair <int, int> p[N], C[N];

// A: 6 2 1 5 4
// I: 0 1 2 3 4

// B: 1 2 4 5 6
// I: 2 1 4 3 0

int main()
{
    int B[] = {6, 2, 1, 5, 4};
    int A[] = {1, 2, 4, 5, 6};

    int i = 0;
    for(; i < N; ++i){
        p[i].first = i;
        p[i].second = B[i];
    }

    i = 0;
    for(; i < N; ++i)
        printf("%d - %d \n", p[i].first, p[i].second);


    return 0;
}
