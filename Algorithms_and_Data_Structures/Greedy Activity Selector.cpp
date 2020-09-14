#include<cstdio>
#include<ctime>
#include<cstdlib>
using namespace std;

#define N 10
static char selectedJobs[N];

struct jobs{
    char c;
    int start;
    int end;
} job[N];

void greedyActivitySelector(){
    selectedJobs[0] = job[0].c;
    int k = 0, x = 1;
    for (int m = 1; m < N; ++m){
        if(job[m].start >= job[k].end){
            selectedJobs[x] = job[m].c;
            ++x;
            k = m;
        }
    }
}

int partition(int front, int rear){
    struct jobs element = job[rear];
    int i = front - 1;
    for(int j = front; j<rear; ++j){
        if(job[j].end <=  element.end){
            ++i;
            struct jobs temp = job[i];
            job[i] = job[j];
            job[j] = temp;
        }
    }
    struct jobs temp = job[i+1];
    job[i+1] = job[rear];
    job[rear] = temp;
    return i+1;
}

void quicksort(int front, int rear){
    if(front < rear){
        int part = partition(front, rear);
        quicksort(front, part-1);
        quicksort(part+1, rear);
    }
}


int main(){
    int i;

    /*
    srand(time(NULL));
    for (i = 0; i < N; ++i){
        job[i].c = 'A' + i;
        job[i].start = rand() % N;
        job[i].end = rand() % N;

        while(jobs[i].start > val = rand() % N)
            job[i].end = rand() % N;
    }
    */

    job[0] = {'A', 2, 5};
    job[1] = {'B', 0, 3};
    job[2] = {'C', 3, 6};
    job[3] = {'D', 1, 3};
    job[4] = {'E', 6, 8};
    job[5] = {'F', 8, 10};
    job[6] = {'G', 5, 8};
    job[7] = {'H', 7, 9};
    job[8] = {'I', 10, 12};
    job[9] = {'J', 3, 5};

    quicksort(0, N-1);
    for (i = 0; i < N; ++i)
        printf("%c %d %d\n", job[i].c, job[i].start, job[i].end);

    greedyActivitySelector();

    for (i = 0; i < N; ++i)
        printf("%c ", selectedJobs[i]);

    return 0;
}
