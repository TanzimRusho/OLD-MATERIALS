#include<iostream>
#include<cstdio>
#include<cstdlib>

using namespace std;

struct list{
    int data;
    struct list *next;
    struct list *prev;
};

typedef struct list node;

void display(node *head);
void displayReverse(node *head);
int listLength(node *head);
node *mergeSort(node *a, node *b);
node *reverseList(node *head);
node *insertion(node *head, int newitem);

int main(){
    node *head, *tail, *temp;
    char ans;
    head = NULL;
    tail = NULL;

    do{
        fflush(stdout);
        printf("Do you want to create a new node (y/n)?\n");
        fflush(stdin);
        ans = getchar();
        if(ans-'y'==0){
            int newitem;
            fflush(stdout);
            printf("Enter item to insert to sorted list:\n");
            fflush(stdin);
            scanf("%d", &newitem);
            head = insertion(head, newitem);
        }else{
            break;
        }
    }while(ans-'y'==0);

    if(head==NULL){
        printf("No list to display.\n");
    }else{
        printf("Original List:\n");
        display(head);
        printf("Reversed List:\n");
        displayReverse(head);
        printf("\n");
        printf("Length of the list is: %d\n", listLength(head));
        node *temp1;
        temp1 = reverseList(head);
        printf("Reversed copy of original list:\n");
        display(temp1);
        printf("Reversing Reversed copy of original list:\n");
        displayReverse(temp1);

        printf("Merged and sorted list:\n");
        //temp = mergeSort(head, temp1);
        //display(temp);
    }

    return 0;
}

void display(node *head){
    if(head!=NULL){
        printf("%d ", head->data);
        display(head->next);
    }
    /*
    node *temp;
    temp = head;
    while(temp!=NULL){
        printf("%d\n", temp->data);
        temp=temp->next;
    }
    */
}

void displayReverse(node *head){
    if(head!=NULL){
        displayReverse(head->next);
        printf("%d ", head->data);
    }
}

int listLength(node *head){
    if(head != NULL){
        return 1+listLength(head->next);
    }
}

node *mergeSort(node *a, node *b){
    node *temp = NULL;
    if(a==NULL){
        return b;
    }else if(b==NULL){
        return a;
    }

    if(a->data <= b->data){
        temp = a;
        temp->next = mergeSort(a->next, b);
    }else{
        temp = b;
        temp->next = mergeSort(a, b->next);
    }

    return temp;
}

node *reverseList(node *head){
    node *head1, *temp1, *tail1;
    node *temp;
    temp = head;

    head1=NULL;
    tail1=NULL;

    while(temp!=NULL){
        if(head1==NULL){
            head1=new node();

            head1->data = temp->data;

            head1->next = NULL;
            tail1 = head1;
        }else{
            temp1 = new node();

            temp1->data = temp->data;

            temp1->next = tail1;
            tail1 = temp1;
        }
        temp = temp->next;
    };

    return head;
}

node *insertion(node *head, int newitem){
    node *temp, *tail;

    if(head==NULL || head->data>=newitem){
        head = new node();

        head->data = newitem;
        head->next = NULL;
        tail = head;
    }else{
        tail = head;
        while(tail->next!=NULL && tail->next->data <= newitem){
            tail = tail->next;
        }
        temp = new node();
        temp->data = newitem;
        temp->next = tail->next;
        tail->next = temp;
    }

    return head;
}
