#include<stdio.h>
#include<string.h>

static char stack[256];
static char par[256];
int top;

int main(){
    unsigned n, error, i;

    scanf("%u", &n);
    getchar();

    while(n--){
        gets(par);

        if(strlen(par) & 1)
            printf("No\n");
        else{
            stack[256] = {'\0'};
            top = -1;
            error = i = 0;

            for(; par[i]; ++i){
                if(par[i] == '[' || par[i] == '(')
                    stack[++top] = par[i];
                else if((par[i] == ')' && stack[top] == '(') || (par[i] == ']' && stack[top] == '['))
                    --top;
                else{
                    error = 1;
                    break;
                }
            }

            (error || top > -1) ? printf("No\n") : printf("Yes\n");
        }
    }
    return 0;
}
