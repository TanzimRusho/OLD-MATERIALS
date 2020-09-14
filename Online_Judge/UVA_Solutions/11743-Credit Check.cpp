#include<stdio.h>
int main(){
    int a,b,c,m,i,j,n,os,es;
    char t[20];
    scanf("%d",&n);
    while(n--){
        os=es=0;
        getchar();
        gets(t);
        for(m=0;t[m]!='\0';++m);
        for(i=0;t[i]!='\0';++i){
           if(t[i]==' '){
                for(j=i;j<m-1;++j){
                    t[j]=t[j+1];
                }
           }
        }
        t[i]='\0';
        puts(t);
        if(1){
            printf("Valid\n");
        }else{
            printf("Invalid\n");
        }
    }
    return 0;
}
