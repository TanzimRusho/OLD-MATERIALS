/*
 * Author: Quickgrid ( Asif Ahmed )
 * Site: http://quickgrid.wordpress.com
 * Problem: UVA 100 ( 3n + 1 )
 */
#include<stdio.h>

#define SIZE 1000001

static unsigned int table[SIZE];                        /* Lookup table for storing previously calculated values */

unsigned int cycleLength(register unsigned int n){      /* Returns cycle length for given number */
    if(n < SIZE && table[n]){                           /* If the value already exists in the lookup table then return its cycle length */
        return table[n];
    }
    if(n&1){                                            /* Check if number is odd */
        if(n < SIZE){
            table[n] = 2 + cycleLength((3*n+1) >> 1);   /* Since 3n+1 becomes an even number, we perform the next step which is divided by two since its even, also +2 since we perform two operations */
            return table[n];
        }else{
            return 2 + cycleLength((3*n+1) >> 1);       /* The value is bigger than table so we calculate and return */
        }
    }else{
        if(n < SIZE){
            table[n] = 1 + cycleLength(n >> 1);         /* The number is even so we perform number divided two, or bit shift left once */
            return table[n];
        }else{
            return 1 + cycleLength(n >> 1);
        }
    }
}

int main(){
    unsigned int a,b,count;
    register unsigned int n;
    table[1] = 1;                                        /* This is necessary since i don't check for 1 in cycleLength, Also 1st index is always 1 */
    while(scanf("%u%u", &a, &b)==2){
        unsigned int maxCycle = 0;
        if(a<b){                                         /* The input may contain bigger number first then smaller number */
            for(n=a; n<=b; ++n){
                count = cycleLength(n);                  /* Cycle every value between a to b */
                if(maxCycle < count){                    /* We need to find max cycle, so if a cycle count is greater than maxCycle then replace maxCycle */
                    maxCycle = count;
                }
            }
        }else{
            for(n=b; n<=a; ++n){
                count = cycleLength(n);
                if(maxCycle < count){
                    maxCycle = count;
                }
            }
        }
        printf("%u %u %u\n", a, b, maxCycle);
    }
    return 0;
}
