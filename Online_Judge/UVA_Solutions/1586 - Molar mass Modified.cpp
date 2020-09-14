#include<stdio.h>

#define C 12.01
#define N 14.01
#define O 16.00
#define H 1.008

int main(){
    register unsigned int n, i;
    char s[80];
    scanf("%d", &n);
    while(n--){
        scanf("%s", &s);
        float sum = 0.0;
        for(i=0; s[i]!='\0';){
            switch(s[i]){
            case 'C':
                if((s[i+1]>='0' && s[i+1]<='9') && (s[i+2]>='0' && s[i+2]<='9')){
                    sum += C*(s[i+2]-48+(s[i+1]-48)*10);
                }else if(s[i+1]>='0' && s[i+1]<='9'){
                    sum += C*(s[i+1]-48);
                }else{
                    sum += C;
                }
                break;
            case 'N':
                if((s[i+1]>='0' && s[i+1]<='9') && (s[i+2]>='0' && s[i+2]<='9')){
                    sum += N*(s[i+2]-48+(s[i+1]-48)*10);
                }else if(s[i+1]>='0' && s[i+1]<='9'){
                    sum += N*(s[i+1]-48);
                }else{
                    sum += N;
                }
                break;
            case 'O':
                if((s[i+1]>='0' && s[i+1]<='9') && (s[i+2]>='0' && s[i+2]<='9')){
                    sum += 0*(s[i+2]-48+(s[i+1]-48)*10);
                }else if(s[i+1]>='0' && s[i+1]<='9'){
                    sum += 0*(s[i+1]-48);
                }else{
                    sum += 0;
                }
                break;
            case 'H':
                if((s[i+1]>='0' && s[i+1]<='9') && (s[i+2]>='0' && s[i+2]<='9')){
                    sum += H*(s[i+2]-48+(s[i+1]-48)*10);
                }else if(s[i+1]>='0' && s[i+1]<='9'){
                    sum += H*(s[i+1]-48);
                }else{
                    sum += H;
                }
                break;
            }
        }
        printf("%.3f\n", sum);
    }
    return 0;
}
