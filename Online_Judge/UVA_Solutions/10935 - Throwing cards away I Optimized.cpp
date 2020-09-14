/*
 * @author quickgrid ( Asif Ahmed )
 * @link   https://quickgrid.wordpress.com
 */

#include<stdio.h>
#define size 128

/*
 * unsigned since no item in our array is negative
 */
static unsigned a[size];
unsigned f = 0, r = 0;

void enqueue(unsigned k){
    /*
     * get a valid index in circular queue array
     */
    unsigned s = (r + 1) % (size + 1);

    /*
     * set the last element to given card
     */
    a[s] = k;
    /*
     * update the rear position marker
     */
    r = s;
}

unsigned dequeue(){
    /*
     * move the front marker one position in circular queue array
     */
    f = (f + 1) % (size + 1);
    /*
     * keep the value of last card for returning
     */
    unsigned k = a[f];
    a[f] = 0;
    return k;
}

int main(){
    register unsigned n, i;

    while (scanf("%u", &n) && n){
        /*
         * since there is one card there is no discarded card
         */
        if (n == 1){
            printf("Discarded cards:\n");
            printf("Remaining card: 1\n");
            continue;
        }

        f = 0, r = 0;
        for (i = 1; i <= n; ++i){
            /*
             * it says 1 to n cards on deck so i enqueue all cards serially
             */
            enqueue(i);
        }

        printf("Discarded cards: ");
        /*
         * stop when 2 cards on deck
         */
        while (f + 2 != r){
            printf("%u, ", dequeue());
            unsigned k = dequeue();
            enqueue(k);
        }

        /*
         * get position of last discardable card
         */
        f = (f + 1) % (size + 1);

        /*
         * print the last discardable card
         */
        printf("%u\n", a[f]);
        /*
         * now print the last remaining card on deck
         */
        printf("Remaining card: %u\n", a[r]);
    }
    return 0;
}
