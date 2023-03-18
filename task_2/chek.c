#include "chek.h"

void check(int argc, char *arr[], int size){
    if (argc != 3){
        printf("The program expected two arguments\n");
        exit(-1);
    }
    int s, i = 0;
    while (arr[2][i] != '\0'){
        ++i;
        s++;
    }
    if (s != size){
        printf("The specified size of the array "
               "does not match the number of its elements\n");
        exit(-1);
    }
}