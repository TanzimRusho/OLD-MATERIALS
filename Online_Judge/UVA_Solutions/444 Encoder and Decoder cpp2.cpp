#include<iostream>
using namespace std;
int main(){
    int i,j,a;
    string s;
	while(getline(cin,s)){
        for(i=0; s[i]!='\0'; ++i);
        for(j=i-1; j>=0; --j){
            if(s[0]>='0' && s[0]<='9'){
                if(s[j]!='1'){
                    a = s[j-1] + s[j]*10 - '0' +32;
                    if(j-1>=0){
                        j--;
                    }
                }else{
                    a = s[j-2]-'0' + (s[j-1]-'0')*10 + (s[j] -'0')*100;
                    if(j-2>=0){
                        j-=2;
                    }
                }
                cout << (char)a;
            }else{
                a = s[j];
                if((s[j]>='a' && s[j]<='c') || (s[j]>='A' && s[j]<='Z') || s[j]==' ' || s[j]==';' || s[j]=='.' || s[j]==',' || s[j]=='!' || s[j]==':' || s[j]=='?'){
                    a = (a%10)*10 + (a/10);
                    if(s[j]=='P' || s[j]=='F'){
                        cout << "0";
                    }
                    cout << a;
                }else if(s[j]=='d'){
                    cout << "001";
                }else if(s[j]=='x'){
                    cout << "021";
                }else{
                    //a = (a%100)*100 + ((a/=10)%10)*10 + (a/10);
                    int b = (a%100)*100;
                    int c = a/10;
                    a = b + (c%10)*10 + (c/10);
                    if(a>2000){
                        a-=2000;
                    }else if(a>1000){
                        a-=1000;
                    }
                    cout << a;
                }
            }
        }
        cout << endl;
	}
	return 0;
}
