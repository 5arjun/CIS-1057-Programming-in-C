#include <stdio.h>
#include <math.h>

int main(){

    char fn[50];
    char ln[50];
    int age = 0;

    printf("Reading Simpsons...\n");
    for (int i = 1; i <= 4; i++){
    scanf("%s %s %d", fn, ln, &age);
    printf("%s %s %d\n", fn,  ln, age);
    }
    return 0;
}