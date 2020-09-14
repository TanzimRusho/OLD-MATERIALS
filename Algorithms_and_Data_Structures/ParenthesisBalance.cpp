/*
 * Author: Quickgrid ( Asif Ahmed )
 * Site: https://quickgrid.wordpress.com
 * Problem: UVA 673 ( Parentheses Balance )
 */

#include<stdio.h>

/**
 * Size for our stack although they said 128 but stack safety
 */
#define SIZE 256

/**
 * Our stack or array to hold parenthesis
 */
static char stack[SIZE];
/**
 * Our stack index counter
 */
int top = -1;

/**
 * Push function of out stack, We basically store the character and increase the counter
 * Checking of stack overflow is not implemented since stack size is large enough for this program
 */
void push(char c){
    stack[++top] = c;
}

/**
 * Set the element in current index to NUL and decrease the index
 * Stack underflow is never happens for this program
 */
void pop(){
    stack[top--] = '\0';
}

int main(){
    register unsigned n, i;
    unsigned char c;

    /**
     * Scan the test case count, getchar() is needed because i used gets() below which takes away my new line if getchar() is not used
     */
    scanf("%u", &n); getchar();

    while (n--){
        stack[SIZE] = {'\0'};
        /**
         * Reset the stack index, meaning we start using our stack array from the beginning
         */
        top = -1;
        /**
         * If no error then error is 0 else if there is error then error is 1
         */
        unsigned error = 0;

        /**
         * Our character array to take the input string
         */
        char *par = new char[SIZE + 1];
        gets(par);

        for (i = 0; par[i]; ++i){
            /**
             * Corner case the input can have space
             */
            if(par[i] == ' ')
                continue;

            /**
             * Push the character to stack if open bracket
             */
            if(par[i] == '[' || par[i] == '(')
                push(par[i]);

            /**
             * Pop or remove the element from top of stack if matching closing bracket found
             */
            else if(par[i] == ']' && stack[top] == '[')
                pop();
            else if(par[i] == ')' && stack[top] == '(')
                pop();

            else{
                /**
                 * If matching closing bracket not found then set error flag to 1 (ON)
                 */
                error = 1;
                /**
                 * Since we found a mistake there is no need to process rest of the string
                 */
                break;
            }
        }

        /**
         * If error flag is on or there still exist some brackets on stack then print NO
         */
        if(error || top > -1)
            printf("No\n");
        else
            printf("Yes\n");
    }
    return 0;
}
