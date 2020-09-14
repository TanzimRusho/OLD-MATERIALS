/**
 * @author  Quickgrid ( Asif Ahmed )
 * @link    https://quickgrid.wordpress.com
 */

#include<stdio.h>

static char s[128];

#define H 1.008
#define C 12.01
#define O 16.0
#define N 14.01

int main(){
    register unsigned int n, i;
    unsigned int i1, i2;
    scanf("%u", &n);

    while(n--){
        scanf("%s", &s);
        float sum = 0;

        for(i = 0; s[i]; ++i){
            i1 = s[i + 1];
            i2 = s[i + 2];
            unsigned i1check = i1 >= '0' && i1 <= '9';

            switch(s[i]){
            case 67:
                if(i1check && (i2 >= '0' && i2 <= '9')){
                    sum += 120.1 * i1 + C * i2 - 6341.28;
                    break;
                }else if(i1check){
                    sum += C * i1 - 576.48;
                    break;
                }else{
                    sum += C;
                    break;
                }
            case 72:
                if(i1check && (i2 >= '0' && i2 <= '9')){
                    sum += 10.08 * i1 + H * i2 - 532.224;
                    break;
                }else if(i1check){
                    sum += H * i1 - 48.384;
                    break;
                }else{
                    sum += H;
                    break;
                }
            case 78:
                if(i1check && (i2 >= '0' && i2 <= '9')){
                    sum += 140.1 * i1 + N * i2 - 7397.28;
                    break;
                }else if(i1check){
                    sum += N * i1 - 196.14;
                    break;
                }else{
                    sum += N;
                    break;
                }
            case 79:
                if(i1check && (i2 >= '0' && i2 <= '9')){
                    sum += 160.0 * i1 + O * i2 - 8448.0;
                    break;
                }else if(i1check){
                    sum += O * i1 - 768.0;
                    break;
                }else{
                    sum += O;
                    break;
                }
            }
        }
        printf("%.3f\n", sum);
    }
    return 0;
}
