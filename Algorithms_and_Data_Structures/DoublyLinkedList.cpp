#include<stdio.h>

struct list{
    int data;
    struct list *next;
    struct list *prev;
};

typedef struct list node;

int main(){
    node *head, *tail, *temp;

    head = new node();
    temp = head;
    tail = head;

    head->data = 10;
    head->prev = NULL;

    head = new node();
    head->data = 20;
    head->prev = tail;
    tail->next = head;
    tail = head;

    head = new node();
    head->data = 30;
    head->prev = tail;
    tail->next = head;
    tail = head;

    head = new node();
    head->data = 40;
    head->prev = tail;
    tail->next = head;
    tail = head;

    tail->next = NULL;

    while(temp!=NULL){
        printf("%d ", temp->data);
        temp = temp->next;
    }

    return 0;
}
