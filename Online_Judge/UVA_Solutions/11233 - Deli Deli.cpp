#include<stdio.h>
#include<string.h>

int main(){
	int m,n,i,j,flag;
	char singular[21][21], plural[21][21], word[21];
	scanf("%d%d", &m, &n);
        for(i=0; i<m ; ++i){
            scanf("%s %s", &singular[i], &plural[i]);
        }
        for(i=0; i<n; ++i){
            flag = 0;
            scanf("%s", &word);
            for(j=0; j<m; ++j){
                if(!strcmp(word, singular[j])){
                    printf("%s\n", plural[j]);
                    flag = 1;
                    break;
                }
            }

            if(flag == 0){
                for(j=0; word[j]!='\0'; ++j);
                if(word[j-1] == 'y' && word[j-2] != 'a' && word[j-2] != 'e' && word[j-2] != 'i' && word[j-2] != 'o' && word[j-2] != 'u'){
                    word[j-1] = '\0';
                    printf("%sies\n", word);
                }else if(word[j-1] == 'o' || word[j-1] == 's' || word[j-1] == 'x'){
                    printf("%ses\n", word);
                }else if(word[j-1] == 'h' && (word[j-2] == 'c' || word[j-2] == 's')){
                    printf("%ses\n", word);
                }else{
                    printf("%ss\n", word);
                }
            }
        }

	return 0;
}
