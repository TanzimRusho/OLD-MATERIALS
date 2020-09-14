#include<iostream>
#include<cstdio>
#include<cstring>
#include<cmath>
using namespace std;
int main(){
	unsigned int n, c = 1;
	scanf("%d", &n);
	while(n--){
        char s[30], orgstr[30];
        unsigned int sum = 0, x = 0;
        scanf("%s", s);
        strcpy(orgstr, s);
        while(x==0 || strlen(s)!=1){
            x = 1;
            unsigned int i;
            for(i=0; s[i]!='\0'; ++i){
                sum += pow(s[i]-48, 2);
                printf("%d %f\n", sum, pow(s[i]-48, 2));
            }
            unsigned int tmpsum = sum, len = 0;
            while(tmpsum){
                ++len;
                tmpsum /= 10;
            }
            for(i=0; s[i]!='\0'; ++i){
                s[i] = 0;
            }
            for(i=0; i<len; ++i){
                s[i] = (sum%10) +48;
                printf("%c\n", s[i]);
                sum /= 10;
            }
            s[len] = '\0';
            strrev(s);
        }
        if(s[0]=='1'){
            printf("Case #%d: %s is a Happy number.\n", c++, orgstr);
        }else{
            printf("Case #%d: %s is an Unhappy number.\n", c++, orgstr);
        }
	}
	return 0;
}
