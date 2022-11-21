#include <iostream>
#include "Date.cpp"


int main(){

    Date date1;
    Date date2(1,3,2021);
    Date date3("08/08/1998");
    Date date4(time(0));
    std::cout << "******************************** Test " << 1 << " ********************************\n";
    std::cout << "date1 : " << date1;
    std::cout << "date2 : " << date2;
    std::cout << "date3 : " << date3;
    std::cout << "date4 : " << date4;
    std::cout << "************************************************************************\n\n";

    std::cout << "******************************** Test " << 2 << " ********************************\n";
    std::cout << "Days from 1 January " << date4.get_year() << " to today : " << date4.get_year_day() << '\n';
    std::cout << "Days from 1 January " << date1.get_year() << " to date1 : " << date1.get_year_day() << '\n';
    std::cout << "************************************************************************\n\n";



    std::cout << "******************************** Test " << 3 << " ********************************\n";
    date1.set(1,1,2020);
    std::cout << "After set functionset(1,1,2020) : " << date1;
    std::cout << "************************************************************************\n\n";

    std::cout << "******************************** Test " << 4 << " ********************************\n";
    std::cout << "date2 : " << date2;
    Date date5 = date2 - 23;
    std::cout << "date2 - 23 (date5) = " << date5;
    date5 += 23;
    std::cout << "date5 += 23  date5 = " << date5;
    date5 -= 23;
    std::cout << "date5 -= 23  date5 = " << date5;
    std::cout << "************************************************************************\n\n";
    
    std::cout << "******************************** Test " << 5 << " ********************************\n";
    std::cout << "date5 = date5++  date5 = " << date5++;
    std::cout << "date5 = ++date5 date5 = " << ++date5;
    std::cout << "date5 = date5--  date5 = " << date5--;
    std::cout << "date5 = --date5 date5 = " << --date5;
    std::cout << "************************************************************************\n\n";

    std::cout << "******************************** Test " << 6 << " ********************************\n";
    std::cout << "Random Date : " << date5.random_date();
    std::cout << "************************************************************************\n\n";
    
    std::cout << "******************************** Test " << 7 << " ********************************\n";
    std::cout<<"\t\t\t\tComparison\t\t\t\t\n";
    std::cout << "date1 : " << date1;
    std::cout << "date2 : " << date2;
    std::cout << "date3 : " << date3;
    std::cout << "date4 : " << date4;
    std::cout << "date5 : " << date5;
    std::cout << '\n';

    bool c1 = date1 > date2;
    std::cout << "date1 > date2 : " << (c1 ? "True" : "False") << '\n'; 
    bool c2 = date1 >= date2;
    std::cout << "date1 >= date2 : " << (c2 ? "True" : "False") << '\n'; 
    bool c3 = date1 < date3;
    std::cout << "date1 < date3 : " << (c3 ? "True" : "False") << '\n'; 
    bool c4 = date1 <= date3;
    std::cout << "date1 <= date3 : " << (c4 ? "True" : "False") << '\n'; 
    bool c5 = date1 == date4;
    std::cout << "date1 == date3 : " << (c5 ? "True" : "False") << '\n'; 
    bool c6 = date1 != date4;
    std::cout << "date1 != date3 : " << (c6 ? "True" : "False") << '\n'; 
    std::cout << "************************************************************************\n\n";

    std::cout << "******************************** Test " << 8 << " ********************************\n";
    std::cout << "Date2 : " << date2;
    std::cout << "Date5 : " << date5;
    std::cout << "Day between date2 and date5 : " << date5-date2 << '\n';
    date5 = date5+23;
    std::cout << "date5 + 23 = " << date5;
    std::cout << "Day between date2 and date5 : " << date5-date2 << '\n';
    date2 = 21 + date2;
    std::cout << "21 + date2 = " << date2;
    std::cout << "************************************************************************\n\n";

    std::cout << "******************************** Test " << 9 << " ********************************\n";
    Date date6;
    std::cout << "Enter date6(day,month,year): ";
    std::cin >> date6;
    std::cout << "date6 : " << date6;
    std::cout << "************************************************************************\n\n";

    std::cout << "******************************** Test " << 10 << " *******************************\n";
    Date::Weekday today = Date::Weekday::Friday;
    std::cout << "today : " << today;
    std::cout << "today++ : " << today++;
    std::cout << "++today : " << ++today;
    std::cout << "--today : " << --today;
    std::cout << "today-- : " << today--;
    std::cout << "************************************************************************\n\n";
    
    return 0;
}