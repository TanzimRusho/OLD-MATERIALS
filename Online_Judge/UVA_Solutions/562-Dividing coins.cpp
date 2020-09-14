#include<iostream>
using namespace std;
int main(){
    int a,b,n,t;
    cin>>n;
    while(n--){
        cin>>t;
        a=t;
        while(t--){
            cin>>b;
        }
        cout<<!(a%2)<<endl;
    }
    return 0;
}
