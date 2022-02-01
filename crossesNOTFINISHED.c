/*

    Draw crosses

    Write a program that prints a cross of +'s and another of x's with a X
    in the center of a field of 0's.

    1. Include the standard input/output library.
    2. Write an empty main with return.
    3. Write a function called crosses that accepts an odd integer,
        prints an X in the center of the field, prints a cross of +'s, a
        diagonal cross of X's and returns nothing. See output.
    6. Add any additional code to produce the correct output.
    7. Add function calls to main.
    8. Test your program with inputs 5, 7 and 9, and submit your program.

    Example of field with number = 5 (first code to print all zeros):

    0 0 0 0 0
    0 0 0 0 0
    0 0 0 0 0
    0 0 0 0 0
    0 0 0 0 0

    Example of field with number = 5 (next, code to add the X):

    0 0 0 0 0
    0 0 0 0 0
    0 0 X 0 0
    0 0 0 0 0
    0 0 0 0 0

    Hint: If the loop control variables count from 0 to n-1, the X
    is at outer loop control variable n/2 and inner at n/2.

    Example of field with number = 5 (next, code +'s in a cross):

    0 0 + 0 0
    0 0 + 0 0
    + + X + +
    0 0 + 0 0
    0 0 + 0 0

    Hint: The n/2 row and n/2 column.

    Example of final result (last, the x's in a diagonal cross):

    x 0 + 0 x
    0 x + x 0
    + + X + +
    0 x + x 0
    x 0 + 0 x

    Hint: From upper right to lower left, i equals j.  From upper
    left to lower right, i + j = (calculate this on paper to find
                                 value for correct locations).

*/

// Preprocessor statements
#include <stdio.h>

// Prototypes

void crosses(int width);
// Main function
int main(){

    int input;
    printf("Enter an odd number: ");
    scanf("%d ", &input);
    crosses(input);
    return 0;
}

// Crosses function
void crosses(int width){
    for (int i = 1; i <= width; i++){
        printf("\n");
        for(int j = 1; j <= width; j++){
            printf("0");
        }
    }
}
