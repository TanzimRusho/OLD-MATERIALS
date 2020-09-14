/**
 * Author:    Asif Ahmed
 * Site:      https://quickgrid.wordpress.com
 * Problem:   UVA
 * Technique:
 */

#include<cstdio>
#include<cstring>
#include<iostream>

using namespace std;


#define N 256


static int priceTable[N];


int main(){

    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);


    int times;
    cin >> times;

    while( times-- ){


        for(int i = 0; i < N; ++i)
            priceTable[i] = 0;


        int valueCount;
        cin >> valueCount;
        getchar();

        while( valueCount-- ){

            unsigned char ch;
            int cents;

            cin >> ch >> cents;
            getchar();

            priceTable[ (int) ch] = cents;
        }

        int sum = 0;

        int sentenceCount;
        cin >> sentenceCount;
        getchar();


        while(sentenceCount-- ){

            unsigned char c;
            while( ( c = getchar() ) != '\n' )
                sum = sum + priceTable[ (int) c ];

        }


        printf("%.2lf$\n", sum / 100.0 );

    }


    return 0;
}
