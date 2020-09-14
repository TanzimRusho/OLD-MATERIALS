#include<stdio.h>

struct list{
    int data;
    struct list *next;
    struct list *prev;
};

typedef struct list node;

node *createNode(node *head, int data){
    head->data = data;
    head->next = NULL;
    head->prev = NULL;
    return head;
}

node *insertNode(node *head, int data){

}

int main(){

    while(1){
        printf("MENU:\n");
        printf("=====\n");
        printf("1.Insert Node:\n");
        printf("2.Delete Node:\n");
        printf("3.Search Node:\n");
        printf("4.Swap With Next Node:\n");
        printf("5.Swap With Previous Node:\n");
        printf("6.Swap With Previous and next Node:\n");
        printf("7.Linear Search Node:\n");
        printf("8.Binary Search Node:\n");
        printf("9.Bubble sort Node:\n");
        printf("10.Replace Node:\n");
        printf("11.Length of list:\n");
        printf("12.Show the list:\n");
        printf("\n=================\n");
        printf("\nEnter Choice Number:\n");
        printf(">>");
/*        while(scanf("%d",&c)==1){
            switch(){
            case 1:
                break;
            case 1:
                break;
            case 1:
                break;
            case 1:
                break;
            case 1:
                break;
            case 1:
                break;
                case 1:
                break;
            case 1:
                break;
            case 1:
                break;
                case 1:
                break;
            case 1:
                break;
            case 1:
                break;
            default:
                break;
            }
        }*/
    }

    return 0;
}
