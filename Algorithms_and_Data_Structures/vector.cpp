#include<iostream>
#include<cstdio>
#include<vector>

using namespace std;

int main(){
    vector<int> points(0);

    points.push_back(1);
    points.push_back(2);
    points.push_back(3);

    while(!points.empty()){
        for(int i=0; i<points.size(); i++){
            cout << points[i] << endl;
        }
    }

    return 0;
}
