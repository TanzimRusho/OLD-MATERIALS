#include<stdio.h>
#define N 4


// 5
int x1[N] = {0,1,0,1};
// 9
int x2[N] = {1,0,0,1};


int result[N];
int w = -2;
int bias = 3;


int halfAdder(int a, int b, int pos){

    int layer1out = ((w * a + w * b) + bias <= 0)? 0 : 1;

    printf(":: %d\n", layer1out);

    int layer2out1 = ((w * a + w * layer1out) + bias <= 0)? 0 : 1;
    int layer2out2 = ((w * layer1out + w * b) + bias <= 0)? 0 : 1;

    int outputLayerSum = ((w * layer2out1 + w * layer2out2) + bias <= 0)? 0 : 1;
    int outputLayerCarry = ((w * layer1out + w * layer1out) + bias <= 0)? 0 : 1;

    result[pos] = outputLayerSum;

    printf("%d, %d\n", outputLayerCarry, outputLayerSum);

    return outputLayerCarry;
}


int main(){

    int carry = 0;
    int sum = 0;

    for(int i = 3; i >= 0; --i){
        carry = halfAdder( x1[i], x2[i], i );

        carry = halfAdder( result[i], carry, i );

    }


    for(int i = 0; i < 4; ++i){
        printf("%d ", result[i]);
    }

    return 0;
}
