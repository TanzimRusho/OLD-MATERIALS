#include<cstdio>
#include<iostream>
#include<string>
#include<map>

using namespace std;

static string query;
static map<string, string> slogan;

int main()
{
    static unsigned n, i, q;

    scanf("%u", &n);
    getchar();

    static unsigned limit = 2 * n;

    static string s1, s2;

    for(i = 0; i < limit; i += 2){
        getline(cin, s1);
        getline(cin, s2);
        slogan[s1] = s2;
    }

    scanf("%u", &q);
    getchar();

    while(q--){
        getline(cin, query);
        cout << slogan[query] << "\n";
    }

    return 0;
}
