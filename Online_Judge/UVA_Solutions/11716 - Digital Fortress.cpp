/**
 * Author:    Asif Ahmed
 * Site:      https://quickgrid.wordpress.com
 * Problem:   UVA 11716 - Digital Fortress
 * Technique: Square String Traverse from row major
 *            to column major by skipping.
 */

#include<stdio.h>
#include<string.h>
#include<math.h>


#define N 10002
static char s[N];
static char output[N];


int main(){

    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);


    int n;
    scanf("%d", &n);
    getchar();


    while( n-- ){
        gets(s);


        // Get the length of string and length of each string group.
        int len = strlen(s);
        int rc = sqrt(len);


        // Reset in case there are characters from previous iteration.
        memset(output, 0, sizeof output);



        // If the string length can be divided into equal parts
        // then traverse by skipping certain length.
        if( rc * rc == len ){

            int k = 0;

            for( int j = 0; j < rc; ++j ){
                for( int i = j; i < len; i = i + rc ){
                    output[k++] = s[i];
                }
            }

            puts(output);

        }
        else{
            puts("INVALID");
        }

    }


    return 0;
}
