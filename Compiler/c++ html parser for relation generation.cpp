#include<iostream>
#include<string>
#include<cstdio>
#include<cstring>

using namespace std;


string tags[128];


int main(){

    freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);


    string s;
    int tagCount = 0;

    while( getline(cin, s) ){
        tags[tagCount++] = s;
    }

    for( int i = 0; i < tagCount; ++i ){

        int k = 0;
        for(; k < tags[i].length(); ++k ){
            if( tags[i][k] != ' ' )
                break;
        }


        for( int j = i + 1; j < tagCount; ++j ){
            if( tags[j][k] == ' ' ){

                int x = k;
                for(; x < tags[j].length(); ++x ){
                    if( tags[j][x] != ' ' ) break;
                }

                cout << tags[j] << " is the " << (x - k) << " th child of " << tags[i] << "\n";
            }else{
                 break;
            }
        }
    }

    return 0;
}
