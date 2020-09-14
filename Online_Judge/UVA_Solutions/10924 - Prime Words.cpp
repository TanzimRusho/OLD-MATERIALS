#include<stdio.h>
#include<math.h>
int main(){
    char s[21];
	while(gets(s)){
        unsigned int i, sum = 0;
        for(i=0; s[i]!='\0'; ++i){
            if(s[i]>='a' && s[i]<='z'){
                sum += s[i]-'a'+1;
            }else{
                sum += s[i]-'A'+27;
            }
        }
        if(sum <= 2){
            printf("It is a prime word.\n");
        }else if(sum % 2 == 0){
            printf("It is not a prime word.\n");
        }else{
            unsigned char prime = 1;
            for(i=3; i<=sqrt(sum); i+=2){
                if(sum % i == 0){
                    printf("It is not a prime word.\n");
                    prime = 0;
                    break;
                }
            }
            if(prime){
                printf("It is a prime word.\n");
            }
        }
	}
	return 0;
}
