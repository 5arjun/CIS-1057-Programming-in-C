#include <stdio.h>

int main(){
    int num;
    for (int i = 2; i < 3; i += 1){
        for(int j = 2; j < 4; j+= 1){
            if (i == j)
                printf("|%d == %d|", i, j);
            else    
               printf("|%d != %d|", i, j);
        }
        
    }
    
    return 0;
}