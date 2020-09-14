#include<stdio.h>
int main(){
    unsigned int n, i, i1, i2;
    char s[80];
    scanf("%d", &n);
    while(n--){
        scanf("%s", &s);
        float val, sum = 0;
        for(i=0; s[i]!='\0'; ++i){
            i1 = s[i+1];
            i2 = s[i+2];
            switch(s[i]){
            case 67:
                if((i1>=48 && i1<=57) && (i2>=48 && i2<=57)){
                    sum += (12.01*i1*10)+12.01*i2-6341.28;
                    break;
                }else if(i1>=48 && i1<=57){
                    sum += 12.01*i1-576.48;
                    break;
                }else{
                    sum += 12.01;
                    break;
                }
            case 72:
                if((i1>=48 && i1<=57) && (i2>=48 && i2<=57)){
                    sum += (1.008*i1*10)+1.008*i2-532.224;
                    break;
                }else if(i1>=48 && i1<=57){
                    sum += 1.008*i1-48.384;
                    break;
                }else{
                    sum += 1.008;
                    break;
                }
            case 78:
                if((i1>=48 && i1<=57) && (i2>=48 && i2<=57)){
                    sum += (14.01*i1*10)+14.01*i2-7397.28;
                    break;
                }else if(i1>=48 && i1<=57){
                    sum += 14.01*i1-196.14;
                    break;
                }else{
                    sum += 14.01;
                    break;
                }
            case 79:
                if((i1>=48 && i1<=57) && (i2>=48 && i2<=57)){
                    sum += (16.00*i1*10)+16.0*i2-8448.0;
                    break;
                }else if(i1>=48 && i1<=57){
                    sum += 16.0*i1-768.0;
                    break;
                }else{
                    sum += 16.0;
                    break;
                }
            }
        }
        printf("%.3f\n", sum);
    }
    return 0;
}
