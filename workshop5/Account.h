/*/////////////////////////////////////////////////////////////////////////
                          Workshop - #5 (P1)
Full Name  : Long Duc Hoang
Student ID#: 122702228
Email      : dhoang19@myseneca.ca
Section    : ZAA
Date	   : 6/1/2023
Authenticity Declaration:
I declare this submission is the result of my own work and has not been
shared with any other student or 3rd party content provider. This submitted
piece of work is entirely of my own creation.
/////////////////////////////////////////////////////////////////////////*/
#ifndef SDDS_ACCOUNT_H_
#define SDDS_ACCOUNT_H_
#include <iostream>

namespace sdds {
    class Account {
        int m_number;
        double m_balance;
        void setEmpty();
    public:
        Account();
        Account(int number, double balance);
        std::ostream& display()const;
        operator bool() const;
        operator int() const;
        operator double() const;
        bool operator~() const;
        Account& operator=(int newNumber);
        Account& operator=( Account& other);
        Account& operator+=(double newBalance);
        Account& operator-=(double newBalance);
        Account& operator<<(Account& other);
        Account& operator>>(Account& other);
    };

    double operator+(const Account& left, const Account& right);
    double operator+=(double& addValue, const Account& right);
}
#endif // SDDS_ACCOUNT_H_