#include "iostream"
#include "Fraction.cpp"

int main(){

    Fraction f1(1,2);
    Fraction f2(2,4);
    Fraction f3(2.15);
    Fraction f4("3/5");

    std::cout<< "****************************************Test 1****************************************\n";
    std::cout << "f1 = " << f1 << '\n';
    std::cout << "f2 = " << f2 << '\n';
    std::cout << "f3 = " << f3 << '\n';
    std::cout << "f4 = " << f4 << '\n';
    std::cout<< "**************************************************************************************\n\n";

    std::cout<< "****************************************Test 2****************************************\n";
    f1+=f4;
    std::cout << "After f1+=f4 : f1 = " << f1 << '\n';
    f4-=f3;
    std::cout << "After f4-=f3 : f4 = " << f4 << '\n';
    f2*=f3;
    std::cout << "After f2*=f3 : f2 = " << f2 << '\n';
    f3/=f1;
    std::cout << "After f3/=f1 : f3 = " << f3 << '\n';
    std::cout<< "**************************************************************************************\n\n";

    std::cout<< "****************************************Test 3****************************************\n";
    std::cout << "Before operators: \n";
    std::cout << "f1 = " << f1 << '\n';
    std::cout << "f2 = " << f2 << '\n';
    std::cout << "f3 = " << f3 << '\n';
    std::cout << "f4 = " << f4 << '\n';
    std::cout<< "--------------------------------------------------------------------------------------\n";
    std::cout << "During operators: \n";
    std::cout << "f1.operator++() = " << ++f1 << '\n';
    std::cout << "f2.operator++(int) = " << f2++ << '\n';
    std::cout << "f3.operator--() = " << --f3 << '\n';
    std::cout << "f4.operator--(int) = " << f4-- << '\n';
    std::cout<< "--------------------------------------------------------------------------------------\n";
    std::cout << "After operators: \n";
    std::cout << "f1 = " << f1 << '\n';
    std::cout << "f2 = " << f2 << '\n';
    std::cout << "f3 = " << f3 << '\n';
    std::cout << "f4 = " << f4 << '\n';
    std::cout<< "**************************************************************************************\n\n";


    std::cout<< "****************************************Test 4****************************************\n";
    if(f1 and f1.Num()>0)
        std::cout << "f1 is less than 1.\n";
    else
        std::cout << "f1 is greater than or equal 1.\n";

    if(!f4 and f4.Num()<0)
        std::cout << "f4 is greater than 1.\n";
    else
        std::cout << "f4 is less than or equal 1.\n";
    std::cout << "f2.to_double : f2 = " << f2.to_double() << '\n';
    std::cout << "f3.to_string : f3 = " << f3.to_string() << '\n';
    std::cout << "Static Random : " << Fraction::Random() << '\n';
    std::cout<< "**************************************************************************************\n\n";

    std::cout<< "****************************************Test 5****************************************\n";
    std::cout << "Before operators: \n";
    std::cout << "f1 = " << f1 << '\n';
    std::cout << "f2 = " << f2 << '\n';
    std::cout << "f3 = " << f3 << '\n';
    std::cout << "f4 = " << f4 << '\n';
    std::cout<< "--------------------------------------------------------------------------------------\n";
    std::cout << "During operators: \n";
    std::cout << "f1 + f4 = " << f1 + f4 << '\n';
    std::cout << "f4 - f3 = " << f4 - f3 << '\n';
    std::cout << "f2 * f3 = " << f2 * f3 << '\n';
    std::cout << "f3 / f1 = " << f3 / f1 << '\n';
    std::cout<< "--------------------------------------------------------------------------------------\n";
    std::cout << "After operators: \n";
    std::cout << "f1 = " << f1 << '\n';
    std::cout << "f2 = " << f2 << '\n';
    std::cout << "f3 = " << f3 << '\n';
    std::cout << "f4 = " << f4 << '\n';
    std::cout<< "**************************************************************************************\n\n";


    std::cout<< "****************************************Test 6****************************************\n";
    std::cout << "f1 = " << f1 << '\n';
    std::cout << "f2 = " << f2 << '\n';
    std::cout << "f3 = " << f3 << '\n';
    std::cout << "f4 = " << f4 << '\n';
    std::cout << "\nf1 == f2 : " << (static_cast<int>(f1 == f2)) << '\n';
    std::cout << "f1 != f3 : " << (static_cast<int>(f1 != f2)) << '\n';
    std::cout << "f1 <  f4 : " << (static_cast<int>(f1 <  f4)) << '\n';
    std::cout << "f2 <= f3 : " << (static_cast<int>(f3 <= f3)) << '\n';
    std::cout << "f2 >  f4 : " << (static_cast<int>(f2 >  f4)) << '\n';
    std::cout << "f3 >= f4 : " << (static_cast<int>(f3 >= f4)) << '\n';
    std::cout<< "**************************************************************************************\n\n";

    std::cout<< "****************************************Test 7****************************************\n";
    Fraction f5;
    std::cout <<  "Enter f5 : ";
    std::cin >> f5;
    Fraction f6;
    f6 = "3.15"_f;
    std::cout << "cin>>f5 : " << f5 << '\n';
    std::cout << "f6 = \"3.15\"_f : " << f6 << '\n';
    std::cout<< "**************************************************************************************\n";
    
    return 0;
}