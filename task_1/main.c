#include <stdio.h>
#include "date.h"

int main(int argc, char *argv[]) {
    int err;
    DateTime_t datetime1, datetime2;
    printf("DateTime1\n");
    err = init_datetime(&datetime1, argv[1]);
    if (err){
        printf("Data error\n");
        return -1;}
    print_datetime(datetime1);
    printf("\n");

    printf("DateTime2\n");
    err = init_datetime(&datetime2, argv[2]);
    if (err){
        printf("Data error\n");
        return -1;}
    print_datetime(datetime2);
    printf("\n");

    DateTime_t datetimeRes = init_res(calk_delta(datetime1, datetime2));
    printf("Delta DateTime\n");
    print_datetime(datetimeRes);
    printf("\n");

    return 0;
}
