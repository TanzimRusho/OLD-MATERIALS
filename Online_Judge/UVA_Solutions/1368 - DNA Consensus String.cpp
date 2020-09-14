/*
 * Author: Quickgrid ( Asif Ahmed )
 * Site: http://quickgrid.wordpress.com
 * Problem: UVA 1368 ( DNA Consensus String )
 */

#include<stdio.h>
int main(){
	register unsigned int n, a, b, i, j, k, error;
	scanf("%u", &n);
	while(n--){
        scanf("%u%u", &a, &b);
        char **s = new char*[a+1];      /* Create the string array */
        for(i=0; i<a; ++i){
            s[i] = new char[b+1];       /* Allocate space for each string */
            scanf("%s", s[i]);          /* Input a string in i th position */
        }
        char *conseq = new char[b+1];   /* Consensus string declaration */
        for(k = i = 0; i<b; ++i){       /* K is used below */
            unsigned int seq[4] = {0};  /* Reset A,C,G,T count array */
            for(j=0; j<a; ++j){
                switch(s[j][i]){
                case 65:                /* 65, 'A' here seq[0] is A */
                    ++seq[0];
                    break;
                case 67:                /* 'C' */
                    ++seq[1];
                    break;
                case 71:                /* 'G' */
                    ++seq[2];
                    break;
                case 84:                /* 'T' */
                    ++seq[3];
                }
            }
            unsigned int max = seq[0], maxIndex = 0;
            for(j=1; j<4; ++j){
                if(seq[j] > max){
                    max = seq[j];       /* Find the max count of A,C,G,T in a column, in all strings */
                    maxIndex = j;       /* Remember the maxIndex for creating consensus string */
                }
            }
            switch(maxIndex){
            case 0:
                conseq[k++] = 65;       /* We keep adding to our consensus string the most count of A,C,G,T */
                break;
            case 1:
                conseq[k++] = 67;
                break;
            case 2:
                conseq[k++] = 71;
                break;
            case 3:
                conseq[k++] = 84;
            }
        }
        for(error = i = 0; i<b; ++i){
            for(j=0; j<a; ++j){
                if(s[j][i] != conseq[i]){   /* Calculate the error count by moving column by column of all strings, then comparing against the consensus string character in that column */
                    ++error;
                }
            }
        }
        printf("%s\n%u\n", conseq, error);  /* Print the consensus string and error count EACH ON A NEW LINE */
	}
	return 0;
}
