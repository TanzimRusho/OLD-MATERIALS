#include<iostream>
#include<cstdio>
#include<ctype.h>
#include<cstdlib>
#include<cstring>

using namespace std;

struct list{
    int attendance;
    float cgpa;
    char name[100];
    char id[100];
    float marks[50];
    char course[50][50];

    struct list *next;
    struct list *prev;
};

typedef struct list node;

void inputTaker(node *head);
void display(node *head);
node *sortList(node *head);
node *deleteData(node *head, char tempStudentId[]);

int main(){
    node *head, *tail, *temp;
    char ans;
    head = NULL;

    do{
        fflush(stdout);
        printf("Create new node (y/n)?\n");
        fflush(stdin);
        ans = tolower(getchar());
        if(ans-'y'==0){
            if(head==NULL){
                head = (node*)malloc(sizeof(node)); //head = new node();

                inputTaker(head);

                head->next = NULL;
                tail = head;
            }else{
                temp = (node*)malloc(sizeof(node)); //temp = new node();

                inputTaker(temp);

                temp->next = NULL;
                tail->next = temp;
                tail = temp;
            }
        }else{
            break;
        }
    }while(ans-'y'==0);

    if(head == NULL){
        printf("No list exist.\n");
    }else{
        display(head);

        //list sorting
        fflush(stdout);
        printf("Do you want sort the list (y/n)?\n");
        fflush(stdin);
        ans = getchar();
        temp = sortList(head);
        printf("After sorting:\n");
        display(temp);

        //temporary info
        node *newHead;
        newHead = temp;
        head = temp;
        char tempStudentId[100];

        //delete
        fflush(stdout);
        printf("Do you want to delete any student data (y/n)?\n");
        fflush(stdin);
        ans = getchar();
        fflush(stdout);
        printf("Enter id for the student you want to delete data:\n");
        fflush(stdin);
        gets(tempStudentId);
        temp = deleteData(newHead, tempStudentId);
        printf("After deletion:\n");
        display(temp);
    }

    return 0;
}

void inputTaker(node *head){
    fflush(stdout);
    printf("Enter student attendace:\n");
    fflush(stdin);
    scanf("%d", &head->attendance);

    fflush(stdout);
    printf("Enter student cgpa:\n");
    fflush(stdin);
    scanf("%f", &head->cgpa);

    fflush(stdout);
    printf("Enter name:\n");
    fflush(stdin);
    gets(head->name);

    fflush(stdout);
    printf("Enter id:\n");
    fflush(stdin);
    gets(head->id);

    int n=0;
    fflush(stdout);
    printf("Enter number of subjects:\n");
    fflush(stdin);
    scanf("%d", &n);
    for(int i=0; i<n; i++){
        fflush(stdout);
        printf("Enter course %d name:\n", i+1);
        fflush(stdin);
        gets(head->course[i]);
        fflush(stdout);
        printf("Enter %s mark:\n", head->course[i]);
        fflush(stdin);
        scanf("%f", &head->marks[i]);
    }
}

void display(node *head){
    node *temp;

    temp = head;
    while(temp!=NULL){
        printf("Name:\n");
        puts(temp->name);

        printf("ID:\n");
        puts(temp->id);

        printf("Attendance:\n");
        printf("%d\n", temp->attendance);

        printf("CGPA:\n");
        printf("%f\n", temp->cgpa);

        for(int i=0; temp->marks[i] != NULL; i++){
            printf("%s mark is:\n", temp->course[i]);
            printf("%f\n", temp->marks[i]);
        }

        temp =  temp->next;
    }
}

node *sortList(node *head){
    node *temp, *p, *q;

    int tempAttendance;
    float tempCgpa;
    char tempName[100];
    char tempId[100];
    float tempMark;
    char tempCourse[50];

    temp = head;
    p = temp;
    while(p!=NULL){
        q = p->next;
        while(q!=NULL){
            if(p->cgpa < q->cgpa){
                tempAttendance = p->attendance;
                p->attendance = q->attendance;
                q->attendance = tempAttendance;

                tempCgpa = p->cgpa;
                p->cgpa = q->cgpa;
                q->cgpa = tempCgpa;

                strcpy(tempName, p->name);
                strcpy(p->name, q->name);
                strcpy(q->name, tempName);

                strcpy(tempId, p->id);
                strcpy(p->id, q->id);
                strcpy(q->id, tempId);

                for(int i=0; temp->marks[i]!=NULL; i++){
                    tempMark = p->marks[i];
                    p->marks[i] = q->marks[i];
                    q->marks[i] = tempMark;

                    strcpy(tempCourse, p->course[i]);
                    strcpy(p->course[i], q->course[i]);
                    strcpy(q->course[i], tempCourse);
                }
            }
            q = q->next;
        }
        p = p->next;
    }

    return head;
}

node *deleteData(node *head, char tempStudentId[]){
    node *temp, *p, *q;
    if(strcmp(head->id, tempStudentId)){
        head = head->next;
    }else{
        temp = head;
        p = temp;
        while(temp!=NULL){
            q = p->next;
            if(strcmp(q->id, tempStudentId)){
                p->next = q->next;
            }
            temp = temp->next;
            p = temp;
        }
    }
    return head;
}
