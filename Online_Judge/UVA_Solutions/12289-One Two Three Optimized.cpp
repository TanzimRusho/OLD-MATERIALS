/**
 * @author  Quickgrid ( Asif Ahmed )
 * @link    https://quickgrid.wordpress.com
 */

#include<stdio.h>

#define O 111
#define N 110
#define E 101

static char s[8];

int main(){
    register unsigned n;
    scanf("%u", &n);

    while (n--){
        scanf("%s", s);
        if (s[3]){
            printf("3\n");
        }else{
            unsigned s0 = s[0];
            unsigned s1 = s[1];
            unsigned s2 = s[2];
            if ((s0 == O && s1 == N) || (s1 == N && s2 == E) || (s0 == O && s2 == E))
                printf("1\n");
            else
                printf("2\n");
        }
    }
    return 0;
}
