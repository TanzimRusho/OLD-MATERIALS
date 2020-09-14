/*
 * Author: Quickgrid ( Asif Ahmed )
 * Site: http://quickgrid.wordpress.com
 * Problem: UVA 673 ( Parenthesis Balance )
 */

#include<stdio.h>

#define SIZE 256                                              /* Size for our stack although they said 128 but ... */

char stack[SIZE];                                             /* Our stack or array to hold parenthesis */
int top = -1;                                                 /* Our stack index */

void push(char c){                                            /* Push function of out stack, We basically store the character and increase the counter */
    stack[++top] = c;
}

void pop(){
    stack[top--] = '\0';                                      /* Set the element in current index to NUL and decrease the index */
}

int main(){
    register unsigned int n;
    unsigned char c;
    scanf("%u", &n); getchar();                               /* Scan the test case count, getchar() is needed because i used gets() below which takes away my new line if getchar() is not used */
    while(n--){
        stack[SIZE] = {'\0'};
        top = -1;                                             /* Reset my stack index, meaning we start using our stack array from the beginning */
        unsigned int error = 0;                               /* If no error then error is 0 else if there is error then error is 1 */
        char *par = new char[SIZE+1];                         /* Our character array to take the input string */
        gets(par);
        for(register unsigned int i = 0; par[i]; ++i){
            if(par[i] == ' ') continue;                       /* Corner case the input can have space */
            if(par[i] == '[' || par[i] == '(') push(par[i]);  /* Push the character to stack if open bracket */
            else if(par[i] == ']' && stack[top] == '[') pop();/* Pop or remove the element from top of stack if matching closing bracket found */
            else if(par[i] == ')' && stack[top] == '(') pop();
            else{
                error = 1;                                    /* If matching closing bracket not found then set error flag to 1 (ON) */
                break;                                        /* Since we found a mistake there is no need to process rest of the string */
            }
        }
        if(error || top > -1) printf("No\n");                 /* If error flag is on or there still exist some brackets on stack then print NO */
        else printf("Yes\n");
    }
    return 0;
}
