#include<cstdio>
#include<sstream>

using namespace std;

#define SIZE 500002
static char buffer[SIZE];

int main(){
    fread(buffer, 1, sizeof buffer, stdin);
    stringstream ss(buffer);

    unsigned int n,x,s;

    while((ss >> n) && n){
        x = 1;
        while(x <= n){
            x <<= 1;
        }
        s = n - (x % n);
        printf("%u\n", s);
    }
    return 0;
}
