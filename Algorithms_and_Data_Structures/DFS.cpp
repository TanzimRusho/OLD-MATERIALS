#include<stdio.h>

#define size 100


char q[size], vertex[size], visited_sequence[size];

int graph[size][size];

int count_visited_seq = -1, top = -1, n;



void visit(char vertex){
    visited_sequence[++count_visited_seq] = vertex;
}


int isVisited(char vertex){

    for(int i=0; i<=count_visited_seq; ++i){
        if(visited_sequence[i] == vertex)
            return 1;   //node already visited
    }

    return 0;
}


void displayVisitedSeqence(){

    for(int i=0; i<=count_visited_seq; ++i)
        printf("%c", visited_sequence[i]);

    printf("\n");
}


void push(char vertex){
    if(top+1 >= size){
        return;
    }
    q[++top] = vertex;
}


char pop(){
    if(top == -1){
        return '\0';
    }
    char ch = q[top];
    q[top--] = NULL;
    return ch;
}


void checkAdjecency(char ch){

    for(int i = 0; i < n; ++i){
        if(ch == vertex[i]){
            for(int j = 0; j < n; ++j){
                if(graph[i][j] == 1 && !isVisited(vertex[j]))
                    push(vertex[j]);
            }
        }
    }

}



void createGraph(){
    int i,j;

    for(i=0; i<26; ++i){
        vertex[i] = 'A'+i;
    }

    printf("How many vertex?\n");
    scanf("%d", &n);

    for(i=0; i<n; ++i){
        for(j=0; j<n; ++j)
            graph[i][j] = 0;
    }

    for(i = 0; i < n; ++i){
        for(j = i + 1; j < n; ++j){
            printf("%c%c exist? ", vertex[i], vertex[j]);
            scanf("%d", &graph[i][j]);
            if(graph[i][j])
                graph[j][i] = graph[i][j];
        }
    }

}


void DFS(){

    push(vertex[0]);

    while(top != -1){
        char ch = pop();
        if(!isVisited(ch))
            visit(ch);
        checkAdjecency(ch);
    }

}


int main(){

    createGraph();

    DFS();

    displayVisitedSeqence();

    return 0;
}
