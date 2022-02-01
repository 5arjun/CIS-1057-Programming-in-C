#include <stdio.h>
#define RATE 0.48;

int main(){

    printf("MILEAGE REIMBURSEMENT CALCULATOR\n");

    printf("Enter beginning odometer reading: ");
    double start = 0.0;
    //user enters starting mileage
    scanf("%lf", &start);

    printf("Enter ending odometer reading: ");
    //user enters ending mileage
    double end = 0.0;
    scanf("%lf", &end);

    //calculates the amount of miles traveled
    double total = end - start;
    //calculates the amount of reimbursement earned
    double reim = total * RATE;

    printf("You traveled %.01lf. At $0.48 per mile, your reimbursement is $%.02lf", total, reim);

    printf("\nFAHRENHEIT TO CELSIUS CALCULATOR\n");
    printf("Enter temperature in Fahrenheit: ");
    double fah = 0.0;
    scanf("%lf", &fah);
    double cel = (fah - 30) / 2;
    printf(" %.02lf degrees Fahrenheit is %.02lf degrees Celsius", fah, cel);

    return 0;
}