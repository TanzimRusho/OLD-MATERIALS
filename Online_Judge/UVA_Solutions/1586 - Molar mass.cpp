#include<stdio.h>

#define C 12.01
#define N 14.01
#define O 16.00
#define H 1.008

static char s[128];

int main(){
    register int n, i;
    scanf("%d", &n);

    while(n--){
        scanf("%s", &s);
        float sum = 0;

        for(i = 0; s[i]; ++i){
            /**
             * Check if it is a compound identifier
             */
            unsigned compoundCheck = s[i] == 'C' || s[i] == 'N' || s[i] == 'O' || s[i] == 'H';

            /**
             * Has only two digit next to it
             * Check if it is a compound identifier and next two digits are atom count
             */
            if(compoundCheck && (s[i + 1] >= '0' && s[i + 1] <= '9') && (s[i + 2] >= '0' && s[i + 2] <= '9')){

                /**
                 * calculate the weight with first digit in 10's position so multiply with 10
                 * Add that to the next atom count ( digit )
                 * Minus 48 convert char to its integer equivalent
                 */
                unsigned dualDigitAtom = (s[i + 1] - 48) * 10 + s[i + 2] - 48;

                switch(s[i]){
                case 'C':
                    sum += C * dualDigitAtom;
                    break;
                case 'N':
                    sum += N * dualDigitAtom;
                    break;
                case 'O':
                    sum += O * dualDigitAtom;
                    break;
                case 'H':
                    sum += H * dualDigitAtom;
                    break;
                }
            }

            /**
             * Has only one digit next to it
             * Check if it is a compound identifier and next digit is atom count
             */
            else if(compoundCheck && (s[i + 1] >= '0' && s[i + 1] <= '9')){

                unsigned singleDigitAtom = s[i + 1] - 48;

                switch(s[i]){
                case 'C':
                    sum += C * singleDigitAtom;
                    break;
                case 'N':
                    sum += N * singleDigitAtom;
                    break;
                case 'O':
                    sum += O * singleDigitAtom;
                    break;
                case 'H':
                    sum += H * singleDigitAtom;
                    break;
                }
            }

            /**
             * Single atom compound meaning no digit next to it
             */
            else if(compoundCheck && (s[i+1]!='C' || s[i+1]!='N' || s[i+1]!='O' ||s[i+1]!='H')){
                switch(s[i]){
                case 'C':
                    sum += C;
                    break;
                case 'N':
                    sum += N;
                    break;
                case 'O':
                    sum += O;
                    break;
                case 'H':
                    sum += H;
                    break;
                }
            }
        }
        printf("%.3f\n", sum);
    }
    return 0;
}
