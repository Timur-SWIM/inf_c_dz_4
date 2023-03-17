#include "quick_sort.h"

int partition(char arr[], int low, int high){
    char pivot = arr[high];
    int i = low - 1;

    for (int j = low; j < high; j++){
        if (arr[j] < pivot){
            ++i;
            swap(char , arr[i], arr[j]);
        }
    }
    swap(char , arr[i + 1], arr[high]);
    return (i + 1);
}

void quick_sort(char arr[], int low, int high){
    if (low < high){
        int p = partition(arr ,low, high);

        quick_sort(arr, low, p - 1);
        quick_sort(arr, p + 1, high);
    }
}

void print_arr(char arr[], int size){
    for (int i = 0; i < size; i++){
        printf("%c", arr[i]);
    }
    printf("\n");
}


