#include<stdio.h>

struct list{
	char name[100];
	char id[100];
	float marks;
	float cgpa;
	int attendence;
	struct list *next;
};

typedef list node;


void dataInput(node *head);
void dataDisplay(node *head);


int main(){
	node *head, *tail, *temp, *tmp;
	head = NULL;
	char ans;

	for(;;){
		fflush(stdout);
		printf("Create new student (y/n)?\n");
		fflush(stdin);
		ans = getchar();

		if(ans-'y'==0){
			if(head==NULL){
				head = new node();

				//user data input
				tmp = head;
				dataInput(tmp);

				head->next = NULL;
				tail = head;
			}else{
				temp = new node();

				//user data input
				tmp = temp;
				dataInput(tmp);

				temp->next = NULL;
				tail->next =  temp;
				tail = temp;
			}
		}else{
			break;
		}
	}

	//our display function
	temp = head;
	if(head==NULL){
		printf("No student data avilable in database.\n");
	}else{
		dataDisplay(temp);
	}

	return 0;
}


void dataInput(node *head){
    node *temp;
    temp = head;

    fflush(stdout);
	printf("Enter name:\n");
	fflush(stdin);
	gets(temp->name);

    fflush(stdout);
	printf("Enter student id:\n");
    fflush(stdin);
	gets(temp->id);

	printf("Enter total marks:\n");
	scanf("%f", &temp->marks);
	printf("\n");

	printf("Enter CGPA:\n");
	scanf("%f", &temp->cgpa);
	printf("\n");

	printf("Enter attendence:\n");
	scanf("%d", &temp->attendence);
	printf("\n");
}

void dataDisplay(node *head){
	node *temp;
	temp = head;

	while(temp!=NULL){
		printf("Student name:\n");
		puts(temp->name);

		printf("Student id:\n");
		puts(temp->id);

		printf("Student mark:\n");
		printf("%f", temp->marks);
		printf("\n");

		printf("Student CGPA:\n");
		printf("%f", temp->cgpa);
        printf("\n");

		printf("Student attendence:\n");
		printf("%d", temp->attendence);
        printf("\n");

		temp = temp->next;
	}
}
