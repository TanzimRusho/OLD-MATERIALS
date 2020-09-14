#include<iostream>
#include<cstdio>
using namespace std;
int main(){
	unsigned int n;
    string s;
	scanf("%u", &n);
	getchar();
	while(n--){
        getline(cin, s);
        unsigned int i = 0, A = 0, I = 0, G = 0, M = 0, R = 0, T = 0, pizza = 0;
        for(; s[i]!='\0'; ++i){
            switch(s[i]){
            case 'A':
                ++A;
                break;
            case 'I':
                ++I;
                break;
            case 'G':
                ++G;
                break;
            case 'M':
                ++M;
                break;
            case 'R':
                ++R;
                break;
            case 'T':
                ++T;
                break;
            }
        }
        while(M>=1 && A>=3 && R>=2 && G>=1 && I>=1 && T>=1){
            ++pizza;
            --G;
            --I;
            --T;
            --M;
            R -= 2;
            A -= 3;
        }
        printf("%u\n", pizza);
	}
	return 0;
}
