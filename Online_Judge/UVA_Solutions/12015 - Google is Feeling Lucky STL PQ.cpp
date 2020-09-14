#include<cstdio>
#include<queue>

using namespace std;

static char s[10][100];
static int c, n, match, i, key;

priority_queue<pair<int,int>> pq;

int main(){
	scanf("%u", &n);

	while(n--){
        for(i = 0; i < 10; ++i){
            scanf("%s %d", s[i], &key);
            pq.push(pair<int, int>(key, -i));
        }

        match = pq.top().first;

        printf("Case #%d:\n", ++c);
        while(pq.top().first == match){
            printf("%s\n", s[-pq.top().second]);
            pq.pop();
        }

        while(!pq.empty())
            pq.pop();
	}
	return 0;
}
