#include <stdio.h>
#include <math.h>

int main (){

    int nums[20];
    int count = 0;
    int sum = 0;
    printf("How many numbers do you want to add: ");
    scanf("%d", &count);

    for ( int i = 1; i <= count; i++){
        printf("\nEnter number %d: ", i); 
        scanf("%d", &nums[i]);
        sum += nums[i];
    } 
    printf("The sum is: %d", sum);
    return 0;
}