#include<stdio.h>
int main()
{
    register unsigned t,i;
    unsigned d1,d2,m1,m2,y1,y2;

    while(scanf("%u",&t)==1)
    {
        for(i=1; i<=t; ++i)
        {
            scanf("%u/%u/%u",&d2,&m2,&y2);
            scanf("%u/%u/%u",&d1,&m1,&y1);

            if(d1 > d2)
                ++m1;

            if(m1 > m2)
                ++y1;

            int age = y2 - y1;

            if(age < 0)
                printf("Case #%d: Invalid birth date\n",i);
            else if(age > 130)
                printf("Case #%d: Check birth date\n",i);
            else
                printf("Case #%d: %d\n",i,age);
        }
    }
    return 0;
}
