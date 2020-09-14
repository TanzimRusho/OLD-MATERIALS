#include<iostream>
#include<vector>
#include<cstdio>

using namespace std;

int main(){
    int n;
    cin >> n;
    while(n--){
        int m, i;
        vector<int> v;
        cin >> m;
        for(i=0; i<m; ++i){
           int a;
           cin >> a;
           v.push_back(a);
        }
        vector<int>::iterator x;
        float sum = 0;
        for(x=v.begin(); x<v.end(); ++x){
            sum += *x;
        }
        sum = sum / m;
        int c = 0;
        for(x=v.begin(); x!=v.end(); ++x){
            if(sum < *x){
                ++c;
            }
        }
        printf("%.3f%\n", (c*100.0)/m);
    }
    return 0;
}
