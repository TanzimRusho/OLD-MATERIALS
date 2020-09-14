/**
 * Author:    Asif Ahmed
 * Site:      https://quickgrid.wordpress.com
 * Problem:   UVA 10815
 * Technique:
 */

#include<cstdio>
#include<iostream>
#include<string>
#include<set>
#include<sstream>

using namespace std;


set<string> process;


int main(){

    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);


    string input;
    while( getline(cin, input)){

        for(int i = 0; input[i]; ++i){
            if( input[i] != ' ' && !( input[i] >= 'A' && input[i] <= 'Z' ) && !( input[i] >= 'a' && input[i] <= 'z' ) ){
                input[i] = ' ';
            }
        }

        istringstream ss( input );


        string s;
        while( getline( ss, s, ' ' ) ){

            for(int i = 0; s[i]; ++i){
                if( s[i] >= 'A' && s[i] <= 'Z')
                    s[i] = s[i] + 32;
            }
            process.insert(s);
        }
    }


    set<string>::iterator iter;
    for(iter = process.begin(); iter != process.end(); ++iter) {
        if( (*iter).length() )
            cout<<(*iter) << "\n";
    }

    return 0;
}
