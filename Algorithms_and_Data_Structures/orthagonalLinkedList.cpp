#include<iostream>
#include<stdio.h>
#include<cstring>

using namespace std;

struct list{
    int data;
    int row;
    int column;
    struct list *next;
    struct list *prev;
};

typedef struct list node;

void display(node *head){
    node *temp;

    temp = head;
    while(temp!=NULL){
        printf("%d", temp->data);
        temp = temp->next;
    }
}

int main(){
    node *head, *tail, *temp;
    char ans;
    int i=0, j=0;

    head = NULL;

    while(1){
        fflush(stdout);
        printf("Create new node: (y/n)?\n");
        fflush(stdin);
        ans = getchar();

        if(ans - 'y' == 0){
            if(head==NULL){
                head = new node();
                printf("Enter data:\n");
                scanf("%d", &head->data);
                head->row = i;
                head->column = j;
                ++i, ++j;
                head->next = NULL;
                tail = head;
            }else{
                temp = new node();
                printf("Enter data:\n");
                scanf("%d", &temp->data);
                temp->row = i;
                temp->column = j;
                ++i, ++j;
                temp->next = NULL;
                tail->next = temp;
                tail = temp;
            }
        }else{
            break;
        }
    }

    if(head==NULL){
        printf("List is empty.\n");
    }else{
        display(head);
    }

    return 0;
}
