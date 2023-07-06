/*/////////////////////////////////////////////////////////////////////////
                          Workshop - #5 (P2)
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
#include "Mark.h"

using namespace std;
namespace sdds {
    //  constructor no argument
    Mark::Mark() {
        mark = 0;
        isvalid = true;
    }
    
    Mark::Mark(int number) {
        // Mark can be created using an integer value
        if (number >= 0 && number <= 100) {
            mark = number;
            isvalid = true;
        }
        // if invalid value will set to 0
        else {
            mark = 0;
            isvalid = false;
        }
    }
    //return integer type
    Mark::operator int() const {
        return mark;
    }

    //return true if the mark is valid
    Mark::operator bool()const {
        bool result=false;
        if (mark>=0 && mark<=100) {
            
            result = true;
           
        }
        return result;
    }
    //integer value will be added to the mark
    Mark& Mark::operator+=(int number) {
        // if the mark is valid action is omitted
        if (*this && isvalid) {
            mark += number;
            if (mark > 100) {
                mark = 0;
                isvalid = false;
            }

           
        }
        
        return *this;
    }
    // overload the assignment operator
    Mark& Mark::operator=(int number) {
       
        mark = number;
        isvalid = true;
        if (!*this) {
            mark = 0;
            isvalid = false;
        }
        
        return *this;
    }
    // cast double return the gpa
    Mark::operator double()const {
        if (!*this)  return 0.0;
        else if (mark >= 0 && mark < 50) {
            return 0.0;
        }
        else if (mark >= 50 && mark < 60) {
            return 1.0;
        }
        else if (mark >= 60 && mark < 70) {
            return 2.0;
        }
        else if (mark >= 70 && mark < 80) {
            return 3.0;
        }
        else if (mark >= 80 && mark <= 100) {
            return 4.0;
        }
        

    }
    // cast char return a character
    Mark::operator char()const {
        if (!*this||!isvalid)  return 'X';
        else if (mark >= 0 && mark < 50) {
            return 'F';
        }
        else if (mark >= 50 && mark < 60) {
            return 'D';
        }
        else if (mark >= 60 && mark < 70) {
            return 'C';
        }
        else if (mark >= 70 && mark < 80) {
            return 'B';
        }
        else if (mark >= 80 && mark <= 100) {
            return 'A';
        }
       
    }
    // add the mark to the number and return integer value
    int operator+=(int& number, const Mark& m_mark){
        if (m_mark)
        {
            return number += static_cast<int>(m_mark); 
        }
        return number;
    }
}

