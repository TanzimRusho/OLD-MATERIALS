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
#include<sstream>

using namespace std;


map<string, int> dictionary;


string first, second;
string input;


int main(){

    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);


    int n, m;
    cin >> n >> m;
    getchar();


    while(n--){
        getline(cin, input);

        int i = input.find(" ");
        first = input.substr(0, i);
        second = input.substr(i + 1, input.length() - 1);

        int num;
        istringstream ss( second );
        ss >> num;

        dictionary[first] = num;

    }

    string tmp;

    while(m--){

        int sum = 0;

        while( getline(cin, input) && input != "." ){

            bool flag = false;
            for(int i = 0; input[i]; ++i){
                if(input[i] == '.'){
                    flag = true;
                    break;
                }
            }
            if(flag)
                break;


            istringstream is( input );
            while( getline( is, tmp, ' ' ) ){
                sum += dictionary[tmp];
            }
        }

        cout << sum << "\n";
    }

    return 0;
}
