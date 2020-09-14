#include<stdio.h>
int main(){
	unsigned int a,b;
	while(scanf("%u%u", &a, &b)==2){
        unsigned int num = 0, same = 0;
        while(1){
            char s[4] = {0};
            unsigned int len = 0, temp = a, k = 0;
            while(temp){
                temp /= 10;
                ++len;
            }
            temp = a;
            switch(len){
            case 2:
                s[0] = temp%10 +48;
                s[1] = temp/10 +48;
                break;
            case 3:
                s[0] = temp%10 +48;
                temp /= 10;
                s[1] = temp%10 +48;
                temp /= 10;
                s[2] = temp +48;
                break;
            case 4:
                s[0] = temp%10 +48;
                temp /= 10;
                s[1] = temp%10 +48;
                temp /= 10;
                s[2] = temp%10 +48;
                temp /= 10;
                s[3] = temp +48;
                break;
            }
            unsigned int found = 0, i, j;
            for(i=0; s[i]!='\0'; ++i){
                for(j=i+1; s[j]!='\0'; ++j){
                    if(s[i] == s[j]){
                        ++same;
                        found = 1;
                        break;
                    }
                }
                if(found) break;
            }
            if(a==b){
                break;
            }
            ++a;
            ++num;
        }
        printf("%u\n", num-same+1);
	}
	return 0;
}
