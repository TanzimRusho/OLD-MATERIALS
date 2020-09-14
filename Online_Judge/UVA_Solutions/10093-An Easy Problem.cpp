#include<stdio.h>
int main(){
    char n;
    while(n=getchar()){
        if(n-'z'==0){
            printf("such number is impossible!\n");
        }else if('2'<= n && n <= '8'){
            printf("%c\n", n+1);
        }else if('9'<= n && n<= 'Y'){
            if(n-'9'==0){
                printf("%c\n", n+8);
            }else{
                printf("%c\n", n+1);
            }
        }else if('Z'<= n && n<= 'y'){
            if(n-'Z'==0){
                printf("%c\n", n+7);
            }else{
                printf("%c\n", n+1);
            }
        }
    }
    return 0;
}
