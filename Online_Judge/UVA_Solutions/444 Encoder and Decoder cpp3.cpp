#include<iostream>
#include<stdio.h>
using namespace std;
int main(){
    ios_base::sync_with_stdio(false);       /* Browsing codeforces found this and next make cin, cout faster */
    cin.tie(0);
    int i,j,a;
    string s;
	while(getline(cin,s)){
        for(i=0; s[i]!='\0'; ++i);          /* Find out the length of string */
        for(j=i-1; j>=0;){                  /* Start processing the string/input backward */
            if(s[0]>='0' && s[0]<='9'){     /* Check if the input is encoded integer. Also checking with s[0] or the first character is enough since it can either be numbers or letters */
                if(s[j]!='1'){              /* Check if the character is of length 2 because No input below 100 Ascii value of (d) contains integer length 2 */
                    a = (s[j-1]-'0') + (s[j]-'0')*10;   /* Make the last digits 10s and 1st digit in 1s place. Ex: 79 = 7+(9*10) = 97 */
                    j-=2;                   /* Decrease the loop counter by two since we have processed two digits. Meaning the integer was 99 or below */
                }else{
                    a = s[j-2]-'0' + (s[j-1]-'0')*10 + (s[j] -'0')*100; /* Make the last digits 100s, middle 10s and 1st digit in 1s place. Ex: 101 = 1+(0*10)+(1*100) = 101 */
                    j-=3;                   /* Decrease the loop counter by Three since we have processed Three digits. Meaning the integer was 100 or above */
                }
                cout << (char)a;            /* Since the input was a number and we decoded it to a character now just print that character */
            }else{                          /* If not encoded integer it is obviously a string */
                a = s[j];                   /* Store the ASCII integer value of the character */
                while(a){
                    cout << a%10;           /* Print the last integer digit of (a) */
                    a /=10;                 /* Discard the last digit */
                }
                --j;                        /* Decrease the loop counter since One character is processed */
            }
        }
        cout << endl;                       /* Also reading up i have found endl is slow, rather using '\n' is suggested */
	}
	return 0;
}
