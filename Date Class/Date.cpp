#include "Date.h"
#include <iostream>
#include <math.h>  
using namespace project;

Date::Date():m_day(1), m_month(1), m_year(1900) //5 
{
    
}

Date::Date(int d, int m, int y) :m_day(d), m_month(m), m_year(y)//6
{

}


Date::Date(const char *p) //7
{
    //  Format: gg/aa/yil
    std::vector<std::string> v = split (p, '/');
    m_day = stoi(v[0]);
    m_month = stoi(v[1]);
    m_year = stoi(v[2]);
}


Date::Date(std::time_t timer) //8
{
    tm * local_time = localtime(&timer);
    m_year = 1900 + local_time->tm_year;
    m_month = 1 + local_time->tm_mon;
    m_day = local_time->tm_mday;
}


int Date::get_month_day()const //9
{
    return m_day;
}


int Date::get_month()const //10
{
    return m_month;
}
int Date::get_year()const //11
{
    return m_year;
}


int Date::get_year_day()const //12
{
    constexpr unsigned int days_to_month[2][12] =
      {
         // non-leap year
         { 0, 31, 59, 90, 120, 151, 181, 212, 243, 273, 304, 334 },
         // leap year
         { 0, 31, 60, 91, 121, 152, 182, 213, 244, 274, 305, 335 },
      };
    bool is_leap = m_year % 4 == 0 && (m_year % 100 != 0 || m_year % 400 == 0);
    return days_to_month[is_leap][m_month - 1] + m_day;
}


Date::Weekday Date::get_week_day()const //13
{
    int d = m_day;
    int m = m_month;
    int y = m_year;
    static int t[] = { 0, 3, 2, 5, 0, 3, 5, 1, 4, 6, 2, 4 };  
    y -= m < 3;  
    int calculation_week_day_number = ( y + y / 4 - y / 100 + y / 400 + t[m - 1] + d) % 7; 
    return Weekday(calculation_week_day_number);
}


Date& Date::set_month_day(int day) //14
{
    m_day = day;
    return *this;
}


Date& Date::set_month(int month) //15
{
    m_month = month;
    return *this;
}
Date& Date::set_year(int year) //16
{
    m_year = year;
    return *this;
}


Date& Date::set(int day, int mon, int year) //17
{
    m_day = day;
    m_month = mon;
    m_year = year;
    return *this;
}

/// Subtract specified number of days from date
Date Date::operator - (int day) const { //18

    // Falls within the same month?
    if (0 < (m_day - day)) {
        return Date(m_day - day, m_month, m_year);
    }

    // Start from this year
    int nYear(m_year);

    // Start from specified days and go back to first day of this month
    int nDays(day);
    nDays -= m_day;

    // Start from previous month and check if it falls on to previous year
    int nMonth(m_month - 1);
    if (nMonth < 1) {
        nMonth = 12; // December
        --nYear;     // Previous year
    }

    // Maximum days in the current month
    int nDaysInMonth = MaxDayInMonth[nMonth] + (nMonth == 2 && isleap(nYear) ? 1 : 0);

    // Iterate till it becomes a valid day of a month
    while (nDays >= 0) {
        // Subtract the max number of days of current month
        nDays -= nDaysInMonth;

        // Falls on to previous month?
        if (nDays > 0) {
            // Go to previous month
            --nMonth;

            // Falls on to previous year?
            if (nMonth < 1) {
                nMonth = 12; // December
                --nYear;     // Previous year
            }
        }

        // Update the max days of the new month
        nDaysInMonth = MaxDayInMonth[nMonth] + (nMonth == 2 && isleap(nYear) ? 1 : 0);
    }
    return Date((0 < nDays ? nDays : -nDays),  nMonth, nYear);
}

// Add x days to the given date.
Date& Date::operator+=(int day)  //19
{
    /// Add specified number of days to date
    // Maximum days in the month
    int nMaxDays(MaxDayInMonth[m_month] + (m_month == 2 && isleap(m_year) ? 1 : 0));

    // Initialize the Year, Month, Days
    int nYear(m_year);
    int nMonth(m_month);
    int nDays(m_day + day);

    // Iterate till it becomes a valid day of a month
    while (nDays > nMaxDays) {
        // Subtract the max number of days of current month
        nDays -= nMaxDays;

        // Advance to next month
        ++nMonth;

        // Falls on to next year?
        if (nMonth > 12) {
            nMonth = 1; // January
            ++nYear;    // Next year
        }

        // Update the max days of the new month
        nMaxDays = MaxDayInMonth[nMonth] + (nMonth == 2 && isleap(nYear) ? 1 : 0);
    }
    m_year = nYear;
    m_month = nMonth;
    m_day = nDays;
    return *this;
}


