#include<cstdio>
#include<iostream>
#include<sstream>

#define SIZE 1024
static char buffer[SIZE];

int main(){
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);
    fread(buffer, 1, SIZE, stdin);
    std::stringstream ssin(buffer);
    std::cout << buffer;

    return 0;
}
