#include <stdio.h>


int main (){
    /*
    char s [100];
    FILE *file = fopen("homer.txt", "r");

    if (file != NULL){
        while(fscanf(file, "%s", s) != EOF){
            printf("s = %s\n"), s
        }
        fclose(file);
    }

    */
   printf("Enter a number: ");
   int x = 1;
   scanf("%d", &x);

 /*   while (x < 1 || x > 5){
        printf("Errpr num has to be between 1 n 5\n");
        printf("Enter a number: ");
        scanf("%d", &x);
    }
*/
    do{
        if(x < 1 || x > 5)
        printf("Errpr num has to be between 1 n 5\n");
        printf("Enter a number: ");
        scanf("%d", &x);
    }while (x < 1 || x > 5); 

return 0;
}