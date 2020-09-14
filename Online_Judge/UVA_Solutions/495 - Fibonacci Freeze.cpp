#include<iostream>
#include<cmath>
#include<iomanip>
using namespace std;

unsigned long long ft[5001] = {0};

unsigned long long f(int n){
    if(n==0){
        return 0;
    }
    if(n==1){
        return 1;
    }
    if(ft[n]==0){
        ft[n] = f(n-1) + f(n-2);
    }
    return ft[n];
}

int main(){
	int n;
	while(cin >> n){
        cout << f(n) << endl;
        //cout << setprecision(100) << (pow(((1+sqrt(5))/2), n) - pow(1-(1+sqrt(5)/2), n))/sqrt(5) << endl;
	}
	return 0;
}
