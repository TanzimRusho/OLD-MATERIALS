#include<stdio.h>
#include<time.h>
#include<stdlib.h>

struct list{
    int data;
    struct list *next;
};

typedef struct list node;

node *insertNode(node *head, int item){
    node *temp, *temp1;

    temp = head;
    temp1 = new node();
    temp1->data = item;
    temp1->next = temp;
    temp = temp1;
    return temp1;
    /*
    temp = head;
    if(head == NULL){
        temp1 = new node();
        temp1->data = item;
        temp1->next = temp;
        temp = temp1;
        return temp;
    }
    else{
        while((temp->next!=NULL) && (temp->next->data <= item)){
            temp = temp->next;
        }
        temp1 = new node();
        temp1->data = item;
        temp1->next = temp->next;
        temp->next = temp1;
        return head;
    }
    */
}

node *deleteNode(node *head, int item){
    node *temp, *temp1;
    temp = head;
    if(head==NULL){
        printf("No linked List\n");
    }else if(head->data == item){
        temp1 = head;
        head = head->next;
        delete temp1;
    }else{
        while((temp->next!=NULL) && (temp->next->data!=item)){
            temp = temp->next;
        }
        if(temp->next==NULL){
            printf("Item not found.\n");
        }else{
            temp1 = temp->next;
            temp->next = temp1->next;
            delete temp1;
        }
    }
    return head;
}

node *createNode(node *head, int p){
    node *temp=NULL, *tail;
    temp = head;

    for(int i=1; i<=p; i++){
        tail = new node;
        tail->data = i;
        tail->next = temp;
        temp = tail;
    }

    return temp;
}



void display(node *head){
    node *temp;
    temp = head;
    while(temp!=NULL){
        printf("%d\n", temp->data);
        temp = temp->next;
    }
}

int main(){
    srand(time(NULL));
    char ans;
    int p,k,n,item;
    node *head = NULL, *temp, *tail, *deleted=NULL;
    node *tail1, *temp1=NULL, *head1;
    temp1 = tail1 = head1 = NULL;

    while(1){
        fflush(stdout);
        printf("Play Game (y/n)?\n");
        fflush(stdin);
        ans = getchar();
        if(ans - 'y'==0){
            fflush(stdout);
            printf("Enter number of players:\n");
            fflush(stdin);
            scanf("%d", &p);
            head = createNode(head, p);
        }else{
            break;
        }

        /*
        if(head == NULL){
            printf("No linked list to display.\n");
        }else{
            display(head);
        }
        */

        k = p;
        while(head->next!=NULL){
            read:
            temp1 = deleted;
            item = rand()%k +1;
            while(temp1!=NULL){
                if(temp1->data == item){
                    goto read;
                }
                temp1 = temp1->next;
            }
            head = deleteNode(head, item);
            deleted = insertNode(deleted, item);
        }

        if(head == NULL){
            printf("No linked list to display.\n");
        }else{
            printf("winner:\n");
            display(head);
        }

        if(deleted == NULL){
            printf("No linked list to display.\n");
        }else{
            printf("Other players:\n");
            display(deleted);
        }
    }

    return 0;
}
