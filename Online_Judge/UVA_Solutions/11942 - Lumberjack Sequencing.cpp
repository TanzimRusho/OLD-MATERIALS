#include<stdio.h>
#include<stdbool.h>

int main(){
	int n, i, j, a[21][21];
	bool  ordered[21] = {false};
	scanf("%d", &n);

	for(j=0; j<n; ++j){
        for(i=0; i<10; i++){
            scanf("%d", &a[j][i]);
        }

        if(a[j][0] < a[j][1]){
            for(i=0; i<9; ++i){
                if(a[j][i] < a[j][i+1]){
                    ordered[j] = true;
                }else{
                    ordered[j] = false;
                    break;
                }
            }
        }else if(a[j][0] > a[j][1]){
            for(i=0; i<9; ++i){
                if(a[j][i] > a[j][i+1]){
                    ordered[j] = true;
                }else{
                    ordered[j] = false;
                    break;
                }
            }
        }
	}

    printf("Lumberjacks:\n");
    for(j=0; j<n; ++j){
        if(ordered[j] == true){
            printf("Ordered\n");
        }else{
            printf("Unordered\n");
        }
    }
	return 0;
}
