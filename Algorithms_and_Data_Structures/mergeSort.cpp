#include<stdio.h>

int main(){
    int m,n;
    int j=0, k=0;

    printf("Enter array 1 size:\n");
    scanf("%d", &n);

    int *a = new int[n];

    for(int i=0; i<n; i++){
        scanf("%d", &a[i]);
    }
    printf("\n");

    printf("Enter array 2 size:\n");
    scanf("%d", &m);

    int *b = new int[m];

    for(int i=0; i<m; i++){
        scanf("%d", &b[i]);
    }
    printf("\n");

    int *c = new int[m+n];

    for(int i=0; i<m+n; i++){
        if(a[j]<b[k]){
             c[x] = a[j];
             x++;
             j++;
        }else{
            c[x] = a[k];
            x++;
            k++;
        }
        if(j>n){

        }else{

        }
    }

    return 0;
}
