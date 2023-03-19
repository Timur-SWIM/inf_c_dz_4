#include "main.h"

int main() {
    float arr[MAX];
    char action;
    int ID, studnum = 0;
    struct student students[MAX];
    for(int i = 0; i < studnum-1; i++){
        arr[i] = students[i].average_score;
    }
    while (1) {
        puts("\nAdd student - a");
        puts("Show information about student - i");
        puts("Delete student - d");
        puts("Output rating - r");
        puts("Exit - e");
        printf("Input action with database:");
        scanf("%c", &action);
        switch (action) {
            case 'a':
                add_student(students, &studnum);
                break;
            case 'i':
                printf("Input student's ID:\n");
                scanf("%d", &ID);
                show_student(students, studnum, ID);
                break;
            case 'd':
                delete_student(students, &studnum, ID);
            case 'r':
                output_rating(students, studnum);
                break;
            case 'e':
                return 0;
            default:
                printf("Invalid input!\n");
                break;
        }
    }
}
