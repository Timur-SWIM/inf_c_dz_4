
#ifndef TASK_3_DB_H
#define TASK_3_DB_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX 50
struct student {
    int ID;
    char name[40];
    char number[15];
    float average_score;
};
void add_student(struct student students[], int *studnum);
void show_student(struct student students[], int studnum, int ID);
void delete_student(struct student students[], int *studnum, int ID);
void merge(float arr[], int l, int m, int r);
void mergeSort(float arr[], int l, int r);
void output_rating(struct student students[], int studnum);
#endif //TASK_3_DB_H
