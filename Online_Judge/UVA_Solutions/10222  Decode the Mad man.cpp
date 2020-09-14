#include<iostream>
using namespace std;
int main(){
    int i,j;
    string s;
    string in = "qwertyuiop[]asdfghjkl;'zxcvbnm,./";
	while(getline(cin, s)){
        for(i=0; i<s.length(); ++i){
            if(s[i]==' '){
                cout << " ";
            }else{
                for(j=0; j<in.length(); ++j){
                    if(s[j]>=65 && s[j]<=90){
                        s[j] += 32;
                    }
                    if(s[i]==in[j]){
                        cout << in[j-2];
                    }
                }
            }
        }
        cout << endl;
	}
	return 0;
}
