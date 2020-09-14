/**
 * Author:    Asif Ahmed
 * Site:      https://quickgrid.wordpress.com
 * Problem:
 */


#include<stdio.h>
#include<string.h>

#define R 101
#define C 101


static char strings[R][C];
static char output[R][C];

int main(){

    int i = 0;
    int maxlen = 0;

    while( gets( strings[i] ) ){

        int len = strlen(strings[i]);

        if(len > maxlen)
            maxlen = len;

        ++i;
    }

    int rows = i;

    int x = 0;
    for( int k = 0; k < maxlen; ++k ){

        int y = 0;
        for(int j = rows - 1; j >= 0; --j){

            if( strings[j][k] == '\n' || strings[j][k] == ' ' || strings[j][k] == '\0')
                output[x][y++] = ' ';

            else output[x][y++] = strings[j][k];

        }
        ++x;
    }

    for(int i = 0; i < x; ++i)
        puts(output[i]);


    return 0;
}
