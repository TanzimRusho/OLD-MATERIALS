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

    // dummy is just an empty node to keep track of front of equation.
    // It is not part of equation. Equation starts after dummy node.
    node* tmp = dummy->next;

    // Print the equation term by term.
    while( tmp != NULL ){
        printf("%c%d%c^%c%d ", tmp->sign, tmp->constant, tmp->variable, tmp->signExponent, tmp->exponent);
        tmp = tmp->next;
    }
    printf("\n");

}


void calculateEquation(node* dummy, double var){

    double sum = 0;
    bool calculable;


    // dummy->next because dummy node is not a part of the equation.
    node* tmp = dummy->next;

    while( tmp != NULL ){

        double constantValue = 0, variableValue = 0;
        calculable = true;

        // make constant negative if the sign is negative.
        constantValue = tmp->constant;
        if(tmp->sign == '-')
            constantValue *= -1;


        // calculate the value of the variable with given exponent.
        variableValue = pow(var, tmp->exponent);
        if(tmp->signExponent == '-'){
            if(variableValue)
                variableValue = (double) 1 / variableValue;
            else
                calculable = false;
        }


        // multiply the calculated value of variable with the constant.
        sum = sum + variableValue * constantValue;

        // calculate the next term of the equation.
        tmp = tmp->next;


        // If not calculable. Ex: divide by zero. then print this.
        if(!calculable){
            printf("Sorry Try something different\n");
            break;
        }

    }

    // print the result.
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


    // Dummy node to make insertion code simpler.
    node* dummy = new node();
    dummy->variable = '$';
    node* current = dummy;


    // Take input of equation term by term.
    // If
    //     taking input from console stop input using null terminator ( ctrl + z ).
    // Else
    //     when taking input from file enter a 0 in a line by itself to stop input.
    while( scanf("%c%d%c%*c%c%d", &sign, &constant, &variable, &signExponent, &exponent ) == 5){
        getchar();
        current = insertNode(current, sign, constant, variable, signExponent, exponent);
    }

    // print the
    printEquation(dummy);


    // Enter different values for the variable to get the value of function.
    while(1){
        printf("Calculate value of Equation for given value (y/n)?\n");

        char choice = getchar();

        if( choice == 'y' ){
            printf("Enter value for the variable:\n");

            double variableValue;
            scanf("%lf", &variableValue);
            getchar();

            calculateEquation(dummy, variableValue);
        }else{
            printf("Exiting...\n");
            break;
        }
    }

    return 0;
}

