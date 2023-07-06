/*/////////////////////////////////////////////////////////////////////////
                          Workshop - #4 (P5)
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
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include "Account.h"

using namespace std;
namespace sdds {
    // invalid account
    void Account::setEmpty() {
        m_number = -1;
        m_balance = 0.0;
    }
    // New account
    Account::Account() {
        m_number = 0;
        m_balance = 0.0;
    }
    
    Account::Account(int number, double balance) {
        setEmpty();
        if (number >= 10000 && number <= 99999
            && balance > 0) {
            m_number = number;
            m_balance = balance;
        }
    }
    std::ostream& Account::display() const {
        if (*this) {
            cout << " ";
            cout << m_number;
            cout << " | ";
            cout.width(12);
            cout.precision(2);
            cout.setf(ios::right);
            cout.setf(ios::fixed);
            cout << m_balance;
            cout.unsetf(ios::right);
            cout << " ";
        }
        else if (~*this) {
            cout << "  NEW  |         0.00 ";
        }
        else {
            cout << "  BAD  |    ACCOUNT   ";
        }
        return cout;
    }
    //true if the account is valid and otherwise false.
    Account:: operator bool() const {
        bool result = false;
        if (m_number >= 10000 && m_number <= 99999
            && m_balance >= 0) {
            result = true;
        }
        return result;
    }
    //
    Account::operator int() const {
        return m_number;
    }
    Account::operator double() const {
        return m_balance;
    }
    //returns true is the account is new or not set
    bool Account::operator~() const {
        bool result = false;
        if (m_number == 0 ) {
            result = true;
        }
        return result;
    }
    //overload the assignment operator
    Account& Account::operator=(int newNumber) {
        //If the integer value is an invalid account number
        if (m_number == 0) {
            m_number = newNumber;
           
        }
        else if((newNumber < 10000 || newNumber > 99999)) {
            setEmpty();

        }
       
        
        return *this;
    }
    // move between account 
    Account& Account::operator=( Account& other) {
        if (m_number==0 && other) {
            m_number = other.m_number;
            m_balance = other.m_balance;
            //after moving set to the new account
            other.m_number = 0;
            other.m_balance = 0.0;
        }
        return *this;
    }
    // add money to balance if valid account and valid balance
    Account& Account::operator+=(double newBalance) {
        if (newBalance >= 0 && *this) {
            // add the money to the current account
            m_balance += newBalance;
        }
        return *this;
    }
    // withdraw money from account if the account is valid and the balance is available
    Account& Account::operator-=(double newBalance) {
        if (*this && newBalance >= 0 && m_balance>=newBalance) {
            // minus a amount of money of the current account
            m_balance -= newBalance;
        }
        return *this;
    }
    // move money from right to left
    Account& Account::operator<<(Account& other) {
        if (this != &other) {
            if (*this && other) {
                m_balance += other.m_balance;
                other.m_balance = 0.0;
            }
        }
        return *this;
    }
    // move money from left to right
    Account& Account::operator>>(Account& other) {
        if (this != &other ) {
            if (*this && other) {
                other.m_balance += m_balance;
                m_balance = 0.0;
            }
        }
        return *this;
    }
   // return the sum of two account 
    double operator+(const Account& left, const Account& right) {
        double sum = 0.0;
        if (left && right) {
            // access the m_balance value from private
            sum = static_cast<double>(left) + static_cast<double>(right);
        }
        else {
            sum = 0.0;
        }
        return sum;
    }
    // return the double after adding the right balance 
    double operator+=(double& addValue, const Account& right) {
        return addValue += static_cast<double>(right);
        
    }

}