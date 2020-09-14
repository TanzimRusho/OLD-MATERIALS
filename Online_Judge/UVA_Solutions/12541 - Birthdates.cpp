#include<stdio.h>

struct person{
    char name[16];
    int date, month, year;
};

int main(){
    int n,i;
    int maxDate, minDate;
    scanf("%d", &n);
    struct person p[n], maxp, minp;
    for(i=0; i<n; ++i){
        scanf("%s%d%d%d", &p[i].name, &p[i].date, &p[i].month, &p[i].year);
    }
    maxp = p[0];    /*younger person*/
    minp = p[0];    /*older person*/
    for(i=0; i<n; ++i){
        if(p[i].year > maxp.year){
            maxp = p[i];
        }else if(p[i].year < minp.year){
            minp = p[i];
        }else{
            if(p[i].month > maxp.month && p[i].year >= maxp.year){
                maxp = p[i];
            }else if(p[i].month < minp.month && p[i].year <= minp.year){
                minp = p[i];
            }else{
                if(p[i].date > maxp.date && p[i].month >= maxp.month && p[i].year >= maxp.year){
                    maxp = p[i];
                }else if(p[i].date < minp.date && p[i].month <= minp.month && p[i].year <= minp.year){
                    minp = p[i];
                }
            }
        }
    }
    printf("%s\n", maxp.name);
    printf("%s\n", minp.name);
    return 0;
}
