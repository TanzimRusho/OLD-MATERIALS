#include<iostream>
#include<cstdio>
#include<sstream>

#define SIZE 100000

static char buffer[SIZE];
static std::string t;

int main(){
    register unsigned int i, k, c = 0;
    fread(buffer, 1, sizeof buffer, stdin);
    std::stringstream ss(buffer);
    while(getline(ss, t) && t.length()){
        char inp[512] = {'\0'};
        for(i = k = 0; t[i]!='\0'; ++i){
            if(t[i] == 34 && !c){
                inp[k] = inp[k+1] = 96;
                k += 2, c = 1;
            }else if(c && t[i] == 34){
                inp[k] = inp[k+1] = 39;
                k += 2, c = 0;
            }else{
                inp[k] = t[i];
                ++k;
            }
        }
        puts(inp);
    }
    return 0;
}
