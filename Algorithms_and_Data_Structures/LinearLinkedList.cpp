#include<stdio.h>
#include<windows.h>

struct list{
    int data;
    list *next;
};

typedef struct list node;

int main(){
    /*
    node *head, *curr, *temp;

    head = new node();
    head->next = NULL;
    head->data = 10;

    curr = new node();
    curr->next = NULL;
    curr->data = 20;

    temp = new node();
    temp->next = NULL;
    temp->data = 30;

    head->next = curr;
    curr->next = temp;


    temp = head;
    while(temp!=NULL){
        printf("%d ", temp->data);
        temp = temp->next;
    }
    */
    node *a, *b, *c, *d, *temp;

    //node creation
    a = new node();
    b = new node();
    c = new node();
    d = new node();

    //address fix
    a->next = NULL;
    b->next = NULL;
    c->next = NULL;
    d->next = NULL;

    //node data set
    a->data = 10;
    b->data = 20;
    c->data = 30;
    d->data = 40;

    //create link
    a->next = b;
    b->next = c;
    c->next = d;
    d->next = a;
    a->next = d;
    c->next = b;
    b->next = a;
    a->next = c;
    c->next = c;

    temp = a;
    while(temp!=NULL){
        Sleep(1000);
        printf("%d ", temp->data);
        temp = temp->next;
    }

    return 0;
}
