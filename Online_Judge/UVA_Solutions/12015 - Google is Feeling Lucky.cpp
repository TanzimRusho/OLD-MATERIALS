#include<stdio.h>

static char s[10][100];
static unsigned r[10];

static unsigned c, n, max, i;

int main(){

	scanf("%u", &n);

	while(n--){
        scanf("%s %u", &s[0], &r[0]);
        max = r[0];

        for(i = 1; i < 10; ++i){
            scanf("%s %u", &s[i], &r[i]);
            if(r[i] > max)
                max = r[i];
        }

        printf("Case #%u:\n", ++c);
        for(i = 0; i < 10; ++i){
            if(r[i] == max)
                printf("%s\n", s[i]);
        }
    }
	return 0;
}
