#include <stdio.h>

//PROBLEM ONE FUNCTIONS:
void printFunc (int a[4][3], int *masses, int n);
void calcCenterOfMass (int ptr[4][3], int masses[4]);
void sum_columns (int ptr[4][3], int sum[3]);
int sum_masses(int masses[4]);
void sumOverM( int sumC[3], int sumM);
//PROBLEM 2 FUNCTIONS
void print_array (int sArray[], int length);
int binary_search ( int sArray[], int length, int find);
//PROBLEM 3 FUNCTIONS
void bubble_sort(int array[], int length);
void print_array2( int array[], int length );


int main(){
    printf("PROBLEM 1: \n");
    int n = 4;
    int test[4][3] = {{5,-4,3,} , {4,3,-2}, {-4,-3,-1} , {-9,8,6}};
    
    int masses[4] = {2,5,2,1};
    printFunc(test, masses, n);
    calcCenterOfMass(test, masses);


    printf("\n\nPROBLEM THREE\n");
    int arrayThree[10] = {9,8,7,6,5,4,3,2,1,0};
    int lengthTwo = 10;
    
    print_array2(arrayThree, 10);
    bubble_sort(arrayThree, 10);
    printf("\n");
    print_array(arrayThree, 10);


    int length ;
    int arrayTwo[10] = {0,1,2,3,4,5,6,7,8,9};
    printf("\n\n\nPROBLEM TWO\n");
    print_array(arrayTwo, length);
    
    int index = binary_search(arrayTwo, length, 6);
    printf(" \n Found at index %d", index);


    
    return 0;
}

void printFunc (int a[4][3], int *masses, int n){
    //this function prints everything given in the problem
    //prints out the xyz points
    printf("Locations: \n");
    for (int i = 0; i < 4; i++){
        for (int j = 0; j < 3; j++){
            printf(" %3d", a[i][j]);
        }
        printf("\n");
    }
    //PRINTS OUT THE RESPECTIVE MASSES
    printf("Masses: \n");
    for (int i = 0; i < 4; i++){
        printf("%d\n", masses[i]);
    }
    //prints n
    printf("Number of Data Points:\n");
    printf("n = %d\n", n);
}

void calcCenterOfMass (int ptr[4][3], int masses[4]){
    //this loop multiplies each coord by its respective mass
    for(int i = 0; i < 4; i++){
        for(int j = 0; j < 3; j++){
            ptr[i][j] *= masses[i]; 
            printf(" %3d", ptr[i][j]);
        }
        printf("\n");
    }
    int sumColumns[3];
    //calls function to find the sum of each column
    sum_columns(ptr, sumColumns );
    
    
    sumOverM(sumColumns, sum_masses(masses) );

}
void sum_columns (int ptr[4][3], int sum[3]){
    int x = 0; //holds the sum of column
    
    

    for(int i = 0; i < 3; i++){
        for (int j = 0; j < 4; j++){
            x += ptr[j][i];
        }
        sum[i] = x;
        
        x = 0;//resets the sum of columns to 0
    }
}

int sum_masses(int masses[4]){
    //this function adds up all of the masses given
    int sumMasses = 0;
    for (int i = 0; i < 4; i++)
        sumMasses+= masses[i];

    return sumMasses;
}

void sumOverM( int sumC[3], int sumM){
    //this function calculates the center of gravity by dividing
    // the sum of columns by the usm of masses.
    printf("\nCenter of mass: \n( ");
    for(int i = 0; i < 3; i++){
            printf(" %.1f ", (double)sumC[i]/(double)sumM); //casts the ints as doubles
    }
    printf(")");
}

void print_array (int sArray[], int length){
    for(int i = 0; i < length-1; i++)
        sArray[i] = i;
    for (int i = 0; i < length-1; i++)
        printf("%d ", sArray[i]);
}

int binary_search ( int sArray[], int length, int find){
    int bottom = 0;
    int top = length-1;;
    int middle = 0;
    
    while(bottom <= top){
        middle = (top + bottom) / 2;
        if(find < sArray[middle]){
            top = middle + 1;
        }
        else if (find > sArray[middle]){
            bottom = middle + 1;
        }
        else if (bottom > top)
            break;
        else 
            return middle;
    }

   return -1;
}

void bubble_sort(int array[], int length){
    for(int i = 0; i < length - 1; i++){
        for(int j = length - 1; j > 0; j--)
        if(array[j] < array[j-1]){
            int temp = array[j];
            array[j] = array[j - 1];
            array[j - 1] = temp;
        }
        
    }
}

void print_array2( int array[], int length ){


    for (int i = 0; i < length; i++)
        printf("%d ", array[i]);
}