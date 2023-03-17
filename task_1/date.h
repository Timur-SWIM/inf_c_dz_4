#ifndef TASK_1_DATE_H
#define TASK_1_DATE_H

#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <stdio.h>

typedef struct Date{
    int year, month, day;
}Date_t;
typedef struct Time{
    int hour, minute, second;
}Time_t;
typedef struct DateTime{
    struct Date date;
    struct Time time;
}DateTime_t;

int str_to_int(char str[]);
char * init_data(char str[], int start, int size);
int init_date(Date_t *date, char str[]);
int init_time(Time_t *time, char str[]);
int init_datetime(DateTime_t *dateTime, char str[]);
void print_datetime(DateTime_t datetime);
long long calk_delta(DateTime_t datetime1, DateTime_t datetime2);
DateTime_t init_res(long long delta);
#endif //TASK_1_DATE_H
