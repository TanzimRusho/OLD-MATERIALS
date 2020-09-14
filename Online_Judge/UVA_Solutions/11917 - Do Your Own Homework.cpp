#include<stdio.h>
#include<string.h>

int main(){
	int n, freq, m, i, c = 1;
	char a[101][101], sub[101];
	int b[101];
	int flag;
	scanf("%d", &n);
	while(n--){
        flag = 0;
        scanf("%d", &m);
        for(i=0; i<m; ++i){
            scanf("%s %d", &a[i], &b[i]);
        }
        scanf("%d", &freq);
        scanf("%s", &sub);

        for(i=0; i<m; ++i){
            if(!strcmp(a[i], sub)){
                if(b[i] <= freq){
                    flag = 1;
                }else{
                    flag = 2;
                }
                break;
            }else{
                flag = 0;
            }
        }

        if(flag == 1){
            printf("Case %d: Yesss\n", c);
        }else if(flag == 2){
            printf("Case %d: Late\n", c);
        }else{
            printf("Case %d: Do your own homework!\n", c);
        }

        ++c;
	}
	return 0;
}
