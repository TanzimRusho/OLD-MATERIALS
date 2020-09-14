/**
 * Author:    Asif Ahmed
 * Site:      https://quickgrid.wordpress.com
 * Problem:   UVA 11988 - broken keyboard
 * Technique: Doubly Linked List with
 *            dummy tail node as Pointer.
 */

#include<stdio.h>
#include<string.h>


#define N 100000


static char input[N];



// Doubly linked list.
struct vertex{
    char c;
    struct vertex* next;
    struct vertex* prev;
};
typedef struct vertex node;



node* insertNode(node* n, char c){

    // Create the new node to hold current character.
    node* temp = new node();
    temp->c = c;


    // Create forward connection from this created node
    // to the next node of passed in node (n).
    // Also create backward connection from the passed
    // in node to current node.
    temp->next = n->next;
    n->next->prev = temp;


    // Create forward connection from passed in node (n) to the
    // newly created node (temp).
    // Also create backward connection from created node to the
    // passed in node.
    n->next = temp;
    temp->prev = n;


    // return the pointer to the current node.
    return temp;
}



void printList( node* dummy ){

    // Dummy (head) is not a part of output.
    node* tmp = dummy->next;


    // Since I use tail pointer, check if its tail.
    while( tmp->c ){
        putchar( tmp->c );
        tmp = tmp->next;
    }

    printf("\n");
}



int main(){

    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);


    while( gets(input) ){

        // Dummy node is just to keep track of beginning.
        // It does not contain any input character.
        // Tail is used to insert before the last node.
        // Tail is also another dummy node keeps track of
        // the end.
        node* dummy = new node();
        node* tail = new node();


        // NULL may not be necessary since I use tail character
        // checking to stop printing.
        tail->prev = dummy;
        dummy->next = tail;
        tail->next = NULL;
        dummy->prev = NULL;


        // Set current node to dummy (beginning). Set tail
        // to NULL character equivalent ASCII value.
        node* cur = dummy;
        tail->c = 0;


        for(int i = 0; input[i]; ++i){

            // Update node pointer to beginning based on bracket.
            // If not bracket use previous pointer location.
            if( input[i] == '[' ){
                cur = dummy;
                continue;
            }
            if( input[i] == ']' ){
                cur = tail->prev;
                continue;
            }

            cur = insertNode(cur, input[i] );
        }


        // Print output characters one by one.
        printList( dummy );

    }


    return 0;
}
