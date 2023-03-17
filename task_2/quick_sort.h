#ifndef TASK_2_QUICK_SORT_H
#define TASK_2_QUICK_SORT_H
#include <stdio.h>
#define swap(t,x,y) t temp = x; x = y; y = temp;


int partition(char arr[], int low, int high);
void quick_sort(char arr[], int low, int high);
void print_arr(char arr[], int size);
#endif //TASK_2_QUICK_SORT_H
