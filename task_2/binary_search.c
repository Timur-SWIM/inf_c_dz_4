#include "binary_search.h"

int binary_search(char arr[], char x, int  low, int high){
    if (high > low){
        int mid = (low + (high - 1)) / 2;
        if (arr[mid] == x){
            return mid;}
        if (arr[mid > x]){
            return binary_search(arr, x, mid + 1, high);
        }
        return binary_search(arr, x, low, mid - 1);
    }
    printf("Error: low > high\n");
    return -1;
}