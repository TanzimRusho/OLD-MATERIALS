#include<stdio.h>
#include<math.h>
#include<string.h>


#define STACK_SIZE 1000



static char query[ STACK_SIZE ];

int queryLength;




/*****************************************************/
// BEGIN: Implementation of Number & Sign Stack
/*****************************************************/


static char signStack[ STACK_SIZE ];
static int numberStack[ STACK_SIZE ];


int topSign = -1, topNumber = -1;

void pushNumber(int n) {
    numberStack[ ++topNumber ] = n;
}


int popNumber() {
    return numberStack[ topNumber-- ];
}



void pushSign(char c) {
    signStack[ ++topSign ] = c;
}


char popSign() {
    return signStack[ topSign-- ];
}



/*****************************************************/
// BEGIN: Implementation of Number & Sign Stack
/*****************************************************/





/*****************************************************/
// BEGIN: Implementation of Digit Stack
/*****************************************************/

int digitStack[ STACK_SIZE ];
int top = -1;

void push(int n) {
    digitStack[ ++top ] = n;
}


int pop() {
    return digitStack[ top-- ];
}

/*****************************************************/
// END: Implementation of Digit Stack
/*****************************************************/



/*****************************************************/
// BEGIN: Conversion to Number
/*****************************************************/


int stackToNumber() {

    int previousNumber = 0;
    int power = 1;

    while(top >= 0) {

        previousNumber = pop() * power + previousNumber;

        power *= 10;

    }

    //printf("** %d\n", previousNumber);

    return previousNumber;

}


/*****************************************************/
// END: Conversion to Number
/*****************************************************/



/*****************************************************/
// BEGIN: Number & Sign Stack
/*****************************************************/

void pushToNumberStack() {

    if(top == -1)
        return;
    else {
        int n = stackToNumber();

        //printf("*** %d\n", n);

        pushNumber( n );
    }
}

/*****************************************************/
// END: Number & Sign Stack
/*****************************************************/


static char replacement[ STACK_SIZE ], queryCopy[ STACK_SIZE ];


int main() {

    int i;

    int times;
    int cases = 1;
    scanf("%d", &times);

    while(times--) {

        // reset
        top = topNumber = topSign = -1;
        memset(digitStack, 0, sizeof digitStack);
        memset(numberStack, 0, sizeof numberStack);
        memset(signStack, 0, sizeof signStack);
        memset(query, 0, sizeof query);
        memset(replacement, 0, sizeof replacement);
        memset(queryCopy, 0, sizeof queryCopy);


        /**
         * Take string input.
         */
        scanf("%s", query);
        scanf("%s", replacement);

        int repTracker = 0;

        /**
         * Get the length of the String
         */
        for(i = 0; query[i]; ++i){
            if(query[i] == '#'){
                query[i] = replacement[repTracker];
                ++repTracker;
            }
            queryCopy[i] = query[i];
        }



        /**
         * Push digits to stack.
         */
        queryLength = i;


        for(i = 0; i < queryLength; ++i) {
            switch(query[i]) {

            case '(':
                pushToNumberStack();
                break;

            case '+':
                pushToNumberStack();
                pushSign(query[i]);
                break;

            case '-':
                pushToNumberStack();
                pushSign(query[i]);
                break;

            case '/':
                pushToNumberStack();
                pushSign(query[i]);
                break;

            case ')': {
                pushToNumberStack();

                char operation = popSign();
                int number = popNumber();
                int temp;

                switch(operation) {
                case '+':
                    temp = popNumber() + number;
                    break;
                case '-':
                    temp = popNumber() - number;
                    break;
                case '/':
                    temp = popNumber() / number;
                    break;
                }

                //printf("Calculated: %d\n", temp);

                pushNumber(temp);
            }
            break;

            default:
                if(query[i] >= '0' && query[i] <= '9')
                    push(query[i] - '0');
                else {
                    pushToNumberStack();
                    printf("Unsupported Input\n");
                    return 0;
                }
            }

        }

        int j;
        for(j = 0; signStack[j]; ++j);
        while(j--){
                pushToNumberStack();

                char operation = popSign();
                int number = popNumber();
                int temp;

                switch(operation) {
                case '+':
                    temp = popNumber() + number;
                    break;
                case '-':
                    temp = popNumber() - number;
                    break;
                case '/':
                    temp = popNumber() / number;
                    break;
                }
                pushNumber(temp);
        }

        printf("Case %d:\n%s\n", cases++, queryCopy);
        printf("%d\n", popNumber());

    }

    return 0;
}
