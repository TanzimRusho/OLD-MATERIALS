/**
 * @author  Quickgrid ( Asif Ahmed )
 * @link    https://quickgrid.wordpress.com
 * Problem: UVA
 */

#include<stdio.h>

int main(){
	static int sum, max, val, exit;
    static char c;

	while(1){
        sum = max = 0;

        while(1){
            exit = scanf("%d%c", &val, &c);
            if(exit == -1)
                return 0;

            sum += val;

            if(sum < 0)
                sum = 0;

            if(sum > max)
                max = sum;

            if(c == '\n')
                break;
        }

        printf("%d\n", max);
	}
	return 0;
}
