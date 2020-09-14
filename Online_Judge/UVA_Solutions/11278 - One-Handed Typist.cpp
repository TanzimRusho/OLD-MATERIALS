/*
 * Author:     Quickgrid ( Asif Ahmed )
 * Site:       https://quickgrid.wordpress.com
 * Problem:    UVA 11278 - One Handed Typist
 * Techniques: Array mapping, Character mapping
 */

#include<stdio.h>
#include<string.h>


#define N  128
#define IO 1001


static const char standard[N] = "`1234567890-=qwertyuiop[]\\asdfghjkl;'zxcvbnm,./~!@#$%^&*()_+QWERTYUIOP{}|ASDFGHJKL:\"ZXCVBNM<>? ";
static const char dvorak[N]   = "`123qjlmfp/[]456.orsuyb;=\\789aehtdck-0zx,inwvg'~!@#QJLMFP?{}$%^>ORSUYB:+|&*(AEHTDCK_)ZX<INWVG\" ";

static char mappingKB[N];

static char input[IO];
static char output[IO];


int main(){

    for(int i = 0; dvorak[i]; ++i)
        mappingKB[ standard[i] ] = dvorak[i];


    while(gets(input)){

        // Reset memory otherwise character form previous input will be shown along with new
        memset(output, 0, sizeof output);

        for(int i = 0; input[i]; ++i)
            output[i] = mappingKB[ input[i] ];

        puts(output);

    }


    return 0;
}
