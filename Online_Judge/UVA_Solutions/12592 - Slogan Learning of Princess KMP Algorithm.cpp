#include<cstdio>
#include<iostream>
#include<string>

using namespace std;

static string slogan[100];
static string query;

#define r 160

static unsigned DFA[r][100];

unsigned DFAStringMatchingAlgorithm(string text, string pattern){
    unsigned m = pattern.length();
    unsigned n = query.length();

    unsigned i, j;
    for(i = 0, j = 0; i < n && j < m; ++i)
        j = DFA[text[i]][j];

    if(j == m)
        return 1;
    else
        return 0;
}

void KMPString(string pattern){
    unsigned m = pattern.length();

    DFA[pattern[0]][0] = 1;

    unsigned x, j, k;
    for(x = 0, j = 1; j < m; ++j){
        for(k = 0; k < r; ++k)
            DFA[k][j] = DFA[k][x];
        DFA[pattern[j]][j] = j + 1;
        x = DFA[pattern[j]][x];
    }
}

int main()
{
    static unsigned n, i, q;

    scanf("%u", &n);
    getchar();

    static unsigned limit = 2 * n;

    for(i = 0; i < limit; i += 2){
        getline(cin, slogan[i]);
        getline(cin, slogan[i+1]);
    }

    scanf("%u", &q);
    getchar();

    while(q--){
        getline(cin, query);
        KMPString(query);
        for(i = 0; i < limit; i += 2){
            if(DFAStringMatchingAlgorithm(slogan[i], query))
                cout << slogan[i+1] << "\n";
        }
    }

    return 0;
}
