#include <stdio.h>
#include <stdlib.h>
#include "quick_sort.h"

int main(int argc, char *argv[]) {
    char arr[] = {5,4,3,2, 1};
    printf("%s\n", argv[2]);
    print_arr(arr, atoi(argv[1]));
    quick_sort(arr, 0, atoi(argv[1]) - 1);
    print_arr(arr, atoi(argv[1]));
    return 0;
}
