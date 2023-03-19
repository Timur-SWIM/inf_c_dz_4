#include "db.h"

void add_student(struct student students[], int *studnum) {
    if (*studnum == MAX) {
        puts("Too much students!\n");
        return;}
    struct student new_struct;
    printf("Input student's ID:");
    scanf("%d", &new_struct.ID);
    printf("Input student's name:");
    scanf("%s", new_struct.name);
    printf("Input student's number:");
    scanf("%s", new_struct.number);
    printf("Input student's average score:");
    scanf("%f", &new_struct.average_score);
    students[*studnum] = new_struct;
    (*studnum)++;
}
void show_student(struct student students[], int studnum, int ID) {
    for (int i = 0; i < studnum; ++i) {
        if (ID == students[i].ID) {
            printf("ID - %d; Name - %s; Number - %s; Average score - %f\n", students[i].ID,
                   students[i].name, students[i].number,
                   students[i].average_score);
        } else {
            puts("Student is not found!");
            return;}
    }
}
void delete_student(struct student students[], int *studnum, int ID) {
    printf("Input student's ID:\n");
    scanf("%d", &ID);
    for (int i = 0; i < *studnum; i++) {
        if (ID == students[i].ID) {
            for (int j = i; j < *studnum - 1; j++) {
                students[j] = students[j + 1];
            }
            (*studnum)--;
            return;
        }
    }
}
void merge(float arr[], int l, int m, int r)
{
    int i, j, k;
    int n1 = m - l + 1;
    int n2 = r - m;
    float L[n1], R[n2];

    for (i = 0; i < n1; i++)
        L[i] = arr[l + i];
    for (j = 0; j < n2; j++)
        R[j] = arr[m + 1 + j];
    i = 0; j = 0; k = l;

    while (i < n1 && j < n2) {
        if (L[i] <= R[j]) {
            arr[k] = L[i];
            i++;
        }
        else {
            arr[k] = R[j];
            j++;
        }
        k++;
    }
    while (i < n1) {
        arr[k] = L[i];
        i++;
        k++;
    }
    while (j < n2) {
        arr[k] = R[j];
        j++;
        k++;
    }
}
void mergeSort(float arr[], int l, int r)
{
    if (l < r) {
        int m = l + (r - l) / 2;
        mergeSort(arr, l, m);
        mergeSort(arr, m + 1, r);
        merge(arr, l, m, r);
    }
}
void output_rating(struct student students[], int studnum){
    for (int i = 0; i < studnum; ++i) {
        printf("ID - %d; Name - %s; Number - %s; Average score - %0.2f\n",
               students[i].ID, students[i].name, students[i].number, students[i].average_score);
    }
}
