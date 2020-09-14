#include<cstdio>
#include<iostream>
#include<string>

using namespace std;

static string slogan[100];
static string query;

int main()
{
    unsigned n, i;

    scanf("%u", &n);
    getchar();

    unsigned limit = 2 * n;

    for(i = 0; i < limit; i += 2){
        getline(cin, slogan[i]);
        getline(cin, slogan[i+1]);
    }

    unsigned q;
    scanf("%u", &q);
    getchar();

    while(q--){
        getline(cin, query);
        for(i = 0; i < limit; i += 2){
            if(query.compare(slogan[i]) == 0)
                cout << slogan[i+1] << "\n";
        }
    }

    return 0;
}
