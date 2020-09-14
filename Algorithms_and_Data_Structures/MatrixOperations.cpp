#include<iostream>
#include<cmath>

using namespace std;

struct Dimension{
    int x, y;
} dim;

class ValueInput{
private:
    int m, n;
    void valueSet();
public:
    void setDimension(int &x, int &y){
        m = x;
        n = y;
    };

    int printDimensions(){
        return this->m;
    }
};

int main(){
    int a=3, b=2;

    ValueInput vi;
    vi.setDimension(a, b);
    vi.printDimensions();

    return 0;
}
