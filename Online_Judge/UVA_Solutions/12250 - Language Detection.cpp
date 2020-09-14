#include<stdio.h>
#include<string.h>

int main(){
	int n, c = 1;
	char s[20];
	while(gets(s)){
        if(s[0] == '#' && s[1] == '\0'){
            return 0;
        }
        if(!strcmp(s, "HELLO")){
            printf("Case %d: ENGLISH\n", c);
        }else if(!strcmp(s, "HOLA")){
            printf("Case %d: SPANISH\n", c);
        }else if(!strcmp(s, "HALLO")){
            printf("Case %d: GERMAN\n", c);
        }else if(!strcmp(s, "BONJOUR")){
            printf("Case %d: FRENCH\n", c);
        }else if(!strcmp(s, "CIAO")){
            printf("Case %d: ITALIAN\n", c);
        }else if(!strcmp(s, "ZDRAVSTVUJTE")){
            printf("Case %d: RUSSIAN\n", c);
        }else{
            printf("Case %d: UNKNOWN\n", c);
        }
        ++c;
	}
	return 0;
}
