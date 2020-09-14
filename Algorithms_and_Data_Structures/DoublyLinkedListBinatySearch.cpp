/*
 * Binary Search on Linked List
 */

 #include<iostream>
 #include<cstdio>
 #include<cstdlib>
 #include<cstring>

 using namespace std;


 struct courseDetails
 {
     char subjectName[50];
     float marks[50];
     int courseCode[50];

     struct courseDetails *next;
     struct courseDetails *prev;
 };

 typedef struct courseDetails cod;

 struct infoBank
 {
    char name[50];
    char id[50];
    float cgpa;
    int attendence;

     cod *cheadPoint;
    struct courseDetails courseNode;

    struct infoBank *next;
    struct infoBank *prev;
 };


 typedef struct infoBank node;


 void display(node *head);

 int main(){
    node *head, *tail, *temp;
    cod *chead, *ctail, *ctemp;
    char quesionStudent, quesionCourse;
    head = NULL;

    while(1)
    {
        fflush(stdout);
        printf("create new Student:(y/n)?\n");
        fflush(stdin);
        quesionStudent = getchar();

        if(quesionStudent-'y' == 0)
        {
            if(head == NULL)
            {
                head = new node();

                //input operations
                fflush(stdout);
                printf("Enter student Name:\n");
                fflush(stdin);
                gets(head->name);
                fflush(stdout);
                printf("Enter student ID:\n");
                fflush(stdin);
                gets(head->id);
                printf("Enter student Attendance:\n");
                scanf("%d", &head->attendence);
                printf("Enter student CGPA:\n");
                scanf("%f", &head->cgpa);

                while(1)
                {
                    //node *chead, *ctail, *ctemp;
                    chead = NULL;

                    fflush(stdout);
                    printf("create new course:(y/n)?\n");
                    fflush(stdin);
                    quesionCourse = getchar();

                    if(quesionCourse-'y' == 0)
                    {
                        if(chead == NULL)
                        {
                            chead = new cod();

                            fflush(stdout);
                            printf("Enter Subject Name:\n");
                            fflush(stdin);
                            gets(chead->subjectName);
                            printf("Enter subject Course Code:\n");
                            scanf("%d", &chead->courseCode);
                            printf("Enter student marks:\n");
                            scanf("%f", &chead->marks);

                            chead->next = NULL;
                            ctail = chead;
                        }
                        else{

                        }
                    }else{
                        break;
                    }
                }


                head->next = NULL;
                tail = head;
                head->cheadPoint = chead;
            }
            else
            {

            }
        }else
        {
            break;
        }
    }

    display(head);

    return 0;
 }

 void display(node *head){
    node *temp;
    temp = head;
    cod *ctemp;
    ctemp = head->cheadPoint;

    while(temp!=NULL){
        printf("Name:\n");
        puts(temp->name);
        printf("ID:\n");
        puts(temp->id);
        printf("CGPA:\n");
        printf("%f\n", temp->cgpa);
        printf("Attendance:\n");
        printf("%d\n", temp->attendence);

        while(ctemp!=NULL){
            printf("Subject Name:\n");
            puts(ctemp->subjectName);
            printf("Subject Marks:\n");
            printf("%f\n", ctemp->subjectName);
            printf("Course Code:\n");
            printf("%d\n", ctemp->courseCode);

            ctemp = ctemp->next;
        }

        temp = temp->next;
    }
 }
