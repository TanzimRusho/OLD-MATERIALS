#include<stdio.h>
#include<string.h>

int varCount = 0;

typedef struct list{
    int data;
    struct list *next;
} node;

void display(node *head){
    node *temp;
    temp = head;
    int sum = 0;

    //the whole array
    /*temp = temp->next;*/
    printf("Complete list is:\n");
    while(temp!=NULL){
        printf("%d ", temp->data);
        sum += temp->data;

        temp = temp->next;
    }
    printf("\n");

    //sum of list
    printf("Summation of array is: %d\n", sum);
    printf("Average of the array is: %f\n", (float) sum/varCount);

    //odd numbers in array
    temp = head;
    printf("Odd numbers in list are:\n");
    while(temp!=NULL){
        if((temp->data % 2) != 0){
            printf("%d ", temp->data);
        }
        temp = temp->next;
    }
    printf("\n");

    //even numbers in array
    temp = head;
    printf("Even numbers in list are:\n");
    while(temp!=NULL){
        if((temp->data % 2) == 0){
            printf("%d ", temp->data);
        }
        temp = temp->next;
    }

    //max number in list
    temp = head;
    int maxVal = temp->data;
    temp = temp->next;
    while(temp!=NULL){
        if(maxVal < temp->data){
            maxVal = temp->data;
        }
        temp = temp->next;
    }
    printf("\nMax in list is: %d", maxVal);


    //min number in list
    temp = head;
    int minVal = temp->data;
    temp = temp->next;
    while(temp!=NULL){
        if(minVal > temp->data){
            minVal = temp->data;
        }
        temp = temp->next;
    }
    printf("\nMin in list is: %d", minVal);
}

int main(){
    node *head, *tail, *temp;
    char ans;
    head = NULL;

    while(1){
        fflush(stdout);
        printf("Create node (y/n)?\n");
        fflush(stdin);
        ans  = getchar();
        if(ans == 'y'){
            if(head == NULL){
                head = new node();
                printf("Enter data:\n");
                scanf("%d", &head->data);
                head->next = NULL;
                tail = head;
            }else{
                temp = new node();
                printf("Enter data:\n");
                scanf("%d", &temp->data);
                temp->next = NULL;
                tail->next = temp;
                tail = temp;
            }
            ++varCount;
        }else{
            break;
        }
    }

/*
    for(int i=0; i<=n; i++){
        if(head == NULL){
            head = new node();
            head->data = i;
            head->next = NULL;
            tail = head;
        }
        else{
            temp = new node();
            temp->data = i;
            temp->next = NULL;
            tail->next = temp;
            tail = temp;
        }
    }
*/

    if(head!=NULL){
        display(head);
    }

    return 0;
}
