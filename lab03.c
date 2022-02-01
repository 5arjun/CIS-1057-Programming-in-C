#include <stdio.h>
#include <math.h>
#define pi = 3.1415926535

double payment_calc(double p, double ir, double m);
double gospers(double in);

int main(){

    
    double principal = 0.0;
    printf("Enter your principal: ");
    scanf("%lf", &principal);

    double air = 0.0;
    printf("Enter annual interest rate: ");
    scanf("%lf", &air);

    double months = 0.0;
    printf("Enter number of payments: ");
    scanf("%lf", &months);

    //function is called, then the payment amount is outputted
    double pay = payment_calc(principal, air, months);
    printf("Your monthly payment is: %.02lf", pay);

    //
    //NEXT
    //PROGRAM #2
    //
    double input = 0.0;
    printf("\nEnter a number: ");
    scanf("%lf", &input);

    double output =  gospers(input);
    printf(" %.00lf! equals approximately %.05lf", input, output);

    return 0;
}

double payment_calc(double p, double ir, double m){
    // p is principal, ir is annual interest rate, m is # of payments
    //mInt is the MONTHLY interest rate percentage
    double mInt = ir / 12 / 100;
    //calculate the numerator of the paymetn equation
    double numerator = mInt * p;
    //calculate the denominator of the paymetn equation
    double denominator = 1- pow((1+mInt),(-m));
    // calculate the payment amount and then return it to main
    double payment = numerator / denominator;
    return payment;
}

double gospers(double in){
    double first = pow(in, in) * exp(-in);
    double second = sqrt((2.0 * in + 1/3) * 3.141592);
    double total = first * second;
    return total;

}