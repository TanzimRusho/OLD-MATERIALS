#include<iostream>

struct list{
    char *name;
    char *id;
    float *marks;
    float *subjects;

    struct list *next;
    struct list *prev;
};

typedef struct list node;

int main(){
    node *student = new node [10];


    return 0;
}
