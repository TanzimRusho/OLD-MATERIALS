#include<stdio.h>


long long reverseNumber(long long input) {

    long long reversed = 0;

    while(input) {
        reversed = reversed * 10 + (input % 10);
        input /= 10;
    }

    return reversed;

}


static char resultString[20];


bool isPalindrome(long long sum) {

    int  i = 0;

    while(sum) {
        resultString[i++] = sum % 10;
        sum /= 10;
    }

    for(int j = 0, k = i - 1; j < i && k >= 0; ++j, --k) {
        if(resultString[j] != resultString[k])
            return false;
    }

    return true;
}


int main() {

    long long input;
    int times, iterations;

    scanf("%d", &times);

    while( times-- ) {

        scanf("%lld", &input);

        iterations = 0;

        long long sum;


        while( true ) {
            sum = input + reverseNumber(input);
            ++iterations;
            input = sum;

            if( isPalindrome(input) ){
                printf("%d %lld\n", iterations, input);
                break;
            }

        }

    }


    return 0;
}
