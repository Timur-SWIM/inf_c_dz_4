#include <stdio.h>
#include <stdlib.h>
#include "quick_sort.h"
#include "binary_search.h"

int main(int argc, char *argv[]) {
    printf("%s\n", argv[2]);
    quick_sort(argv[2], 0, atoi(argv[1]) - 1);
    printf("%s\n", argv[2]);
    int x_id;
    char x;
    printf("Input x=");
    scanf("%c", &x);
    x_id = binary_search(argv[2], x, 0, atoi(argv[1]) - 1);
    printf("\n%d", x_id);
    return 0;
}
