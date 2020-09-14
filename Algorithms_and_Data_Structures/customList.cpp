#include <stdio.h>
#include <stdlib.h>

struct list
{
    int data;
    struct list *next;
    struct list *prev;
};

typedef struct list node;

void  display(node *head)
{
    if(head!=NULL){
        printf("%d", head->data);
        display(head->next);
    }
}

node *insertFirst(node *head, int newitem){
    node *tail, *temp;
    if(head==NULL){
        head = new node();

        head->data = newitem;
        head->next = NULL;
        head->prev = NULL;
        tail = head;
    }else if(head->data >= newitem){
        temp = new node();

        temp->data = newitem;
        temp->next = NULL;
        temp->prev = tail;
        tail->next = temp;
        tail = temp;
    }

    return head;
}

node *insertLast(node *head, int newitem){
     node *tail, *temp;
    if(head==NULL){
       head = new node();
        head->data = newitem;
        head->next = NULL;
        head->prev = NULL;
        tail = head;
    }
    else{
        temp = new node();
        temp->data = newitem;
        temp->next = NULL;
        temp->prev = NULL;

        node *temp1 = head;
        while(temp1!=NULL){
            temp1 = temp1->next;
        }

        temp1->next = temp;
        temp->prev = temp1;
        tail = temp1;
    }

    return head;
}

int main(){
    node *head, *p, *q;

    p = insertFirst(head, 10);
	display(p);
	return 0;
}
