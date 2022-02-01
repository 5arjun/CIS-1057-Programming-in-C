#include <stdio.h>

int problemOne (int month, int day, int year);
void problemTwo(int observed);
int within_x_percent(double realTemp, double inputTemp, double percent);

int main(){
    int inMonth, inDay, inYear;
    printf("CALCULATE DAY OF YEAR\n");
    printf("Enter date: ");
    scanf("%d %d %d",&inMonth, &inDay, &inYear);//input month day year

    int tot = problemOne(inMonth, inDay, inYear); //call to function
    printf("%d/%d/%d is the %dth day of %d",inMonth, inDay, inYear, tot, inYear);


    printf("\nFIND SUBSTANCE FOR BOILING POINT\nEnter a temperature: ");
    double input = 0;
    scanf("%lf", &input);
    problemTwo(input);
    return 0;
}

int problemOne (int month, int days, int year){


    int totalDays = 0; 
    int isLeapYear = 0;
    //to find out if the year is a leap year
    if(year % 4 == 0 && year / 100 != 0 )//divides by 4 evenly but not 100
        isLeapYear = 1;
        
    else if(year % 400 == 0)//divides by 400 evenly
        isLeapYear = 1;
    // loop if it IS a leap year
    if(isLeapYear){
        for (int i = 1; i < month; i++){

            if(i == 2){  //just for february
                totalDays += 30;
            }
            else if (i % 2 == 1){ //for the odd number months with 31 days
                totalDays += 31;
            }
            else if (i % 2 == 0){ //even number months with 30 days
                totalDays += 30;
            }
            else if (i == 7 || i == 8){ //july and august 31 days
                totalDays += 31;
            } 
        }
        totalDays += days; //adds the day inputted
    }
    else{ //same loop as a bove but with one less day since it is not a leap year
        for (int i = 1; i < month; i++){
            if(i == 2){
                totalDays += 29;
            }
            else if (i % 2 == 1){
                totalDays += 31;
            }
            else if (i % 2 == 0){
                totalDays += 30;
            }
            else if (i == 7 || i == 8){
                totalDays += 31;
            } 
        }
        totalDays += days;

    }
 return totalDays; //return to main function
}

void problemTwo(int observed){

    int exact ;
    double data [5] = {100, 357, 1187, 2193, 2660};//array for the boiling points
    for (int i = 0; i <= 5; i++){//loops 5 times and calls function to find which substance
        int whichSubstance = within_x_percent(data[i], observed, 5);//sets whichsubstance to 1 or 0 depending on if the # is within 5%
        if (whichSubstance == 1){
           exact = data[i];
           break;
        }
    }
    switch (exact)
    {
    case 100:
        printf("\nThe substance is Water");
        break;
    case 357:
        printf("\nThe substance is Mercury");
        break;
    case 1187:
        printf("\nThe substance is copper");
        break;
    case 2193:
        printf("\nThe substance is Silver");
        break;
    case 2660:
        printf("\nThe substance is Gold");
        break;

    default:
        printf("\nThe substance is unknown");
        break;
    }
}

int within_x_percent(double realTemp, double inputTemp, double percent){
    int tf;
        double plusminus = realTemp * (percent / 100);
        if (inputTemp <= realTemp + plusminus && inputTemp >= realTemp - plusminus)
             tf = 1;
        else
             tf = 0;
    return tf;
}