Date& Date::operator-=(int day) //20
{
    // Falls within the same month?
    if (0 < (m_day - day)) {
        m_day = m_day - day;
        return *this;
    }

    // Start from this year
    int nYear(m_year);

    // Start from specified days and go back to first day of this month
    int nDays(day);
    nDays -= m_day;

    // Start from previous month and check if it falls on to previous year
    int nMonth(m_month - 1);
    if (nMonth < 1) {
        nMonth = 12; // December
        --nYear;     // Previous year
    }

    // Maximum days in the current month
    int nDaysInMonth = MaxDayInMonth[nMonth] + (nMonth == 2 && isleap(nYear) ? 1 : 0);

    // Iterate till it becomes a valid day of a month
    while (nDays >= 0) {
        // Subtract the max number of days of current month
        nDays -= nDaysInMonth;

        // Falls on to previous month?
        if (nDays > 0) {
            // Go to previous month
            --nMonth;

            // Falls on to previous year?
            if (nMonth < 1) {
                nMonth = 12; // December
                --nYear;     // Previous year
            }
        }

        // Update the max days of the new month
        nDaysInMonth = MaxDayInMonth[nMonth] + (nMonth == 2 && isleap(nYear) ? 1 : 0);
    }
    m_year = nYear;
    m_month = nMonth;
    m_day = abs(nDays);
    return *this;
}


Date& Date::operator++() //21
{
    *this += 1;
    return *this;
}


Date Date::operator++(int) //22
{
    Date cpy = *this;
    *this += 1;
    return cpy;
}

Date& Date::operator--() //23
{
    *this -= 1;
    return *this;
}


Date Date::operator--(int) //24
{
    Date cpy = *this;
    *this -= 1;
    return cpy;
}

Date Date::random_date() //25
{
    int how_many_years = 100;
    srand (time(NULL));
    int randomYear = 1950 + (rand()%how_many_years)+1;
    int randomMonth = (rand()%12)+1;
    int randomDays = 32;
    while(randomDays>=MaxDayInMonth[randomMonth]){
        randomDays = (rand()%31)+1;
    }
    return Date(randomDays, randomMonth, randomYear);
}


constexpr bool Date::isleap(int y) //26
{
    return y % 4 == 0 && (y % 100 != 0 || y % 400 == 0);
}

bool project::operator<(const Date &l, const Date &r) //27
{
    if(l.get_year()<r.get_year()){
        return true;
    }else{
        if(l.get_month()<r.get_month()){
            return true;
        }else{
            if(l.get_year_day()<r.get_year_day()){
                return true;
            }
            else{
                return false;
            }
        }
    }
}

bool project::operator>(const Date & l, const Date &r) //27
{
    if(l.get_year()>r.get_year()){
        return true;
    }else{
        if(l.get_month()>r.get_month()){
            return true;
        }else{
            if(l.get_year_day()>r.get_year_day()){
                return true;
            }
            else{
                return false;
            }
        }
    }
}

bool project::operator<=(const Date &l, const Date &r) //27
{
    return !(l>r);
}

bool project::operator>=(const Date &l, const Date &r) //27
{
    return !(l<r);
}
bool project::operator==(const Date &l, const Date &r) //27
{
    return ((l.get_year_day() == r.get_year_day()) || (l.get_month() == r.get_month()) || (l.get_year() == r.get_year()));
}
bool project::operator!=(const Date &l, const Date &r) //27
{
    return !(l==r);
}

int project::operator-(const Date &d1, const Date &d2) //28
{
    // COUNT TOTAL NUMBER OF DAYS
    // BEFORE FIRST DATE 'dt1'
 
    // initialize count using years and day
    long int n1 = d1.get_year() * 365 + d1.get_year_day();
    // Since every leap year is of 366 days,
    // Add a day for every leap year
    n1 += d1.countLeapYears();
 
    // SIMILARLY, COUNT TOTAL NUMBER OF
    // DAYS BEFORE 'dt2'
 
    long int n2 = d2.get_year() * 365 + d2.get_year_day();
    // Add days for months in given date
    n2 += d2.countLeapYears();
 
    // return difference between two counts
    return abs(n2 - n1);
}

Date project::operator+(const Date &date, int n) //29
{
    Date copy_date = date;
    copy_date += n;
    return copy_date;
}


Date project::operator+(int n, const Date &d) //29
{
    Date copy_date = d;
    copy_date += n;
    return copy_date;
}


std::ostream & project::operator<<(std::ostream &os, const Date &date)//31
{
    std::string ay[13] = { " ", "January", "February", "March",  "April", "May", "June", "July",  "August", "September", "October", "November", "December" };
    std::string gun = "";
    switch(date.get_week_day())
    {
        case Date::Weekday::Sunday  : gun = "Sunday\n";   break;
        case Date::Weekday::Monday : gun = "Monday\n"; break;
        case Date::Weekday::Tuesday : gun = "Tuesday\n";  break;
        case Date::Weekday::Wednesday  : gun = "Wednesday\n";   break;
        case Date::Weekday::Thursday : gun = "Thursday\n"; break;
        case Date::Weekday::Friday : gun = "Friday\n";  break;
        case Date::Weekday::Saturday : gun = "Saturday\n"; break;
    }
    return os << date.get_month_day() << ' ' << ay[date.get_month()] << ' ' << date.get_year() << ' ' << gun;
}

