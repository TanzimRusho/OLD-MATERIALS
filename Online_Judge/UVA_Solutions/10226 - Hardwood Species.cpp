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
#include<iomanip>


using namespace std;


map<string, int> speciesCount;


string input;



int main(){

    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);

    int first = 0;

    int n;
    cin >> n;
    getchar();
    getchar();

    while(n--){

        speciesCount.clear();


        int total = 0;

        while( getline(cin, input) && input.length() ){
            ++speciesCount[input];
            ++total;
        }


        if(first){
            cout << "\n";
        }
        ++first;

        for (std::map<string, int>::iterator i = speciesCount.begin(); i != speciesCount.end(); i++){
            cout << i->first << " " << fixed << setprecision(4) << ( (float) i->second / total ) * 100 << "\n";
        }


    }

    return 0;
}
