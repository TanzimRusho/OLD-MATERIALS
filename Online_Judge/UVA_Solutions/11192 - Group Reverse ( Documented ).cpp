#include<stdio.h>

/*
 * Input string buffer
 */
char s[128];

/*
 * Global index for accessing input array, may be declared inside main
 */
int top = -1;

int main(){
    register unsigned int j,u,n,i,x;

    /*
     * Input group count and Check if count is Not Zero
     */
    while (scanf("%u", &n) && n) {
        scanf("%s", s);

        /*
         * Find out input string size
         */
        for (j = 0; s[j]; ++j);

        /*
         * Find out length of each group
         */
        n = j/n;

        /*
         * Group Reverse loop
         */
        for (x = i = 0; i < j; ++i) {

            /*
             * For checking is the item after is NUL terminator
             */
            u = s[i+1];

            /*
             * @var u
             * If the character after current is NUL then NOT u, is True
             *
             * @var n
             * Check to see if characters in group count is NOT full, then push more to stack
             */
            if ( !u || x != n ) {

                /*
                 * Push current character on top of stack
                 */
                s[++top] = s[i];

                /*
                 * Keep a count of characters pushed on stack
                 */
                ++x;
            }

            /*
             * If character limit per group is reached then Condition is True
             */
            if ( !u || x == n ) {

                /*
                 * Empty the the stack for every pushed character
                 */
                while (x--){

                    /*
                     * Output character by character in reversed form
                     */
                    printf("%c", s[top]);
                    --top;
                }
                x = 0;
            }

        }
        printf("\n");
    }
    return 0;
}
