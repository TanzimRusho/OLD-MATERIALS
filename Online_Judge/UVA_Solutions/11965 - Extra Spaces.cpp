/**
 * @author  Quickgrid ( Asif Ahmed )
 * @link    http://quickgrid.wordpress.com
 */

#include<cstdio>

static char buffer[1024];

int main(){
	register unsigned int n, m, c = 0;
	scanf("%u", &n);

	while (n--){

        /*
         * Use getchar() before reading a string or character to discard the newline character,
         * Otherwise newline character will be taken taken by the string or character input function
         */
        scanf("%u", &m); getchar();

        /*
         * Only print newline between test cases
         */
        if (c) printf("\n");

        ++c;
        printf("Case %u:\n", c);

        while (m--){
            gets(buffer);

            register unsigned i = 0, spaces = 1;
            unsigned val;

            for (; val = buffer[i]; ++i){

                /*
                 * Since there a two comparisons below do One comparison here
                 */
                val = val == ' ';

                /*
                 * If a space found after non space character then print a space
                 */
                if (val && spaces){
                    printf(" ");
                    spaces = 0;
                    continue;
                }

                /*
                 * If consecutive space are found skip them
                 */
                if (val) continue;

                /*
                 * Print non space characters
                 */
                printf("%c", buffer[i]);
                spaces = 1;
            }
            printf("\n");
        }
	}
	return 0;
}
