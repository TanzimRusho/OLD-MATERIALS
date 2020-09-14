/**
 * Author:    Asif Ahmed
 * Site:      https://quickgrid.wordpress.com
 * Problem:   UVA
 * Technique:
 */

#include<cstdio>
#include<string>
#include<iostream>
#include<map>

using namespace std;


map<string, string> dictionary;


string first, second;
string input;


int main(){

    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);


    // may cause error
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);


    while( getline(cin, input) && input.length() ){
        int i = input.find(" ");
        first = input.substr(0, i);
        second = input.substr(i + 1, input.length() - 1);
        dictionary[second] = first;
    }


    while( getline(cin, second) ){
        if( dictionary[second] == "" )
            cout << "eh" << "\n";
        else
            cout << dictionary[second] << "\n";
    }

    return 0;
}
