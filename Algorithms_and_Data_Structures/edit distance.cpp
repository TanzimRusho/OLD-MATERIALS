#include <iostream>
#include <cstring>

#define MAXSTRINGLEN 5000

using namespace std;

int dp [MAXSTRINGLEN+1] [MAXSTRINGLEN+1] ;
string s , t ;

int d(int x , int y) {
    if( s[x-1] == t[y-1] ) return 0 ;
    return 1;
}

int main(){
    while(cin >> s >> t) {
        //memset(dp , 0 , sizeof(dp)) ;


        for(int i = 0; i <= s.size() ; i++)
            dp[i][0] = i ;
        for(int j = 0; j <= t.size() ; j++)
            dp[0][j] = j ;


        for(int i = 1 ; i <= s.size() ; i++) {
            for(int j = 1 ; j <= t.size() ; j++)
                dp[i][j] = min(dp[i-1][j] + 1, min(dp[i][j-1] + 1, dp[i-1][j-1] + d(i,j)));
        }
        cout << "Edit Distance is: " << dp [ s.size() ] [ t.size() ] << "\n" ;
    }
    return 0 ;
}
