#include <stdio.h>
int problemOne(int in);
double problemTwo(int iterations);

int main(){

    printf("IS IT DIVISIBLE BY 9");
    printf("\nEnter an integer: ");
    int input;
    scanf("%d", &input);
    if(problemOne(input))
        printf("%d is divisible by 9", input);
    else
        printf("%d is NOT divisable by 9", input);

    printf("\nEstimate pi");
    printf("\nEnter number of iterations: ");
    int NumOfI;
    scanf("%d", &NumOfI);
    double rpi = problemTwo(NumOfI);
    printf("Estimated PI is %lf", rpi);
return 0;
}

int problemOne(int in){
    int count = 0;
    int adding;
    while(in>0){    
        adding = in % 10;    //adds the remainder of the bumber divided by 10
        count += adding;    //adding digit by digit
        in = in / 10;    //divids by 10 go move on to the next digit
    }    
    if (count % 9 == 0)
        return 1; //if the number is divisable by 9
    else
        return 0; // if its not divisable by 9
    
}

double problemTwo(int iterations){
    double pi = 4;
    
    double mult;
    double dencount = 1;
    double posneg = 1;
    double pimult = 0;
    for(int count = 1; count <= iterations; count++){
        
        double den = 1 / dencount;
        mult = den * posneg;
        posneg *= -1;
        dencount += 2;
        pimult += mult;
    }
    pi *= pimult;
    return pi;
}