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
#ifndef SDDS_MARK_H_
#define SDDS_MARK_H_
#include <iostream>

namespace sdds {
    class Mark {
        int mark;
        bool isvalid; 
    public:
        Mark();
        Mark(int number);
        operator bool() const;
        operator int() const;
        operator double() const;
        operator char() const;
        Mark& operator=(int number);
        Mark& operator+=(int number);

    };
    int operator+=(int& number, const Mark& m_mark);
}





#endif // SDDS_MARK_H_