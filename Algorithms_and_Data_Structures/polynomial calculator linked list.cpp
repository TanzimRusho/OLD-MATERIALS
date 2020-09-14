/**
 * Author:    Asif Ahmed
 * Site:      https://quickgrid.wordpress.com
 * Problem:   Simple Polynomial data structure and
 *            Calculator with single variable.
 */

#include<stdio.h>
#include<string.h>
#include<math.h>


#define N 512


char input[N];


struct PolynomialEquation{

    char sign;
    char signExponent;
    int exponent;
    char variable;
    int constant;

    struct PolynomialEquation *next;
};
typedef struct PolynomialEquation node;



node* insertNode(node* current, char sign, int constant, char variable, char signExponent, int exponent){

    node* temp = new node();

    temp->sign = sign;
    temp->signExponent = signExponent;
    temp->exponent = exponent;
    temp->variable = variable;
    temp->constant = constant;

    temp->next = NULL;
    current->next = temp;
    current = temp;

    return current;
}


void printEquation(node* dummy){
    node* tmp = dummy->next;
    while( tmp != NULL ){
        printf("%c%d%c^%c%d ", tmp->sign, tmp->constant, tmp->variable, tmp->signExponent, tmp->exponent);
        tmp = tmp->next;
    }
    printf("\n");
}


void calculateEquation(node* dummy, int var){

    double sum = 0;
    bool calculable;


    node* tmp = dummy->next;
    while( tmp != NULL ){

        double constantValue = 0, variableValue = 0;
        calculable = true;


        constantValue = tmp->constant;
        if(tmp->sign == '-')
            constantValue *= -1;


        variableValue = pow(var, tmp->exponent);
        if(tmp->signExponent == '-'){
            if(variableValue)
                variableValue = (double) 1 / variableValue;
            else
                calculable = false;
        }


        sum = sum + variableValue * constantValue;
        tmp = tmp->next;


        if(!calculable){
            printf("Sorry Try something different\n");
            break;
        }

    }

    if(calculable)
        printf(">>\t %f\n", sum);

}


int main(){

    // Comment these lines to do I/O operation in console.
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);



    char sign;
    char signExponent;
    int exponent;
    char variable;
    int constant;



    node* dummy = new node();
    dummy->variable = '$';
    node* current = dummy;


    while( scanf("%c%d%c%*c%c%d", &sign, &constant, &variable, &signExponent, &exponent ) == 5){
        getchar();
        current = insertNode(current, sign, constant, variable, signExponent, exponent);
    }

    printEquation(dummy);


    while(1){
        printf("Calculate value of Equation for given value (y/n)?\n");

        char choice = getchar();

        if( choice == 'y' ){
            printf("Enter value for the variable:\n");

            int variableValue;
            scanf("%d", &variableValue);
            getchar();

            calculateEquation(dummy, variableValue);
        }else{
            printf("Exiting...\n");
            break;
        }
    }

    return 0;
}
