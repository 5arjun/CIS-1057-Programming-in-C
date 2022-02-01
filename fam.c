#include <stdio.h>

int main (){

    char fn [10];
    char ln [10];
    int age = 0;

    
    for (int i = 1; i <= 4; i++){
        scanf ("%s %s %d", fn, ln, &age);
        printf("%s %s %d \n", fn, ln, age);
    }
    return 0;
}