/*
 * Author: Quickgrid ( Asif Ahmed )
 * Site: https://quickgrid.wordpress.com
 * Problem: UVA 12541 ( Birth dates  )
 */

#include<stdio.h>

struct person{
    char name[16];
    unsigned int date, month, year;
};

int main(){
    register unsigned int n, i = 0;

    scanf("%u", &n);

    struct person p[n], maxp, minp;

    for(; i<n; ++i){
        scanf("%s%u%u%u", &p[i].name, &p[i].date, &p[i].month, &p[i].year);
    }

    maxp = p[0];    /*younger person*/
    minp = p[0];    /*older person*/

    for(i=0; i<n; ++i){
        if(p[i].year > maxp.year)
            maxp = p[i];

        else if(p[i].year < minp.year)
            minp = p[i];

        else{
            if(p[i].month > maxp.month && p[i].year >= maxp.year)
                maxp = p[i];

            else if(p[i].month < minp.month && p[i].year <= minp.year)
                minp = p[i];

            else{
                if(p[i].date > maxp.date && p[i].month >= maxp.month && p[i].year >= maxp.year)
                    maxp = p[i];
                else if(p[i].date < minp.date && p[i].month <= minp.month && p[i].year <= minp.year)
                    minp = p[i];
            }
        }

    }

    printf("%s\n%s\n", maxp.name, minp.name);

    return 0;
}
