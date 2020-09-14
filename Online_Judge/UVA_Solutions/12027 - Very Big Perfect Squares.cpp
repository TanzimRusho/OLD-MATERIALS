#include<cstdio>
#include<string>

using namespace std;

static unsigned n, k, i, len, x;
static string s;

void gcn(){
    char c = '0';
    s.clear();
    while((c = getchar_unlocked()) && (c != -1 && c != '\n' && c != '\r')){
        if(k < 2){
            s += c;
            ++k;
        }
        ++x;
    }
}

unsigned sqrt32(unsigned n)
{
    unsigned c = 0x8000;
    unsigned g = 0x8000;

    for(;;) {
        if(g*g > n)
            g ^= c;
        c >>= 1;
        if(c == 0)
            return g;
        g |= c;
    }
}

int main() {
    gcn();
    while(1){
        if(s[0] == '0' && s[1] == '\0')
            return 0;

        n = s[0] - '0';

        --x;
        if(x && x&1)
            n = n * 10 + s[1] - '0';

        putchar_unlocked( sqrt32(n) + '0');

        for(i = x >> 1; i; --i)
            putchar_unlocked('0');
        puts("");

        x = k = 0;
        gcn();
    }

    return 0;
}
