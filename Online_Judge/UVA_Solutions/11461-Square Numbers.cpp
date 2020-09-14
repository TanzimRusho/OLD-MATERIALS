#include<iostream>
#include<cmath>
using namespace std;
int main(){
    int a,b,c,i;
    while(cin>>a>>b){
        if(a+b==0) return 0;
        c=0;
        for(i=a; i<=b; ++i){
            if(pow(ceil(sqrt(i)),2)==i) ++c;
        }
        cout<<c<<endl;
    }
    return 0;
}
