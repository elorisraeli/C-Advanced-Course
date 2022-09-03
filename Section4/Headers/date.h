#ifndef MAIN_H_INCLUDED
#define MAIN_H_INCLUDED

// Header file for working with dates
#include <stdbool.h>

// Enumerated types

enum kMonth
{
    January = 1,
    February,
    March,
    April,
    May,
    June,
    July,
    August,
    Swptember,
    October,
    November,
    December
};
enum kDay
{
    Sunday,
    Monday,
    Tuesday,
    Wednesday,
    Thursday,
    Friday,
    Saturday
};

struct date
{
    enum kDay day;
    enum kMonth month;
    int year;
};

// Data type
typedef struct date Date;

// Functions that work with dates
Date dateUpdate(Date today);
int numberOfDays(Date d);
bool isLeapYear(Date d);

// Macro to set a date in a structure
#define setDate(s, dd, mm, yy) s = (Date) { dd, mm, yy }

// External variable reference
extern Date todaysDate;

#endif