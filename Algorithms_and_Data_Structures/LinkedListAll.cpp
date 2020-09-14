#include<stdio.h>
#include<stdlib.h>
#include<ctype.h>

struct list{
    int data;
    struct list *next;
    struct list *prev;
};
typedef struct list node;

void inputTaker(node *head);
node *bubbleSort(node *head, int dir);
node *insertNode(node *head, int item);
node *deleteNode(node *head, int item);
node *middleNode(node *head, node *tail);
node *binarySearch(node *head, node *tail, int item);
void display(node *head, int dir);

int main(){
    char ans;
    node *head,*tail,*temp;
    head = tail = temp = NULL;
    do{
        fflush(stdout);
        printf("Create new node (y/n)?\n");
        fflush(stdin);
        ans = tolower(getchar());
        if(ans-'y'==0){
            if(head==NULL){
                head = new node();
                inputTaker(head);
                head->next = NULL;
                head->prev = NULL;
                tail = head;
            }else{
                temp = new node();
                inputTaker(temp);
                temp->next = NULL;
                temp->prev = tail;
                tail->next = temp;
                tail = temp;
            }
        }else{
            break;
        }
    }while(ans-'y'==0);

    if(head==NULL){
        printf("List doesn't exist\n");
    }else{
        node *newHead;
        newHead = head;
        //display(head, 0);
        //display(temp, 1);
        display(bubbleSort(head, 0), 0);

        int item;
        printf("Enter item to find:\n");
        scanf("%d", &item);
        if(binarySearch(newHead, tail, item)==NULL){
            printf("Item doesn't exist.\n");
        }else{
            printf("%d is in the list\n", item);
        }

        /*
        //use while loop here
        int item;
        printf("Delete node value:\n");
        scanf("%d", &item);
        newHead = deleteNode(newHead, item);
        display(newHead, 0);
        //display(bubbleSort(newHead,0),0);

        //use while loop here
        printf("Insert node value:\n");
        scanf("%d", &item);
        newHead = insertNode(newHead, item);
        display(newHead, 0);
        //display(bubbleSort(newHead,0),0);
        */
    }

    return 0;
}

void inputTaker(node *head){
    fflush(stdout);
    printf("Enter data:\n");
    fflush(stdin);
    scanf("%d",&head->data);
}

node *bubbleSort(node *head, int dir){
    int temp;
    node *p,*q;
    p = head;
    while(p!=NULL){
        q = p->next;
        while(q!=NULL){
            if(dir == 0){
                if(p->data > q->data){
                    temp = p->data;
                    p->data = q->data;
                    q->data = temp;
                }
            }else{
                if(p->data < q->data){
                    temp = p->data;
                    p->data = q->data;
                    q->data = temp;
                }
            }
            q = q->next;
        }
        p = p->next;
    }
    return head;
}

node *insertNode(node *head, int item){
    node *temp, *temp1;
    temp = head;
    if((head == NULL) || head->data >= item){
        temp1 = new node();
        temp1->data = item;
        temp1->next = temp;
        temp->prev = temp1;
        temp = temp1;
        temp1->prev = NULL;
        return temp;
    }else{
        while((temp->next!=NULL) && (temp->next->data <= item)){
            temp = temp->next;
        }
        temp1 = new node();
        temp1->data = item;
        temp1->next = temp->next;
        temp->next = temp1;
        return head;
    }
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
            temp1->next->prev = temp1->prev;
            delete temp1;
        }
    }
    return head;
}

node *middleNode(node *head, node *tail){
    if(head == NULL){
        return NULL;
    }
    node *slowptr = head;
    node *fastptr = head->next;
    while(fastptr!=tail){
        fastptr = fastptr->next;
        if(fastptr!=tail){
            slowptr = slowptr->next;
            fastptr = fastptr->next;
        }
    }
    return slowptr;
}

node *binarySearch(node *head, node *tail, int item){
    do{
        node *middle = middleNode(head, tail);
        if(middle == NULL){
            return NULL;
        }
        if(middle->data == item){
            return middle;
        }else if(middle->data < item){
            head = middle->next;
        }else{
            tail = middle->prev;
        }
    }while(tail == NULL || tail->next!=head);
    return NULL;
}

void display(node *head, int dir){
    node *temp;
    temp = head;
    if(dir==0){
        while(temp!=NULL){
            printf("%d\n", temp->data);
            temp=temp->next;
        }
        printf("\n");
    }
    else{
        while(temp!=NULL){
            printf("%d\n", temp->data);
            temp=temp->prev;
        }
        printf("\n");
    }
}
