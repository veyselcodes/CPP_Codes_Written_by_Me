#include <string>
#include <iosfwd>

class Fraction {
private:
    int numerator, denominator;
public:
	explicit Fraction(int num = 0, int denum = 1); //1
	explicit Fraction(double dval); // 2
	explicit Fraction(const std::string &s);  //3
	
	Fraction& operator+=(const Fraction& f); //4
	Fraction& operator-=(const Fraction& f); //5
	Fraction& operator*=(const Fraction& f); //6
	Fraction& operator/=(const Fraction& f); //7
	
	Fraction& operator++(); //8
	Fraction operator++(int); //9
	Fraction& operator--(); //10
	Fraction operator--(int);  //11
	
	constexpr int Num()const;  //12
	constexpr int Denom()const; //13
	explicit operator bool()const;  //14
	bool operator !()const;  //14
	double to_double()const; //15
	std::string to_string()const; //16
	
	static Fraction Random();  //17

    // Additional Functioons
    static int gcd(int n, int d);
};

Fraction operator+(const Fraction&, const Fraction &); //18
Fraction operator-(const Fraction&, const Fraction &);  //19
Fraction operator*(const Fraction&, const Fraction &); //20
Fraction operator/(const Fraction&, const Fraction &);  //21

bool operator==(const Fraction& f1, const Fraction& f2); //22
bool operator!=(const Fraction& f1, const Fraction& f2); //23
bool operator<(const Fraction& f1, const Fraction& f2);   //24
bool operator<=(const Fraction& f1, const Fraction& f2);   //25
bool operator>(const Fraction& f1, const Fraction& f2);  //26
bool operator>=(const Fraction& f1, const Fraction& f2);  //27

std::ostream &operator<<(std::ostream&, const Fraction &); //28
std::istream &operator>>(std::istream&, Fraction &);  //29
Fraction operator""_f(const char* str, size_t n); //30