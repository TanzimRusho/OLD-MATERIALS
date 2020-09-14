#include<stdio.h>
int main(){
	register unsigned int n, c = 1;
	scanf("%u", &n);
	while(n--){
        register unsigned int m, i;
        unsigned int A = 0, B = 0, T = 0, W = 0;
        char s[11];
        scanf("%u%s", &m, &s);
        for(i=0; i<m; ++i){
            switch(s[i]){
            case 65:    /* or use 'A' instead of 65 (ASCII) but using 65 is faster */
                ++A;
                break;
            case 66:    /* or use 'B' instead of 66 (ASCII) but using 66 is faster */
                ++B;
                break;
            case 84:    /* or use 'T' instead of 84 (ASCII) but using 84 is faster */
                ++T;
                break;
            case 87:    /* or use 'W' instead of 87 (ASCII) but using 87 is faster */
                ++W;
                break;
            }
        }
        if(A == m){                         /* All matches are abandoned */
            printf("Case %u: ABANDONED\n",c);
        }else if(B+A == m){                 /* If Bangladesh won all the matches, except for Abandoned ones */
            printf("Case %u: BANGLAWASH\n",c);
        }else if(W+A == m){                 /* If WWW won all the matches, except for Abandoned ones */
            printf("Case %u: WHITEWASH\n",c);
        }else if(B>W){                      /* Bangladesh won more matches then WWW */
            printf("Case %u: BANGLADESH %u - %u\n",c,B,W);
        }else if(B<W){                      /* WWW won more matches then Bangladesh */
            printf("Case %u: WWW %u - %u\n",c,W,B);
        }else{                              /* Win count for both team is tied */
            printf("Case %u: DRAW %u %u\n",c,B,T);
        }
        ++c;
	}
	return 0;
}
