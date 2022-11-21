#ifndef DATE_H
#define DATE_H
#include <iosfwd>
#include <ctime>
#include <vector>
#include <string>
#include <time.h>
#include <stdlib.h>

namespace project {
class Date {
private:
	int m_year;
	int m_month;
	int m_day;
	inline static const int MaxDayInMonth[13] = {0, 31, 28, 31, 30, 31, 30, 1, 31, 30, 31, 30, 31};
public:
	static constexpr int year_base = 1900;  //1
	static constexpr int random_min_year = 1940;  //2
	static constexpr int random_max_year = 2020;  //3
	enum class Weekday {Sunday, Monday, Tuesday, Wednesday, Thursday, Friday, Saturday}; //4
	Date(); //5 
	Date(int d, int m, int y);  //6
	Date(const char *p);  //7
	Date(std::time_t timer); //8
	int get_month_day()const; //9
	int get_month()const; //10
	int get_year()const; //11
	int get_year_day()const; //12
	Weekday get_week_day()const; //13

	Date& set_month_day(int day); //14
	Date& set_month(int month); //15
	Date& set_year(int year); //16
	Date& set(int day, int mon, int year); //17
	Date operator-(int day)const; //18
	Date& operator+=(int day); //19
	Date& operator-=(int day); //20
	Date& operator++(); //21
	Date operator++(int); //22
	Date& operator--(); //23
	Date operator--(int); //24
	
	friend bool operator<(const Date &, const Date &); //27
	friend bool operator==(const Date &, const Date &); //27
	static Date random_date(); //25
	static constexpr bool isleap(int y); //26
	
	friend std::ostream &operator<<(std::ostream &os, const Date &date); //31
	friend std::ostream &operator<<(std::ostream &os, const Date::Weekday &date);//32
	friend std::istream &operator>>(std::istream &is, Date &date); //33

	// Additional Functions
	std::vector<std::string> split (std::string s, char delimiter);
	int countLeapYears() const;
};

bool operator<(const Date &, const Date &); //27
bool operator<=(const Date &, const Date &); //27
bool operator>(const Date &, const Date &); //27
bool operator>=(const Date &, const Date &); //27
bool operator==(const Date &, const Date &); //27
bool operator!=(const Date &, const Date &); //27

int operator-(const Date &d1, const Date &d2); //28
Date operator+(const Date &date, int n); //29
Date operator+(int n, const Date &); //29
Date::Weekday& operator++(Date::Weekday &r); //30
Date::Weekday operator++(Date::Weekday &r, int); //30
Date::Weekday& operator--(Date::Weekday &r); //30
Date::Weekday operator--(Date::Weekday &r, int); //30}
std::ostream &operator<<(std::ostream &os, const Date &date);//31
std::ostream &operator<<(std::ostream &os, const Date::Weekday &date);//32
std::istream &operator>>(std::istream &is, Date &date); //33
}
#endif