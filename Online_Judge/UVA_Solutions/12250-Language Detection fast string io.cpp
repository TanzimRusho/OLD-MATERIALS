#include<cstdio>
#include<iostream>
#include<string>
#include<map>
#include<sstream>

using namespace std;

static string s;
static map<string, string> language;

/*
 * Replace getchar() with getchar_unlocked() when submitting
 */

void gcn(){
    char c = '0';
    s.clear();
    while((c = getchar()) && (c != -1 && c != '\n' && c != '\r'))
        s += c;
}

int main()
{
    static unsigned c = 1;

    language["HELLO"] = "ENGLISH";
    language["HOLA"] = "SPANISH";
    language["HALLO"] = "GERMAN";
    language["BONJOUR"] = "FRENCH";
    language["CIAO"] = "ITALIAN";
    language["ZDRAVSTVUJTE"] = "RUSSIAN";

    gcn();
    while(s.length()){
        if(s[0] == '#' && s[1] == '\0')
            break;
        if(language[s] == "")
            cout << "Case " << c << ": UNKNOWN" << "\n";
        else
            cout << "Case " << c << ": " << language[s] << "\n";
        ++c;
        gcn();
    }
    return 0;
}
