#include <stdio.h>
#include <stdlib.h>
#include "quick_sort.h"
#include "binary_search.h"
#include "chek.h"

int main(int argc, char *argv[]) {
    check(argc, &argv[2], atoi(argv[1]));

    printf("The entered array: %s\n", argv[2]);
    quick_sort(argv[2], 0, atoi(argv[1]) - 1);
    printf("The sorted array: %s\n", argv[2]);

    int x_id;
    char x;

    printf("Input x=");
    scanf("%c", &x);
    x_id = binary_search(argv[2], x, 0, atoi(argv[1]) - 1);
    if (x_id < 0){
        printf("Error: X not find\n");
        return -1;}
    printf("x_index = %d\n", x_id + 1);
    return 0;
}
