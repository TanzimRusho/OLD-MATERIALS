#include<stdio.h>
#include<time.h>
#include<stdlib.h>

int main(){
    srand(time(NULL));
    int n=0, a[100], delitem, index, times;
    printf("Enter array size:\n");
    scanf("%d", &n);

    for(int i=0; i<n; i++){
        a[i] = rand() % 20;
    }
    printf("\n");

    for(int i=0; i<n; i++){
        printf("%d ", a[i]);
    }
    printf("\n");

    printf("Enter element to delete:\n");
    scanf("%d", &delitem);

    for(int i=0; i<n; i++){
        if(a[i] == delitem){
           index = i;
           printf("Found at %d\n", index);
           break;
        }
    }

    for(int i=index; i<n-1; i++){
        a[i] = a[i+1];
    }

    printf("After deletion:\n");
    for(int i=0; i<n-1; i++){
        printf("%d\n", a[i]);
    }

    int item, pos;
    printf("Enter index and item to insert:\n");
    scanf("%d%d", &pos, &item);

    printf("After insertion:\n");
    for(int i=n-1; i>pos; i--){
        a[i+1]=a[i];
    }
    a[pos-1] = item;
    printf("After insertion:\n");
    for(int i=0; a[i]!=NULL; i++){
        printf("%d\n", a[i]);
    }
}
