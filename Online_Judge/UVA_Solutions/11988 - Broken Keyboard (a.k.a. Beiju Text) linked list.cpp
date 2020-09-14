/**
 * Author:    Asif Ahmed
 * Site:      https://quickgrid.wordpress.com
 * Problem:   UVA
 * Technique:
 */

#include<stdio.h>
#include<string.h>


#define N 100000

static char input[N];


struct vertex{
    char c;
    struct vertex* next;
};

typedef struct vertex node;


node* insertNode(node* n, char c){

    node* temp = new node();
    temp->c = c;
    temp->next = n->next;
    n->next = temp;

    return temp;
}


void printList( node* dummy ){

    node* tmp = dummy;

    while( tmp = tmp->next )
        putchar( tmp->c );

    printf("\n");
}


int main(){

    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);


    while( gets(input) ){

        node* dummy = new node();
        dummy->next = NULL;
        node* cur = dummy;


        for(int i = 0; input[i]; ++i){

            if( input[i] == '[' ){
                cur = dummy;
                continue;
            }
            if( input[i] == ']' ){
                node *tmp = cur;
                while( tmp->next != NULL ){
                    tmp = tmp->next;
                }
                cur = tmp;
                continue;
            }

            cur = insertNode(cur, input[i] );

        }

        printList( dummy );

    }


    return 0;
}
