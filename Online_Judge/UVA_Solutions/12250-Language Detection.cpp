#include<cstdio>
#include<iostream>
#include<string>
#include<map>
#include<sstream>

using namespace std;

static string s;
static map<string, string> language;
static char buffer[32000], out[50000];

int main()
{
    ios_base::sync_with_stdio(false);

    static unsigned c = 1;

    language["HELLO"] = "ENGLISH";
    language["HOLA"] = "SPANISH";
    language["HALLO"] = "GERMAN";
    language["BONJOUR"] = "FRENCH";
    language["CIAO"] = "ITALIAN";
    language["ZDRAVSTVUJTE"] = "RUSSIAN";

    fread(buffer, 1, sizeof buffer, stdin);
    istringstream sin(buffer);
    ostringstream sout(out);

    while(getline(sin, s)){

        if(s[0] == '#' && s[1] == '\0')
            break;
        if(language[s] == "")
            sout << "Case " << c << ": UNKNOWN" << "\n";
        else
            sout << "Case " << c << ": " << language[s] << "\n";
        ++c;
    }

    cout << sout.str();

    return 0;
}
