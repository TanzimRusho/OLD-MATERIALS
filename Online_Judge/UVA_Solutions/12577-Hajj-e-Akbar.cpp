#include<stdio.h>
#include<string.h>
int main(){
    int c=0;
    char a[10];
    while(gets(a)){
        if(!strcmp(a,"*")) return 0;
        ++c;
        if(!strcmp(a,"Hajj")) printf("Case %d: Hajj-e-Akbar\n",c);
        else if(!strcmp(a,"Umrah")) printf("Case %d: Hajj-e-Asghar\n",c);
    }
    return 0;
}
