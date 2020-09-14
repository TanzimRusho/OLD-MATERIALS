#include<iostream>
int main(){
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);
    register unsigned int i;
    unsigned int a,b;
    std::cin >> i;
    while(i--){
        std::cin >> a >> b;
        std::cout << (a>b?'>':a<b?'<':'=') << "\n";
    }
    return 0;
}
