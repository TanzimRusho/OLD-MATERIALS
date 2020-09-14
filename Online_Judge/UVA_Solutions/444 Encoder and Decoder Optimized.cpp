/*
 * @author Quickgrid ( Asif Ahmed )
 * @link   https://quickgrid.wordpress.com
 */

#include<iostream>
#include<stdio.h>

using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int i, j, a;
    string s;

    while (getline(cin, s)){
        /*
         * Find out the length of string
         */
        for (i = 0; s[i]; ++i);

        /*
         * Start processing the string/input backward
        */
        for (j = i-1; j >= 0;){
            /*
             * Check if the input is encoded integer. Also checking with s[0] or the first character is enough since it can either be numbers or letters
            */
            if (s[0] >= '0' && s[0] <= '9'){
                /*
                 * Check if the character is of length 2 because No input below 100 Ascii value of (d) contains integer length 2
                 */
                if (s[j] != '1'){
                    /*
                     * Make the last digits 10s and 1st digit in 1s place. Ex: 79 = 7+(9*10) = 97
                     */
                    a = (s[j-1] - '0') + (s[j] - '0') * 10;
                    /*
                     * Decrease the loop counter by two since we have processed two digits. Meaning the integer was 99 or below
                     */
                    j -= 2;
                }else{
                    /*
                     * Make the last digits 100s, middle 10s and 1st digit in 1s place. Ex: 101 = 1+(0*10)+(1*100) = 101
                     */
                    a = s[j-2] - '0' + (s[j-1] - '0') * 10 + (s[j] - '0') * 100;
                    /*
                     * Decrease the loop counter by Three since we have processed Three digits. Meaning the integer was 100 or above
                     */
                    j-=3;
                }
                /*
                 * Since the input was a number and we decoded it to a character now just print that character
                 */
                cout << (char)a;
            }
            /*
             * If not encoded integer it is obviously a string
             */
            else{
                /*
                 * Store the ASCII integer value of the character
                 */
                a = s[j];

                while (a){
                    /*
                     * Print the last integer digit of (a)
                     */
                    cout << a % 10;
                    /*
                     * Discard the last digit
                     */
                    a /= 10;
                }
                /*
                 * Decrease the loop counter since One character is processed
                 */
                --j;
            }
        }
        cout << endl;
    }
    return 0;
}
