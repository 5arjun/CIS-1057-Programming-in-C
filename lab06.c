#include <stdio.h>
void problemOne( int dollars, int *fifties, int *twenties, int *tens);
void test7_11_13(int input, int *qone, int *qtwo, int *qthree);
int main(){
    /*
    int dol, fif, twe, ten;
    printf("Enter a dollar amount (multiple of 10): ");
    scanf("%d", &dol);
    problemOne(dol, &fif, &twe, &ten);
    printf("\n Fifties: %d\n Twenties: %d\n Tens: %d\n", fif, twe, ten);
    */

    printf("\nQUESTION 2\nEnter a number: ");
    int input;
    int qone, qtwo,  qthree;
    scanf("%d", &input);
    test7_11_13( input, &qone,  &qtwo,  &qthree);
    printf("%d\n", qone);
    if(qtwo)
        printf("the sum is an even number\n");
    else
        printf("The sum is an odd number\n");
    if (qthree)
        printf("Not a prime number.\n");
    else   
        printf("This is a prime number.\n");
    

    return 0;

}

void problemOne( int dollars, int *fifties, int *twenties, int *tens){
    
    while (dollars >= 49){
        dollars -= 50;
        *fifties += 1;  
    }
    while (dollars >=19){
        dollars -= 20;
        *twenties += 1;
    }
    while (dollars >0){
        dollars -= 10;
        *tens += 1;
    }

}

void test7_11_13(int input, int *qone, int *qtwo, int *qthree){
    if (input % 7 == 0 || input % 11 == 0 || input % 13 == 0)
        *qone = 1;

    for (int i; i < input; i++){
        if (input % i == 0)
            *qthree = 0;
        else    
            *qthree = 1;
    }

    int add;
    int total;
    while (input > 0){
        add = input % 10;
        total += add;
        input /= 10;
    }
    if (total % 2 == 0)
        *qtwo = 1;
    else    
        *qtwo = 0; 
}