#include <bits/stdc++.h>
#define TOTALBITS 32
#define N 500000

void merge (int *a, int n, int m) {
    int i, j, k;
    int *x = new int[n];
    for (i = 0, j = m, k = 0; k < n; k++) {
        x[k] = j == n      ? a[i++]
             : i == m      ? a[j++]
             : a[j] < a[i] ? a[j++]
             :               a[i++];
    }
    for (i = 0; i < n; i++) {
        a[i] = x[i];
    }
    free(x);
}

void merge_sort (int *a, int n) {
    if (n < 2)
        return;
    int m = n / 2;
    merge_sort(a, m);
    merge_sort(a + m, n - m);
    merge(a, n, m);
}

int main () {


    std::random_device rd;
    std::mt19937 mt(rd());
    std::uniform_real_distribution<float> dist(1, pow(2,TOTALBITS));
    //std::normal_distribution<double> dist(0, pow(2,TOTALBITS));


    int a[N];
    for(int i = 0; i < N; ++i){
        a[i] = dist(mt);
    }

    int n = sizeof a / sizeof a[0];
    int i;
    //for (i = 0; i < n; i++)
        //printf("%d%s", a[i], i == n - 1 ? "\n" : " ");
    merge_sort(a, n);

    /*
    for (i = 0; i < n; i++)
        printf("%d ", a[i]);
    */

    return 0;
}
