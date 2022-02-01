#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>

// Some MACROS here

// function prototypes
int compare_two_strings(char bands[][7], int n, char target[10]);
void KiloOhmCalc (char band1[], char band2[], char band3[]);

void endsInY(char noun[], long length);
void endsInS_Ch_Sh(char noun[], long length);
void otherCases (char noun[], long length);

int longestCommonSuffix (char input1[], char input2[], char outParameter[]);

// main function
int main() {
    printf("PROBLEM 1\n");
    char g = 'y';
    do{
    printf("Enter the colors of the resistor's three bands,\n");
    printf("beginning with the band nearest the end. Type the colors\n");
    printf("in lowercase letters only, NO CAPS.\n");
    char band1[10]; 
    char band2[10];
    char band3[10];
    printf("Band 1 => ");
    scanf("%s", band1);
    printf("Band 2 => ");
    scanf("%s", band2);
    printf("Band 3 => ");
    scanf("%s", band3);
    KiloOhmCalc ( band1,  band2,  band3);
    //asks if they want to do another decode of bands
    printf("\nDo you want to decode another resistor: ");
    scanf("%s", &g);
    }while(g != 'n');


    printf("\n\nPROBLEM 2\n");
    char noun[50];
    printf("Enter a noun: ");
    scanf("%s", noun);
    unsigned long length = strlen(noun);
    if (noun[length-1] == 'y')
        endsInY(noun, length);
    else if (noun[length-1] == 'h' || noun[length-1] == 's')
        endsInS_Ch_Sh(noun, length);
    else    
        otherCases(noun, length);
    printf("The plural of that is %s", noun);

    printf("\n\nPROBLEM 3\n");
    char input1[50];
    char input2[50];
    char outParameter[20];
    int opLength = 0;
    printf("Enter the first string: ");
    scanf("%s", input1);
    printf("Enter the second string: ");
    scanf("%s", input2);

    opLength = longestCommonSuffix(input1, input2, outParameter);
    
    printf("The longest common suffix is : ");
    for(int i = opLength; i >= 0 ; i--)
        printf("%c", outParameter[i]);
    
return 0;
}

int compare_two_strings(char bands[][7], int n, char target[10]){
    for (int i=0; i < n; i++){
        if (strcmp(bands[i], target) == 0){     // compare two strings.
            return i; //returns the place in the list it was found
        }
    }
    return -1;
}

void KiloOhmCalc (char band1[], char band2[], char band3[]){
    // color codes of all bands
    char COLOR_CODES[10][7] = {"black", "brown", "red",
                                "orange", "yellow", "green",
                                "blue", "violet", "gray","white"};

    //gets 2 digits received from the first 2 bands
    int digit1 = compare_two_strings(COLOR_CODES, 10, band1);  // call the function to compare two strings
    int digit2 = compare_two_strings(COLOR_CODES, 10, band2);  // call the function to compare two strings
    int digit3 = compare_two_strings(COLOR_CODES, 10, band3);  // call the function to compare two strings
    //converts the into into chars 
    char charDigit1[3];
    sprintf(charDigit1, "%d", digit1);
    char charDigit2[3];
    sprintf(charDigit2, "%d", digit2);
    
    strcat(charDigit1, charDigit2);//concats the first 2 bands

    int value = atoi(charDigit1); //converts from string to int
    
    int kiloOhms = value * pow(10, digit3);
    printf("Resistance Value: %d Kilo-Ohms", kiloOhms);
    
}

void endsInY(char noun[], long length){
    noun[length-1] = '\0';
    strcat(noun, "ies");
}
void endsInS_Ch_Sh(char noun[], long length){
    strcat(noun, "es");
}
void otherCases (char noun[], long length){
    strcat(noun, "s");
}

int longestCommonSuffix (char input1[], char input2[], char outParameter[]){
    int length1 = strlen(input1);
    int length2 = strlen(input2);

    int i = 0;
    int countOfSame = 0;
    char temp[20];
    while ( i < length1 && i < length2){
        if (input1[length1-1] == input1[length2-1]){
            countOfSame++;
            outParameter[i] = input1[length1-i];
        }
        i++;
    }
    return countOfSame;
}

