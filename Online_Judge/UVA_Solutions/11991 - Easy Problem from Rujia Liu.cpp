#include<stdio.h>

int main(){
	int n, i, k, v, m, j;
	int a[100001], match;
	while(scanf("%d %d", &n, &m) == 2){
        for(i=0; i<n; ++i){
            scanf("%d", &a[i]);
        }
        for(i=0; i<m; ++i){
            match = 0;
            scanf("%d %d", &k, &v);
            int num = 0;
            for(j=0; a[j]!='\0'; ++j){
                if(a[j] == v){
                    ++num;
                }
                if(num == k){
                    match = 1;
                    break;
                }else{
                    match = 0;
                }
            }
            if(match){
                printf("%d\n",j+1);
            }else{
                printf("0\n");
            }
        }
	}
	return 0;
}

/*
#include<cstdio>
#include<map>
#include<vector>
using namespace std;
map<int,vector<int> >mm;
int main()
{
	int n,m,a,k,v;
	while(scanf("%d%d",&n,&m)!=EOF){
		mm.clear();
		for(int i=1;i<=n;i++)
		{
			scanf("%d",&a);
			mm[a].push_back(i);
		}
		while(m--)
		{
			scanf("%d%d",&k,&v);
			if(mm[v].size()<k)
				printf("0\n");
			else
				printf("%d\n",mm[v][k-1]);
		}
	}
}
*/
