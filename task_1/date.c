#include "date.h"

int str_to_int(char str[]){
    int count = 0;
    while (str[count] != '\0'){
        if (!isdigit(str[count]))
            return -1;
        count++;
    }
    return atoi(str);
}

char *init_data(char str[], int start, int size){
    char * new_str = (char *) malloc(sizeof(char) * (size + 1));
    strncpy(new_str, str + start, size);
    return new_str;
}

int init_date(Date_t *date, char str[]){
    date->day = str_to_int(init_data(str, 0, 2));
    date->month = str_to_int(init_data(str, 3, 2));
    date->year = str_to_int(init_data(str, 6, 4));

    if (date->day == 0 || date->month == 0 || date->year == 0)
        return EXIT_FAILURE;
    if (date->day > 31 || date->month > 12)
        return EXIT_FAILURE;
    return 0;
}

int init_time(Time_t *time, char str[]){
    time->hour = str_to_int(init_data(str, 0, 2));
    time->minute = str_to_int(init_data(str, 3, 2));
    time->second = str_to_int(init_data(str, 6, 2));

    if (time->second < 0 || time->minute < 0 || time->hour < 0)
        return EXIT_FAILURE;
    if (time->hour > 23 || time->minute > 59 || time->second > 59)
        return EXIT_FAILURE;
    return 0;
}

int init_datetime(DateTime_t *datetime, char str[]){
    int err;
    Date_t date;
    err = init_date(&date, init_data(str, 0, 10));
    if (err){
        return EXIT_FAILURE;
    }
    Time_t time;
    err = init_time(&time, init_data(str, 11, 8));
    if (err)
        return EXIT_FAILURE;

    datetime->date = date;
    datetime->time = time;

    return 0;
}
void print_datetime(DateTime_t datetime){
    printf("%02d.%02d.%04d ", datetime.date.day, datetime.date.month, datetime.date.year);
    printf("%02d:%02d:%02d", datetime.time.hour, datetime.time.minute, datetime.time.second);
}

long long calk_delta(DateTime_t datetime1, DateTime_t datetime2){
    int min_year = datetime1.date.year< datetime2.date.year ? datetime1.date.year : datetime2.date.year;

    long long date1_to_sec = datetime1.time.second +
                            datetime1.time.minute * 60 +
                            datetime1.time.hour * 3600 +
                            (datetime1.date.day - 1) * 24 * 3600 +
                            (datetime1.date.month - 1) * 30 * 24 * 3600 +
                            (datetime1.date.year - min_year) * 12 * 30 * 24 * 3600;

    long long date2_to_sec = datetime2.time.second +
                             datetime2.time.minute * 60 +
                             datetime2.time.hour * 3600 +
                             (datetime2.date.day - 1) * 24 * 3600 +
                             (datetime2.date.month - 1) * 30 * 24 * 3600 +
                             (datetime2.date.year - min_year) * 12 * 30 * 24 * 3600;

    long long delta = date1_to_sec > date2_to_sec ?
                      date1_to_sec - date2_to_sec:
                      date2_to_sec - date1_to_sec;

    return delta;
}

DateTime_t init_res(long long delta){
    DateTime_t datetimeRes;
    datetimeRes.time.second = (int) (delta % 60);
    delta /= 60;
    datetimeRes.time.minute = (int) (delta % 60);
    delta /= 60;
    datetimeRes.time.hour = (int) (delta % 24);
    delta /= 24;
    datetimeRes.date.day = (int) (delta % 30);
    delta /= 30;
    datetimeRes.date.month = (int) (delta % 12);
    delta = 12;
    datetimeRes.date.year = (int) (delta);

    return datetimeRes;
}