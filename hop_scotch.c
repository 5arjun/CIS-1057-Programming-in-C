/*
    Hopscotch

    Write a program to print a hop-scotch board as described
    below.

    1. Include the standard input/output library.
    2. Write an empty main with return.
    3. Write a function called hop_scotch that accepts an integer,
        prints the board, and returns nothing.
    4. Write a loop to iterate until it prints the outputs for
        given inputs below.
    5. Add any additional code to produce the correct output.
    6. Add function call to main.
    7. Test and submit your program.

    Sample output for number = 0 -> (below is two spaces, a 1, and two
                                     spaces)

      1

    Sample output for number = 1 -> (the second row prints 2, three
                                     spaces, and 3 on one line; and
                                     two spaces, a 4, and two
                                     spaces on the other)

      1
    2   3
      4

    Sample output for number = 2 ->

      1
    2   3
      4
    5   6
      7

    Sample output for number = 3 ->

      1
    2   3
      4
    5   6
      7
    8   9
      10

*/

// Preprocessor statements
#include <stdio.h>

// Prototypes
void hop_scotch(int input);

// Main function
int main(){

  printf("Enter the number of iterations: ");
  int iterations = 0;
  scanf("%d", &iterations);
  hop_scotch(iterations);
}

// Hop-scotch function
void hop_scotch(int input){
    int numbers = 0;
    for(int i; i <= input; i++){
        numbers++;
        printf("  %d  \n", numbers);
        numbers++;
        printf("%d   ", numbers);
        numbers++;
        printf("%d\n", numbers);
        numbers++;
        printf("  %d  \n", numbers);

    } 

}
