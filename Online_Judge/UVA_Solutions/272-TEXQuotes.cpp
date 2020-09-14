#include<stdio.h>
char t[512];
int main(){
    register unsigned int i, k, c = 0;
    while(gets(t)){
        char inp[512] = {'\0'};
        for(i = k = 0; t[i]; ++i){          /* This little optimization lessened runtime by 3 ms, also defining k as register int */
            if(t[i] == 34 && !c){           /* ASCII decimal value of " (Double Quotes) is 34 */
                inp[k] = inp[k+1] = 96;     /* ASCII decimal value of ` (Grave Caret) is 96 */
                k += 2;                     /* We added TWO characters */
                c = 1;                      /* Flag or ON OFF */
            }else if(c && t[i] == 34){
                inp[k] = inp[k+1] = 39;     /* ASCII decimal value of ' (Single Quote) is 39 */
                k += 2;
                c = 0;
            }else{
                inp[k] = t[i];              /* If neither single or Double Quote found */
                ++k;
            }
        }
        printf("%s\n", inp);
    }
    return 0;
}
