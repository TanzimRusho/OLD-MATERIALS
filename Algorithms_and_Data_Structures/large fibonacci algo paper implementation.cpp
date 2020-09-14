/**
 * @author  Quickgrid ( Asif Ahmed )
 * @link    https://quickgrid.wordpress.com
 */

#include<stdio.h>
#include<math.h>

long long fib(long long n){
    if(n == 0)
        return 0;
    else if(n == 1 || n == 2)
        return 1;
    else{
        long long f = 1;
        long long l = 1;
        long long sign = -1;
        long long val = log2(n) - 1;
        long long mask = pow(2, val);

        for(long long i = 1; i <= val; ++i){
            long long temp = f * f;
            f = (f + l) / 2;
            f = 2 * (f * f) - 3 * temp - 2 * sign;
            l = 5 * temp + 2 * sign;
            sign = 1;

            if((n & mask) != 0){
                temp = f;
                f = (f + l) / 2;
                l = f + 2 * temp;
                sign = -1;
            }

            mask = mask / 2;
        }

        if((n & mask) == 0)
            f = f * l;
        else{
            f = (f + l) / 2;
            f = f * l - sign;
        }
        return f;
    }
}

int main(){

    long long n = 14;
    printf("%lld\n", fib(n));


    return 0;
}
