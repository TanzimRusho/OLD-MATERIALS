/*
 * Author: Quickgrid ( Asif Ahmed )
 * Site: https://quickgrid.wordpress.com
 */

#include<stdio.h>


#define N  128
#define IO 1001


/**
 * Heart of the problem. Be careful with mapping, one typo in mapping and the verdict is wrong.
 * Here standard contains all the characters in standard keyboard including capital and small.
 * dvorak contains all the characters in dvorak keyboard including capital and small.
 */
static const char standard[N] = "`1234567890-=qwertyuiop[]\\asdfghjkl;'zxcvbnm,./~!@#$%^&*()_+QWERTYUIOP{}|ASDFGHJKL:\"ZXCVBNM<>? ";
static const char dvorak[N]   = "`123qjlmfp/[]456.orsuyb;=\\789aehtdck-0zx,inwvg'~!@#QJLMFP?{}$%^>ORSUYB:+|&*(AEHTDCK_)ZX<INWVG\" ";


/**
 * This is the mapping array. It holds mappings of dvorak to standard keyboard.
 */
static char mappingKB[N];


static char input[IO];


int main(){

    /**
     * Although mapping "mappingKB[ standard[i] ] = dvorak[i]" seems wrong and
     * mapping from "mappingKB[ dvorak[i] ] = standard[i]" seems correct.
     *
     * But its wrong remember the coach was typing dvorak in standard keyboard keys
     * instead of dvorak key mappings. Since the input was in standard keyboard and we should convert it to dvorak otherwise it looks
     * scrambled.
     *
     * So the keys of standard keyboard maps to dvorak keys.
     */
    for(int i = 0; dvorak[i]; ++i)
        mappingKB[ standard[i] ] = dvorak[i];



    while(gets(input)){

        /**
         * Convert standard keys to dvorak using pre-mapped array
         */
        for(int i = 0; input[i]; ++i)
            printf("%c", mappingKB[ input[i] ] );

        printf("\n");

    }


    return 0;
}
