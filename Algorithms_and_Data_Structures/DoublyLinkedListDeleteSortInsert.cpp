#include<iostream>
#include<cstdio>
#include<ctype.h>

using namespace std;

struct list{
    int data;
    struct list *next;
    struct list *prev;
};

typedef struct list node;

void display(node *head);
node *searchAndDestroy(node *head, int item);

int main(){
    node *head, *tail, *temp;
    head=NULL;
    tail=NULL;
    char ans;

    do{
        fflush(stdout);
        printf("Do you want to create a new node (y/n)?\n");
        fflush(stdin);
        ans = tolower(getchar());
        if(ans-'y'==0){
            if(head==NULL){
                head = new node();
                fflush(stdout);
                printf("Enter data:\n");
                fflush(stdin);
                scanf("%d", &head->data);

                head->next = NULL;
                head->prev = NULL;
                tail = head;
            }else{
                temp = new node();
                fflush(stdout);
                printf("Enter data:\n");
                fflush(stdin);
                scanf("%d", &temp->data);

                temp->next = tail;
                temp->prev = NULL;
                tail->prev = temp;
                tail = temp;
            }
        }else{
            //circular doubly linked list
            //head->next = tail;
            //tail->next = head;
            break;
        }
    }while(ans-'y'==0);

    if(tail==NULL){
        printf("No list available\n");
    }else{
        printf("Before inversion:\n");
        display(tail);
    }

    //
    node *head1, *tail1, *temp1;
    head1 = NULL;
    tail1 = NULL;

    while(temp!=NULL){
        if(tail1 == NULL){
            head1 = new node();

            head1->data = temp->data;

            head1->next = NULL;
            head1->prev = NULL;
            tail1 = head1;
        }else{
            temp1 = new node();

            temp1->data = temp->data;

            temp1->next = tail1;
            temp1->prev = NULL;
            tail1->prev = temp1;
            tail1 = temp1;
        }

        temp = temp->next;
    }
    //circular doubly linked list
    //head1->next = tail1;
    //tail1->next = head1;

    if(tail1==NULL){
        printf("No list available\n");
    }else{
        printf("After inversion:\n");
        display(tail1);
    }

    //
    printf("Adding the original and inverted list:\n");
    head->next = tail1;
    display(tail);

    //
    node *tempdel;
    int item;
    printf("Enter item to find and delete:\n");
    scanf("%d", &item);
    printf("\n");
    tempdel = searchAndDestroy(tail, item);
    printf("New list after deletion:\n");
    display(tempdel);


    delete temp1, temp, head, head1, tempdel, tail, tail1;

    return 0;
}

void display(node *head){
    node * temp;
    temp = head;
    //char message[] = "Error here";
    while(temp!=NULL){
        //try{
            printf("%d\n", temp->data);
            temp = temp->next;
            //temp = temp->prev;
        //   throw message;
        //}catch(char *message){
        //    puts(message);
        //}
    }
}

node *searchAndDestroy(node *head, int item){
    node * temp;
    temp = head;
    if(head->data == item){
        head = head->next;
    }
    else{
        temp = temp->next;
        while(temp!=NULL){
            if(temp->data == item){
                temp->prev->next = temp->next;
                temp->next->prev = temp->prev;
            }
            temp = temp->next;
        }
    }
    return head;
}
