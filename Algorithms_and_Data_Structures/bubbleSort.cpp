#include<stdio.h>

void bubbleSort(int *a, int n);

int main(){
    int n=0, a[100];
    scanf("%d", &n);

    for(int i=0; i<n;i++){
        scanf("%d", &a[i]);
    }

    bubbleSort(a, n);

    for(int i=0; i<n;i++){
        printf("%d", a[i]);
    }

    return 0;
}

void bubbleSort(int *a, int n){
    int temp;
    for(int i=0; i<n-2; i++){
        for(int j=0; j<n-i-1; j++){
            if(a[j]>a[j+1]){
                temp = *(a+j);
                *(a+j) = *(a+(j+1));
                *(a+(j+1)) = temp;
            }
        }
    }
}
