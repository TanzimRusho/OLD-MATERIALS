#include<stdio.h>

int main(){
	int n,i,j;
	scanf("%d", &n);
	while(n--){
        char s[2][101]={"",""};
        int upcase[2][26], lowcase[2][26];
        for(j=0; j<2; ++j){
            for(i=0; i<26; ++i){
                upcase[j][i] = 0;
                lowcase[j][i]  = 0;
            }
        }
        scanf("%s", &s[0]);
        scanf("%s", &s[1]);
        puts(s[0]);
        puts(s[1]);
        for(i=0; s[0][i]!='\0'; ++i){
            for(j=0; j<26; ++j){
                if(s[0][i] == 'a'+j){
                    ++lowcase[0][j];
                }else if(s[0][i] == 'A'+j){
                    ++upcase[0][j];
                }
            }
        }

        for(i=0; s[1][i]!='\0'; ++i){
            for(j=0; j<26; ++j){
                if(s[1][i] == 'a'+j){
                    ++lowcase[1][j];
                }else if(s[1][i] == 'A'+j){
                    ++upcase[1][j];
                }
            }
        }

        for(j=0; j<26; ++j){
            for(i=0; i<26; ++i){
                if(j == 0){
                    if(lowcase[0][i]!=0){
                        printf("%c is : %d\n", 'a'+i, lowcase[0][i]);
                    }
                }else{
                    if(upcase[0][i]!=0){
                        printf("%c is : %d\n", 'A'+i, upcase[0][i]);
                    }
                }
            }
        }

        for(j=0; j<26; ++j){
            for(i=0; i<26; ++i){
                if(j == 0){
                    if(lowcase[1][i]!=0){
                        printf("%c is : %d\n", 'a'+i, lowcase[1][i]);
                    }
                }else{
                    if(upcase[1][i]!=0){
                        printf("%c is : %d\n", 'A'+i, upcase[1][i]);
                    }
                }
            }
        }
	}
	getchar();
	return 0;
}
