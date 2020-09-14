#include<stdio.h>

struct person{
    char name[16];
    int date, month, year;
};
typedef struct person per;

int main(){
    int n,i;
    int maxDate, minDate;
    scanf("%d", &n);
    per *p[n], *young, *old;
    for(i=0; i<n; ++i){
        scanf("%s%d%d%d", &p[i]->name, &p[i]->date, &p[i]->month, &p[i]->year);
    }
    young = p[0];    /*younger person*/
    old = p[0];    /*older person*/
    for(i=0; i<n; ++i){
        if(p[i]->year > young->year){
            young = p[i];
        }else if(p[i]->year < old->year){
            old = p[i];
        }else{
            if(p[i]->month > young->month && p[i]->year >= young->year){
                young = p[i];
            }else if(p[i]->month < old->month && p[i]->year <= old->year){
                old = p[i];
            }else{
                if(p[i]->date > young->date && p[i]->month >= young->month && p[i]->year >= young->year){
                    young = p[i];
                }else if(p[i]->date < old->date && p[i]->month <= old->month && p[i]->year <= old->year){
                    old = p[i];
                }
            }
        }
    }
    printf("%s\n", young->name);
    printf("%s\n", old->name);
    return 0;
}
