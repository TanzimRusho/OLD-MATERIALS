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


        node* tail = dummy;

        bool rightopen = false;

        for(int i = 0; input[i]; ++i){

            if( input[i] == '[' ){
                cur = dummy;
                rightopen = true;
                continue;
            }
            if( input[i] == ']' ){
                rightopen = false;

                node *tmp = tail;

                while( tmp->next != NULL )
                    tmp = tmp->next;

                tail = cur = tmp;
                continue;
            }

            cur = insertNode(cur, input[i] );
            if( !rightopen )
                tail = cur;
        }

        printList( dummy );

    }


    return 0;
}