std::ostream & project::operator<<(std::ostream &os, const Date::Weekday &day)
{
    std::string gun = "";
    switch(day)
    {
        case Date::Weekday::Sunday  : gun = "Sunday\n";   break;
        case Date::Weekday::Monday : gun = "Monday\n"; break;
        case Date::Weekday::Tuesday : gun = "Tuesday\n";  break;
        case Date::Weekday::Wednesday  : gun = "Wednesday\n";   break;
        case Date::Weekday::Thursday : gun = "Thursday\n"; break;
        case Date::Weekday::Friday : gun = "Friday\n";  break;
        case Date::Weekday::Saturday : gun = "Saturday\n"; break;
    }
    return os << gun;
}



std::istream & project::operator>>(std::istream &is, Date &date) //32
{
    int a, b, c;
    is >> a >> b >> c;
    date.set_month_day(a);
    date.set_month(b);
    date.set_year(c);
    return  is;
}

Date::Weekday& project::operator++(Date::Weekday &r) //30
{
    switch(r)
    {
        case Date::Weekday::Monday    :    r = Date::Weekday::Tuesday; break;
        case Date::Weekday::Tuesday   :    r = Date::Weekday::Wednesday; break;
        case Date::Weekday::Wednesday :    r = Date::Weekday::Thursday; break;
        case Date::Weekday::Thursday  :    r = Date::Weekday::Friday; break;
        case Date::Weekday::Friday    :    r = Date::Weekday::Saturday; break;
        case Date::Weekday::Saturday  :    r = Date::Weekday::Sunday; break;
        case Date::Weekday::Sunday    :    r = Date::Weekday::Monday; break;
    }
    return r;
}

Date::Weekday project::operator++(Date::Weekday &r, int) //30
{
    Date::Weekday tmp = r;
    switch(r)
    {
        case Date::Weekday::Monday    :    r = Date::Weekday::Tuesday; break;
        case Date::Weekday::Tuesday   :    r = Date::Weekday::Wednesday; break;
        case Date::Weekday::Wednesday :    r = Date::Weekday::Thursday; break;
        case Date::Weekday::Thursday  :    r = Date::Weekday::Friday; break;
        case Date::Weekday::Friday    :    r = Date::Weekday::Saturday; break;
        case Date::Weekday::Saturday  :    r = Date::Weekday::Sunday; break;
        case Date::Weekday::Sunday    :    r = Date::Weekday::Monday; break;
    } 
    return tmp;
}

Date::Weekday& project::operator--(Date::Weekday &r) //30
{
    switch(r)
    {
        case Date::Weekday::Monday    :    r = Date::Weekday::Sunday; break;
        case Date::Weekday::Tuesday   :    r = Date::Weekday::Monday; break;
        case Date::Weekday::Wednesday :    r = Date::Weekday::Tuesday; break;
        case Date::Weekday::Thursday  :    r = Date::Weekday::Wednesday; break;
        case Date::Weekday::Friday    :    r = Date::Weekday::Thursday; break;
        case Date::Weekday::Saturday  :    r = Date::Weekday::Friday; break;
        case Date::Weekday::Sunday    :    r = Date::Weekday::Saturday; break;
    }
    return r;
}

Date::Weekday project::operator--(Date::Weekday &r, int) //30}
{
    Date::Weekday tmp = r;
    switch(r)
    {
        case Date::Weekday::Monday    :    r = Date::Weekday::Sunday; break;
        case Date::Weekday::Tuesday   :    r = Date::Weekday::Monday; break;
        case Date::Weekday::Wednesday :    r = Date::Weekday::Tuesday; break;
        case Date::Weekday::Thursday  :    r = Date::Weekday::Wednesday; break;
        case Date::Weekday::Friday    :    r = Date::Weekday::Thursday; break;
        case Date::Weekday::Saturday  :    r = Date::Weekday::Friday; break;
        case Date::Weekday::Sunday    :    r = Date::Weekday::Saturday; break;
    }
    return tmp;
}

// Additional Functions
std::vector<std::string> Date::split (std::string s, char delimiter) {
    size_t pos_start = 0, pos_end, delim_len = 1;
    std::string token;
    std::vector<std::string> res;

    while ((pos_end = s.find (delimiter, pos_start)) != std::string::npos) {
        token = s.substr (pos_start, pos_end - pos_start);
        pos_start = pos_end + delim_len;
        res.push_back (token);
    }
    res.push_back (s.substr (pos_start));
    return res;
}

int Date::countLeapYears() const
{
    int years = m_year;
 
    // Check if the current year needs to be
    //  considered for the count of leap years
    // or not
    if (m_month <= 2)
        years--;
 
    // An year is a leap year if it
    // is a multiple of 4,
    // multiple of 400 and not a
     // multiple of 100.
    return years / 4
           - years / 100
           + years / 400;
}    