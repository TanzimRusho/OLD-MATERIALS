#include<iostream>
#include<cstdio>

#define MAXSTRINGLEN 82

using namespace std;

static int dp [MAXSTRINGLEN][MAXSTRINGLEN] ;
static string s , t;

inline int min(int a, int b, int c){
    return ( (a < b && a < c) ? a : (b < c ? b : c) );
}

int main(){
    static int i, j;

    while(cin >> s >> t) {

        for( i = 0; i <= s.size() ; i++)
            dp[i][0] = i ;
        for( j = 0; j <= t.size() ; j++)
            dp[0][j] = j ;


        for( i = 1 ; i <= s.size() ; i++) {
            for( j = 1 ; j <= t.size() ; j++)
                dp[i][j] = min( dp[i-1][j] + 1, dp[i][j-1] + 1, dp[i-1][j-1] + !(s[i-1] == t[j-1]) );
        }
        cout << "Edit Distance is: " << dp [ s.size() ] [ t.size() ] << "\n" ;

        for( i = 0 ; i <= s.size() ; i++) {
            for( j = 0 ; j <= t.size() ; j++)
                printf("%d ", dp[i][j]);
            printf("\n");
        }
    }
    return 0 ;
}
