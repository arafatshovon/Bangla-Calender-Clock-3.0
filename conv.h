#include <stdio.h>


struct Bdate
{
    int banglaYear;
    int banglaDate;
    int banglaMonthIndex;
};


const int midMonthDate[] = {14, 13, 15, 13, 14, 14, 15, 15, 15, 15, 15, 15};
const int totalMonthDays[] = {30, 30, 29, 30, 31, 31, 31, 31, 31, 31, 30, 30};
const int leapYearIndex = 2;  // Leap Year will affect only the day count in 'Falgun'
const int lastMonthIndex = 3;  //'Chaitro' is the last month and its index is 3 in BanglaMonthsList


int isLeapYear(int year) {
    return ((year % 4 == 0) && (year % 100 != 0)) || (year % 400 == 0);
}


int EnToBnYear(int year, int month, int date) {
    int banglaYear = year - 594; // 2017(Gregorian Year) - 594 = 1423(Bangla Year)
    if ((month > lastMonthIndex) || (month == lastMonthIndex && date > 13)) {
        banglaYear += 1;
    }
    return banglaYear;
}

struct Bdate EnglishToBangla(int gDay, int gMonth, int gYear)
{
    gMonth--;
    struct Bdate retval;
    retval.banglaYear = EnToBnYear(gYear, gMonth, gDay);

    int monthDays = totalMonthDays[gMonth];
    if (gDay <= midMonthDate[gMonth])
    {
        if (gMonth == leapYearIndex && isLeapYear(gYear))
        {
            monthDays = totalMonthDays[gMonth] + 1;
        }
        retval.banglaDate = monthDays + gDay - midMonthDate[gMonth];
        retval.banglaMonthIndex = gMonth;
    }
    else
    {
        retval.banglaDate = gDay - midMonthDate[gMonth];
        retval.banglaMonthIndex = (gMonth + 1) % 12; // banglaMonthsList is 0-based indexed
    }

    retval.banglaMonthIndex = (retval.banglaMonthIndex+8)%12+1;
    return retval;
}