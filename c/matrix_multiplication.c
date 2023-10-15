/*
* multiplication of two matrixs
*/
#include <stdio.h>

int array_1[3][3] = {
    {1, 1, 1},
    {2, 2, 2},
    {3, 3, 3}
};
int array_2[3][3] = {
    {3, 3, 3},
    {2, 2, 2},
    {1, 1, 1}
};
int impact[3][3];

void multiplication();

int main(){
    multiplication();
    return 0;
}

void multiplication(){
    for(int i = 0; i < 3; i++){
        for(int j = 0; j < 3; j++){
            impact[i][j] = array_1[i][j] * array_2[i][j];
        }
    }
    for(int i = 0; i < 3; i++){
        printf("{");
        for(int j = 0; j < 3; j++){
            printf(" %d ",impact[i][j]);
        }
        printf("}\n");
    }
}