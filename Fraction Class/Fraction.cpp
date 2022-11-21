#include "Fraction.h"
#include <iostream>
#include <math.h>  
#include <string>
#include<vector>
#include <cstdlib> 
#include <ctime> 

Fraction::Fraction(int num, int denum) : numerator(num), denominator(denum) //1
{
    if(denominator<0){
        numerator *=-1;
        denominator *=-1;
    }
}

Fraction::Fraction(double dval) // 2
{
    int num = 1, den = 1;
    double frac = (static_cast<double>(num) / den);
    double margin = 0.000001;
    while (abs(frac - dval) > margin){
        if (frac > dval){
            den++;
        }
        else{
            num++;
        }
        frac = (static_cast<double>(num) / den);
    }
    numerator = num;
    denominator = den;
}

Fraction::Fraction(const std::string &s)  //3
{
    std::string delimiter = "/";
    auto start = 0U;
    auto end = s.find(delimiter);
    bool delim_check = false;
    while (end != std::string::npos)
    {
        numerator = stoi(s.substr(start, end - start));
        start = end + delimiter.length();
        end = s.find(delimiter, start);
        delim_check = true;
    }
    if(delim_check)
        denominator = stoi(s.substr(start, end));
    else{
        numerator = stoi(s.substr(start, end));
        denominator = 1;
    }
    int n = numerator;
    int d = denominator;
    numerator = n/gcd(n,d);
    denominator = d/gcd(n,d);
    if(denominator<0 && numerator > 0){
        denominator *=-1;
        numerator *=-1;
    }
}

Fraction& Fraction::operator+=(const Fraction& f) //4
{
    int n = numerator*f.denominator+f.numerator*denominator;
    int d = denominator*f.denominator;
    numerator = n/gcd(n,d);
    denominator = d/gcd(n,d);
    return *this;
}
Fraction& Fraction::operator-=(const Fraction& f) //5
{
    int n = numerator*f.denominator-f.numerator*denominator;
    int d = denominator*f.denominator;
    numerator = n/gcd(n,d);
    denominator = d/gcd(n,d);
    return *this;
}
Fraction& Fraction::operator*=(const Fraction& f) //6
{
    int n = numerator*f.numerator;
    int d = denominator*f.denominator;
    numerator = n/gcd(n,d);
    denominator = d/gcd(n,d);
    return *this;
}
Fraction& Fraction::operator/=(const Fraction& f) //7
{
    int n = numerator*f.denominator;
    int d = denominator*f.numerator;
    numerator = n/gcd(n,d);
    denominator = d/gcd(n,d);
    return *this;
}

Fraction& Fraction::operator++() //8
{
    numerator += denominator;
    return *this;
}
Fraction Fraction::operator++(int) //9
{
    Fraction tmp = *this;
    numerator += denominator;
    return tmp;
}
Fraction& Fraction::operator--() //10
{
    numerator -= denominator;
    return *this;
}
Fraction Fraction::operator--(int)  //11
{
    Fraction tmp = *this;
    numerator -= denominator;
    return tmp;
}

constexpr int Fraction::Num()const  //12
{
    return numerator;
}
constexpr int Fraction::Denom()const //13
{
    return denominator;
}

Fraction::operator bool()const  //14
{
    if(denominator>numerator)
        return true;
    else
        return false;
}

bool Fraction::operator !()const  //14
{
    return !(operator bool());
}
double Fraction::to_double()const //15
{
    return static_cast<double>(numerator)/denominator;
}

std::string Fraction::to_string()const //16
{
    return std::to_string(numerator) + "/" + std::to_string(denominator);
}

Fraction Fraction::Random()  //17
{
    srand((unsigned)time(0)); 
    int n = (std::rand()%1000) + 1; 
    int d = (std::rand()%1000) + 1; 
    int numerator = n/gcd(n,d);
    int denominator = d/gcd(n,d);
    return Fraction(numerator,denominator);
}


Fraction operator+(const Fraction& f1, const Fraction &f2) //18
{
    int n = f1.Num()*f2.Denom()+f2.Num()*f1.Denom();
    int d = f1.Denom()*f2.Denom();
    int numerator = n/Fraction::gcd(n,d);
    int denominator = d/Fraction::gcd(n,d);
    return Fraction(numerator,denominator);
}
Fraction operator-(const Fraction& f1, const Fraction &f2)  //19
{
    int n = f1.Num()*f2.Denom()-f2.Num()*f1.Denom();
    int d = f1.Denom()*f2.Denom();
    int numerator = n/Fraction::gcd(n,d);
    int denominator = d/Fraction::gcd(n,d);
    return Fraction(numerator,denominator);
}
Fraction operator*(const Fraction& f1, const Fraction &f2) //20
{
    int n = f1.Num()*f2.Num();
    int d = f1.Denom()*f2.Denom();
    int numerator = n/Fraction::gcd(n,d);
    int denominator = d/Fraction::gcd(n,d);
    return Fraction(numerator,denominator);
}
Fraction operator/(const Fraction& f1, const Fraction &f2)  //21
{
    int n = f1.Num()*f2.Num();
    int d = f1.Denom()*f2.Denom();
    int numerator = n/Fraction::gcd(n,d);
    int denominator = d/Fraction::gcd(n,d);
    return Fraction(numerator,denominator);
}

bool operator==(const Fraction& f1, const Fraction& f2) //22
{
    return f1.Denom() == f2.Denom() && f1.Num() == f2.Num();
}
bool operator!=(const Fraction& f1, const Fraction& f2) //23
{
    return !(f1 == f2);
}
bool operator<(const Fraction& f1, const Fraction& f2)  //24
{
    return f1.to_double() < f2.to_double();
}
bool operator<=(const Fraction& f1, const Fraction& f2) //25
{
    return f1.to_double() <= f2.to_double();
}
bool operator>(const Fraction& f1, const Fraction& f2)  //26
{
    return f1.to_double() > f2.to_double();
}
bool operator>=(const Fraction& f1, const Fraction& f2) //27
{
    return f1.to_double() >= f2.to_double();
}

std::ostream &operator<<(std::ostream& os, const Fraction &f) //28
{
    return os << f.Num() << "/" << f.Denom();
}

std::istream &operator>>(std::istream& is, Fraction &f)  //29
{
    std::string entered ="";
    is >> entered;
    Fraction tmp(entered);
    f = tmp;
    return is;
}

Fraction operator""_f(const char* str, size_t n) //30
{
	return Fraction(atof(str));
}

// Additional Functioons
int Fraction::gcd(int n, int d)
{
    int remainder;
    while (d != 0)
    {
        remainder = n % d;
        n = d;
        d = remainder;
    }
    return n;
}