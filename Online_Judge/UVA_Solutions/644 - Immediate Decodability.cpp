/**
 * Author:    Asif Ahmed
 * Site:      https://quickgrid.wordpress.com
 * Problem:   UVA 644 - Immediate Decodability.
 * Technique:
 */


#include<cstdio>
#include<iostream>
#include<cstring>
#include<string>
using namespace std;


#define N 10
string s[N];


int main(){

    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);


    string input;
    int codeCount = 0;
    int setNumber = 0;


    while( getline(cin, input) ){


        if( !input.compare("9") ){

            ++setNumber;

            bool decodeable = false;

            for(int j = 0; j < codeCount; ++j){
                for(int i = 0; i < codeCount; ++i){

                    if( i == j ) continue;

                    if( s[j].compare( s[i].substr(0, s[j].length()) ) == 0 ){
                        decodeable = true;
                        break;
                    }

                }
            }


            if( ! decodeable )
                cout << "Set " << setNumber << " is immediately decodable" << "\n";
            else
                cout << "Set " << setNumber << " is not immediately decodable" << "\n";


            codeCount = 0;
            for(int i = 0; i < codeCount; ++i)
                s[i].clear();


            continue;
        }


        s[codeCount] = input;
        ++codeCount;


    }


    return 0;
}
